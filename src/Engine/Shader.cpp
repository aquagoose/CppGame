//
// Created by ollie on 11/09/2022.
//

#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace Engine {
    Shader::Shader(const char *vertex, const char *fragment) {
        std::ifstream vtx = std::ifstream(vertex);
        std::stringstream vStream;
        vStream << vtx.rdbuf();
        vtx.close();
        const std::string vStr = vStream.str();

        std::ifstream frg = std::ifstream(fragment);
        std::stringstream fStream;
        fStream << frg.rdbuf();
        frg.close();
        const std::string fStr = fStream.str();

        GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
        GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

        const GLchar* v = vStr.c_str();
        const GLchar* f = fStr.c_str();

        glShaderSource(vShader, 1, &v, nullptr);
        glShaderSource(fShader, 1, &f, nullptr);

        int success;

        glCompileShader(vShader);
        glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            GLchar log[512];
            glGetShaderInfoLog(vShader, 512, nullptr, log);
            std::cout << "Failed to compile vertex shader: " << log << std::endl;
            throw std::exception();
        }

        glCompileShader(fShader);
        glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            GLchar log[512];
            glGetShaderInfoLog(fShader, 512, nullptr, log);
            std::cout << "Failed to compile fragment shader: " << log << std::endl;
            throw std::exception();
        }

        _program = glCreateProgram();
        glAttachShader(_program, vShader);
        glAttachShader(_program, fShader);
        glLinkProgram(_program);
        glGetProgramiv(_program, GL_LINK_STATUS, &success);
        if (!success) {
            GLchar log[512];
            glGetProgramInfoLog(_program, 512, nullptr, log);
            std::cout << "Failed to link program: " << log << std::endl;
            throw std::exception();
        }
        glDetachShader(_program, vShader);
        glDetachShader(_program, fShader);
        glDeleteShader(vShader);
        glDeleteShader(fShader);
    }

    Shader::~Shader() {
        std::cout << "Shader destructor called." << std::endl;
        glDeleteProgram(_program);
    }

    void Shader::Set(const char* uniform, glm::mat4 matrix) {
        GLint loc = GetLocation(uniform);
        glUniformMatrix4fv(loc, 1, GL_FALSE, &matrix[0][0]);
    }

    GLint Shader::GetLocation(const char* name) const {
        GLint loc = glGetUniformLocation(_program, name);
        if (loc < 0)
        {
            std::cout << "Uniform \"" << name << "\" does not exist in the shader." << std::endl;
            throw std::exception();
        }

        return loc;
    }

    void Shader::Use() const {
        glUseProgram(_program);
    }
} // Engine