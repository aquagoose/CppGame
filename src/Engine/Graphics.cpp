//
// Created by ollie on 11/09/2022.
//

#include "Graphics.h"
#include <iostream>

namespace Engine {
    Graphics::Graphics(GameWindow *window) {
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        glFrontFace(GL_CCW);

        //glEnable(GL_BLEND);
        //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        SetViewport(glm::ivec4(0, 0, window->Size().x, window->Size().y));

        std::cout << "Graphics initialized." << std::endl;
    }

    void Graphics::Clear(uint8_t r, uint8_t g, uint8_t b) {
        glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    glm::ivec4 Graphics::Viewport() {
        return _viewport;
    }

    void Graphics::SetViewport(glm::ivec4 viewport) {
        _viewport = viewport;
        glViewport(viewport.x, viewport.y, viewport.z, viewport.w);
    }
} // Engine