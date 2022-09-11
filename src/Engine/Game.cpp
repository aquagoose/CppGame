//
// Created by ollie on 11/09/2022.
//

#include "Game.h"
#include "Time.h"
#include <iostream>

namespace Engine {
    Game::Game() {
        Engine::WindowSettings settings = {};
        settings.Size = glm::ivec2(1920, 1080);
        settings.Title = "Game";
        _settings = settings;
    }

    Game::~Game() {
        std::cout << "Game destructor called." << std::endl;
        delete Graphics;
        delete Window;
    }

    void Game::Run() {
        Window = Engine::GameWindow::CreateWindow(_settings);
        Graphics = new class Graphics(Window);

        Initialize();
        Time::_Initialize();

        while (!Window->ShouldClose())
        {
            Window->ProcessEvents();
            Time::_Update();
            Update();
            Draw();
            Window->Present(1);
        }

        Close();
    }
} // Engine