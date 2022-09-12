//
// Created by ollie on 12/09/22.
//

#include "Input.h"

namespace Engine
{
    std::unordered_set<Keys> _keysDown;
    std::unordered_set<Keys> _newKeys;

    void Input::_Initialize(GLFWwindow* window)
    {
        glfwSetKeyCallback(window, KeyCallback);
    }

    void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (action == GLFW_PRESS)
        {
            Engine::_keysDown.insert((Keys) key);
            Engine::_newKeys.insert((Keys) key);
        }
        else if (action == GLFW_RELEASE)
        {
            Engine::_keysDown.erase((Keys) key);
            Engine::_newKeys.erase((Keys) key);
        }
    }

    void Input::_Update(GLFWwindow *window)
    {
        Engine::_newKeys.clear();
        glfwPollEvents();
    }

    bool Input::KeyDown(Keys key)
    {
        return Engine::_keysDown.count(key) > 0;
    }

    bool Input::KeyPressed(Engine::Keys key)
    {
        return Engine::_newKeys.count(key) > 0;
    }
} // Engine