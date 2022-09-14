//
// Created by ollie on 12/09/22.
//

#include "IntroScene.h"
#include "Engine/SceneManager.h"
#include "MainScene.h"
#include "Engine/Input.h"
#include "Engine/Texture2D.h"
#include "Engine/Game.h"
#include "Engine/Time.h"

Engine::Texture2D* _texture;
Engine::SpriteRenderer* _renderer;
float _timer = 0;
float _amount = 0;

void IntroScene::Initialize()
{
    _texture = new Engine::Texture2D("Content/Textures/piegfx-logo.png");

    _renderer = Engine::Game::Instance()->Renderer;
    Engine::Game::Instance()->Graphics->SetBlendingEnabled(true);
}

void IntroScene::Update()
{
    _timer += Engine::Time::DeltaTime();
    if (_timer >= 2)
    {
        Engine::Game::Instance()->Graphics->SetBlendingEnabled(false);
        _amount += 10 * Engine::Time::DeltaTime();
        if (_amount > 8)
            Engine::SceneManager::SetScene(new MainScene());
    }
}

void IntroScene::Draw()
{
    _renderer->Begin();
    _renderer->Draw(_texture, glm::vec2(0), glm::vec4(-1), _amount);
    _renderer->End();
}
