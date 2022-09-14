//
// Created by ollie on 11/09/2022.
//

#ifndef GAME_GRAPHICS_H
#define GAME_GRAPHICS_H

#include "GameWindow.h"

namespace Engine {

    class Graphics {
    private:
        glm::ivec4 _viewport;
        bool _blending;

    public:
        Graphics(GameWindow* window);

        void Clear(uint8_t r, uint8_t g, uint8_t b);

        glm::ivec4 Viewport();
        void SetViewport(glm::ivec4 viewport);

        bool BlendingEnabled();
        void SetBlendingEnabled(bool enabled);
    };

} // Engine

#endif //GAME_GRAPHICS_H
