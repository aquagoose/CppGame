//
// Created by ollie on 11/09/2022.
//

#include "Game.h"
#include "Time.h"
#include <iostream>
#include "SceneManager.h"

namespace Engine {
    Game* Game::_instance;

    Game::Game(Engine::WindowSettings& settings, Scene* scene) {
        _settings = settings;
        _instance = this;
        SceneManager::_Start(scene);
    }

    Game::~Game() {
        std::cout << "Game destructor called." << std::endl;
        delete Renderer;
        delete Graphics;
        delete Window;
    }

    void Game::Run() {
        Window = Engine::GameWindow::CreateWindow(_settings);
        Graphics = new class Graphics(Window);
        Renderer = new SpriteRenderer(Graphics);

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
    }

    Game *Game::Instance()
    {
        return _instance;
    }

    void Game::Initialize()
    {
        SceneManager::_Initialize();
    }

    void Game::Update()
    {
        SceneManager::_Update();
    }

    void Game::Draw()
    {
        SceneManager::_Draw();
    }
} // Engine