//
// Created by ollie on 12/09/22.
//

#ifndef GAME_SCENE_H
#define GAME_SCENE_H

namespace Engine
{

    class Scene
    {
    public:
        virtual ~Scene();

        virtual void Initialize() = 0;
        virtual void Draw() = 0;
        virtual void Update() = 0;
    };

} // Engine

#endif //GAME_SCENE_H
