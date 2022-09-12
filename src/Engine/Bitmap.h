//
// Created by ollie on 12/09/22.
//

#ifndef GAME_BITMAP_H
#define GAME_BITMAP_H

#include <glm/glm.hpp>

namespace Engine
{

    class Bitmap
    {
    private:
        uint8_t* _data;
        glm::ivec2 _size;

    public:
        Bitmap(const char* path);
        ~Bitmap();

        uint8_t* Data();
        glm::ivec2 Size();
    };

} // Engine

#endif //GAME_BITMAP_H
