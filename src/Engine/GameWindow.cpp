//
// Created by ollie on 11/09/2022.
//

#include "GameWindow.h"
#include <iostream>

namespace Engine {
    GameWindow::GameWindow(GLFWwindow* window)
    {
        _window = window;
    }

    GameWindow* GameWindow::CreateWindow(const WindowSettings &settings) {
        if (!glfwInit())
        {
            std::cout << "GLFW could not initialize." << std::endl;
            throw std::exception();
        }

        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        GLFWwindow* window = glfwCreateWindow(settings.Size.x, settings.Size.y, settings.Title, nullptr, nullptr);
        if (!window)
        {
            glfwTerminate();
            std::cout << "The window was not created." << std::endl;
            throw std::exception();
        }

        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
        int x, y;
        glfwGetMonitorPos(monitor, &x, &y);

        glfwSetWindowPos(window, x + mode->width / 2 - settings.Size.x / 2, y + mode->height / 2 - settings.Size.y / 2);

        glfwMakeContextCurrent(window);
        gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

        glfwShowWindow(window);

        return new GameWindow(window);
    }

    GameWindow::~GameWindow() {
        std::cout << "GameWindow destructor called." << std::endl;
        glfwTerminate();
    }

    bool GameWindow::ShouldClose() {
        return glfwWindowShouldClose(_window);
    }

    void GameWindow::Present(int interval) {
        glfwSwapInterval(interval);
        glfwSwapBuffers(_window);
    }

    void GameWindow::ProcessEvents() {
        glfwPollEvents();
    }

    glm::ivec2 GameWindow::Size() {
        int w, h;
        glfwGetWindowSize(_window, &w, &h);
        return glm::ivec2(w, h);
    }

    void GameWindow::SetSize(glm::ivec2 size) {
        glfwSetWindowSize(_window, size.x, size.y);
    }
} // Engine