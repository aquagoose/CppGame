//
// Created by ollie on 12/09/22.
//

#include "Input.h"

namespace Engine
{
    std::unordered_set<Keys> Input::_keysDown;
    std::unordered_set<Keys> Input::_newKeys;
    glm::vec2 Input::_mousePos;

    void Input::_Initialize(GLFWwindow* window)
    {
        glfwSetKeyCallback(window, KeyCallback);
    }

    void Input::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (action == GLFW_PRESS)
        {
            _keysDown.insert((Keys) key);
            _newKeys.insert((Keys) key);
        }
        else if (action == GLFW_RELEASE)
        {
            _keysDown.erase((Keys) key);
            _newKeys.erase((Keys) key);
        }
    }

    void Input::_Update(GLFWwindow *window)
    {
        _newKeys.clear();
        glfwPollEvents();
        double mX, mY;
        glfwGetCursorPos(window, &mX, &mY);
        _mousePos = glm::vec2(mX, mY);
    }

    bool Input::KeyDown(Keys key)
    {
        return _keysDown.count(key) > 0;
    }

    bool Input::KeyPressed(Engine::Keys key)
    {
        return _newKeys.count(key) > 0;
    }

    glm::vec2 Input::MousePosition()
    {
        return _mousePos;
    }
} // Engine