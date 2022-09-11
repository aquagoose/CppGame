//
// Created by ollie on 11/09/2022.
//

#ifndef GAME_SPRITERENDERER_H
#define GAME_SPRITERENDERER_H

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <vector>
#include "Shader.h"
#include "Texture2D.h"
#include "Graphics.h"

namespace Engine {

    struct SpriteVertex {
        glm::vec2 Position;
        glm::vec2 TexCoords;

        SpriteVertex() {
            Position = glm::vec2(0.0);
            TexCoords = glm::vec2(0.0);
        }

        SpriteVertex(glm::vec2 position, glm::vec2 texCoords) {
            Position = position;
            TexCoords = texCoords;
        }
    };

    struct Sprite {
        Texture2D* Texture;
        glm::vec2 Position;
    };

    class SpriteRenderer {
    public:
        static const int MaxSprites = 512;

    private:
        GLuint _vao, _vbo, _ebo;
        Shader* _shader;
        std::vector<Sprite> _spriteCache;

        int _spriteCount;
        int _deferredSpriteCount;

        SpriteVertex _verticesCache[4];
        uint32_t _indicesCache[6];

        SpriteVertex _vertices[MaxSprites * 4];
        uint32_t _indices[MaxSprites * 6];

        Texture2D* _currentTexture;

        Graphics* _graphics;

        void DrawSprite(Sprite& sprite);
        void Flush();

    public:
        SpriteRenderer(Graphics* graphics);
        ~SpriteRenderer();

        void Begin(glm::mat4 transform = glm::mat4(1.0));
        void End();
        void Draw(Texture2D* texture, glm::vec2 position);
    };

} // Engine

#endif //GAME_SPRITERENDERER_H
