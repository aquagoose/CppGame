//
// Created by ollie on 11/09/2022.
//

#include "Time.h"
#include <glfw/glfw3.h>

namespace Engine {
     float Time::_lastTime = 0;
     float Time::_deltaTime = 0;

    void Time::_Initialize() {
        _lastTime = (float) glfwGetTime();
    }

    void Time::_Update() {
        float time = (float) glfwGetTime();
        _deltaTime = time - _lastTime;
        _lastTime = time;
    }

    float Time::DeltaTime() {
        return _deltaTime;
    }

} // Engine