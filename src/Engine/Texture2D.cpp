//
// Created by ollie on 11/09/2022.
//

#include "Texture2D.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>

namespace Engine {
    Texture2D::Texture2D(const char *path) {
        int width, height, channels;
        unsigned char* data = stbi_load(path, &width, &height, &channels, 4);

        glGenTextures(1, &_handle);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, _handle);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glBindTexture(GL_TEXTURE_2D, 0);

        delete data;

        _size = glm::ivec2(width, height);
    }

    Texture2D::~Texture2D() {
        std::cout << "Texture2D destructor called." << std::endl;
        glDeleteTextures(1, &_handle);
    }

    glm::ivec2 Texture2D::Size() {
        return _size;
    }

    void Texture2D::_Bind(int unit) {
        glActiveTexture(GL_TEXTURE0 + unit);
        glBindTexture(GL_TEXTURE_2D, _handle);
    }
} // Engine