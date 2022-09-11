//
// Created by ollie on 11/09/2022.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "GameWindow.h"
#include "Graphics.h"

namespace Engine {

    class Game {
    private:
        WindowSettings _settings;

    public:
        GameWindow* Window;
        Graphics* Graphics;

        Game();
        ~Game();

        void Run();

        virtual void Initialize() = 0;
        virtual void Update() = 0;
        virtual void Draw() = 0;
        virtual void Close() = 0;
    };

} // Engine

#endif //GAME_GAME_H
