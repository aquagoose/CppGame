//
// Created by ollie on 12/09/22.
//

#ifndef GAME_INTROSCENE_H
#define GAME_INTROSCENE_H

#include "Engine/Scene.h"

class IntroScene : public Engine::Scene
{
public:
    void Initialize() override;
    void Update() override;
    void Draw() override;
};


#endif //GAME_INTROSCENE_H
