//
// Created by ollie on 12/09/22.
//

#ifndef GAME_SCENEMANAGER_H
#define GAME_SCENEMANAGER_H

#include "Scene.h"

namespace Engine
{

    class SceneManager
    {
    private:
        static Scene* _currentScene;
        static Scene* _sceneToSwitch;
        SceneManager() = default;

    public:
        static void _Start(Scene* scene);
        static void _Initialize();
        static void _Update();
        static void _Draw();

        static void SetScene(Scene* scene);
    };

} // Engine

#endif //GAME_SCENEMANAGER_H
