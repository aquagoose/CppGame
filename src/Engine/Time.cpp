//
// Created by ollie on 11/09/2022.
//

#include "Time.h"
#include <GLFW/glfw3.h>

namespace Engine {
     float Time::_deltaTime = 0;
     float Time::_totalTime = 0;

    void Time::_Initialize() {
    }

    void Time::_Update() {
        float time = (float) glfwGetTime();
        _deltaTime = time;
        _totalTime += time;
        glfwSetTime(0);
    }

    float Time::DeltaTime() {
        return _deltaTime;
    }

    float Time::TotalTime()
    {
        return _totalTime;
    }

} // Engine