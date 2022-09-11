//
// Created by ollie on 11/09/2022.
//

#ifndef GAME_TEXTURE2D_H
#define GAME_TEXTURE2D_H

#include <glad/glad.h>
#include <glm/glm.hpp>

namespace Engine {

    class Texture2D {
    private:
        GLuint _handle;
        glm::ivec2 _size;

    public:
        Texture2D(const char* path);
        ~Texture2D();

        glm::ivec2 Size();

        void _Bind(int unit = 0);
    };

} // Engine

#endif //GAME_TEXTURE2D_H
