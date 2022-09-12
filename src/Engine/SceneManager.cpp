//
// Created by ollie on 12/09/22.
//

#include "SceneManager.h"

namespace Engine
{
    Scene* SceneManager::_currentScene;
    Scene* SceneManager::_sceneToSwitch;

    void SceneManager::_Start(Scene *scene)
    {
        _currentScene = scene;
        _sceneToSwitch = nullptr;
    }

    void SceneManager::_Initialize()
    {
        _currentScene->Initialize();
    }

    void SceneManager::_Update()
    {
        if (_sceneToSwitch != nullptr)
        {
            delete _currentScene;
            _currentScene = _sceneToSwitch;
            _currentScene->Initialize();
            _sceneToSwitch = nullptr;
        }

        _currentScene->Update();
    }

    void SceneManager::_Draw()
    {
        _currentScene->Draw();
    }

    void SceneManager::SetScene(Scene *scene)
    {
        _sceneToSwitch = scene;
    }
} // Engine