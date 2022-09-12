//
// Created by ollie on 12/09/22.
//

#include "Bitmap.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>

namespace Engine
{
    Bitmap::Bitmap(const char *path)
    {
        int w, h, c;
        unsigned char* data = stbi_load(path, &w, &h, &c, 4);

        _data = data;
        _size = glm::ivec2(w, h);
    }

    uint8_t *Bitmap::Data()
    {
        return _data;
    }

    glm::ivec2 Bitmap::Size()
    {
        return _size;
    }

    Bitmap::~Bitmap()
    {
        std::cout << "Bitmap destructor called." << std::endl;
        stbi_image_free(_data);
    }
} // Engine