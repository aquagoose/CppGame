//
// Created by ollie on 11/09/2022.
//

#include "Texture2D.h"
#include "Bitmap.h"
#include <iostream>

namespace Engine {
    Texture2D::Texture2D(const char *path) {
        Bitmap bitmap = Bitmap(path);

        glGenTextures(1, &_handle);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, _handle);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bitmap.Size().x, bitmap.Size().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap.Data());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glGenerateMipmap(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 0);

        _size = bitmap.Size();
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