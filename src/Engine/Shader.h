//
// Created by ollie on 11/09/2022.
//

#ifndef GAME_SHADER_H
#define GAME_SHADER_H

#include <glm/glm.hpp>
#include <glad/glad.h>

namespace Engine {

    class Shader {
    private:
        GLuint _program;
        GLint GetLocation(const char *name) const;

    public:
        Shader(const char* vertex, const char* fragment);
        ~Shader();

        void Use() const;

        void Set(const char* uniform, glm::mat4 matrix);
    };

} // Engine

#endif //GAME_SHADER_H
