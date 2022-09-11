//
// Created by ollie on 11/09/2022.
//

#ifndef GAME_GAMEWINDOW_H
#define GAME_GAMEWINDOW_H

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <glfw/glfw3.h>

namespace Engine {

    struct WindowSettings {
        glm::ivec2 Size;
        const char* Title;
    };

    class GameWindow {
    private:
        GLFWwindow* _window;

        explicit GameWindow(GLFWwindow* window);

    public:
        static GameWindow* CreateWindow(const WindowSettings& settings);
        ~GameWindow();

        void ProcessEvents();
        bool ShouldClose();
        void Present(int interval);

        glm::ivec2 Size();
        void SetSize(glm::ivec2 size);
    };

} // Engine

#endif //GAME_GAMEWINDOW_H
