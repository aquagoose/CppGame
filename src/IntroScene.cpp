//
// Created by ollie on 12/09/22.
//

#include "IntroScene.h"
#include "Engine/SceneManager.h"
#include "MainScene.h"
#include "Engine/Input.h"

void IntroScene::Initialize()
{

}

void IntroScene::Update()
{
    if (Engine::Input::KeyPressed(Engine::Keys::Space))
        Engine::SceneManager::SetScene(new MainScene());
}

void IntroScene::Draw()
{

}
