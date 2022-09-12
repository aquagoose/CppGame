//
// Created by ollie on 11/09/2022.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "GameWindow.h"
#include "Graphics.h"
#include "Scene.h"
#include "SpriteRenderer.h"

namespace Engine {

    class Game {
    private:
        WindowSettings _settings;
        static Game* _instance;

    public:
        GameWindow* Window;
        class Graphics* Graphics;
        SpriteRenderer* Renderer;

        Game(Engine::WindowSettings& settings, Scene* scene);
        virtual ~Game();

        void Run();

        virtual void Initialize();
        virtual void Update();
        virtual void Draw();

        static Game* Instance();
    };

} // Engine

#endif //GAME_GAME_H
