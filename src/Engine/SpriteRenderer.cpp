//
// Created by ollie on 11/09/2022.
//

#include "SpriteRenderer.h"
#include <glad/glad.h>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

namespace Engine {
    SpriteRenderer::SpriteRenderer(Graphics* graphics) {
        _graphics = graphics;

        glGenVertexArrays(1, &_vao);
        glBindVertexArray(_vao);

        glGenBuffers(1, &_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, _vbo);
        glBufferData(GL_ARRAY_BUFFER, MaxSprites * sizeof(SpriteVertex) * 4, nullptr, GL_DYNAMIC_DRAW);

        glGenBuffers(1, &_ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, MaxSprites * sizeof(uint32_t) * 6, nullptr, GL_DYNAMIC_DRAW);

        _shader = new Shader("Content/Shaders/Sprite.vert", "Content/Shaders/Sprite.frag");
        _shader->Use();

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(SpriteVertex), (void*) offsetof(SpriteVertex, Position));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(SpriteVertex), (void*) offsetof(SpriteVertex, TexCoords));
        glEnableVertexAttribArray(2);
        glVertexAttribIPointer(2, 1, GL_INT, sizeof(SpriteVertex), (void*) offsetof(SpriteVertex, MipLevel));

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    SpriteRenderer::~SpriteRenderer() {
        std::cout << "SpriteRenderer destructor called." << std::endl;
        glDeleteBuffers(1, &_vbo);
        glDeleteBuffers(1, &_ebo);
        glDeleteVertexArrays(1, &_vao);
    }

    void SpriteRenderer::Begin(glm::mat4 transform) {
        _shader->Use();
        glm::mat4 projection = glm::ortho(0.0f, (float) _graphics->Viewport().z, (float) _graphics->Viewport().w, 0.0f, -1.0f, 1.0f);
        _shader->Set("uCamera", projection * transform);
    }

    void SpriteRenderer::End() {
        for (int i = 0; i < _spriteCount; i++)
            DrawSprite(_spriteCache[i]);

        _spriteCount = 0;

        Flush();

        _spriteCache.clear();
    }

    void SpriteRenderer::Flush() {
        if (_deferredSpriteCount == 0)
            return;

        _shader->Use();
        _currentTexture->_Bind();
        glBindVertexArray(_vao);
        glBindBuffer(GL_ARRAY_BUFFER, _vbo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
        //glBufferSubData(GL_ARRAY_BUFFER, 0, MaxSprites * sizeof(SpriteVertex) * 4, _vertices);
        //glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, MaxSprites * sizeof(uint32_t) * 6, _vertices);

        glDrawElements(GL_TRIANGLES, _deferredSpriteCount * 6, GL_UNSIGNED_INT, nullptr);

        _deferredSpriteCount = 0;
    }

    void SpriteRenderer::Draw(Texture2D* texture, glm::vec2 position, float mipLevel) {
        _spriteCache.push_back(Sprite {
            .Texture = texture,
            .Position = position,
            .MipLevel = mipLevel
        });
        _spriteCount++;
    }

    void SpriteRenderer::DrawSprite(Sprite &sprite) {
        if (sprite.Texture != _currentTexture || _deferredSpriteCount >= MaxSprites)
            Flush();
        _currentTexture = sprite.Texture;

        int width = sprite.Texture->Size().x;
        int height = sprite.Texture->Size().y;

        float posX = sprite.Position.x;
        float posY = sprite.Position.y;

        int mipLevel = sprite.MipLevel;

        _verticesCache[0] = SpriteVertex(glm::vec2(posX + width, posY + height), glm::vec2(1, 1), mipLevel);
        _verticesCache[1] = SpriteVertex(glm::vec2(posX + width, posY), glm::vec2(1, 0), mipLevel);
        _verticesCache[2] = SpriteVertex(glm::vec2(posX, posY), glm::vec2(0, 0), mipLevel);
        _verticesCache[3] = SpriteVertex(glm::vec2(posX, posY + height), glm::vec2(0, 1), mipLevel);

        uint32_t dc = _deferredSpriteCount * 4;
        _indicesCache[0] = 0 + dc;
        _indicesCache[1] = 1 + dc;
        _indicesCache[2] = 3 + dc;
        _indicesCache[3] = 1 + dc;
        _indicesCache[4] = 2 + dc;
        _indicesCache[5] = 3 + dc;

        //memcpy(&_vertices + (_deferredSpriteCount * sizeof(SpriteVertex) * 4), &_verticesCache, sizeof(_verticesCache));
        //memcpy(_indices + (_deferredSpriteCount * sizeof(uint32_t) * 6), _indicesCache, 6 * sizeof(uint32_t));

        //std::copy(_verticesCache, _verticesCache + 4, _vertices + (_deferredSpriteCount * 4));
        //std::copy(_indicesCache, _indicesCache + 6, _indices + (_deferredSpriteCount * 4));

        glBindVertexArray(_vao);
        glBindBuffer(GL_ARRAY_BUFFER, _vbo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
        glBufferSubData(GL_ARRAY_BUFFER, _deferredSpriteCount * sizeof(SpriteVertex) * 4, 4 * sizeof(SpriteVertex), _verticesCache);
        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, _deferredSpriteCount * sizeof(uint32_t) * 6, 6 * sizeof(uint32_t), _indicesCache);

        _deferredSpriteCount++;
    }
} // Engine