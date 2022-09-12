//
// Created by ollie on 12/09/22.
//

#ifndef GAME_MAINSCENE_H
#define GAME_MAINSCENE_H

#include "Engine/Scene.h"
#include "glm/vec2.hpp"
#include "Engine/Texture2D.h"
#include "Tile.h"
#include "Engine/Graphics.h"
#include "Engine/SpriteRenderer.h"

class MainScene : public Engine::Scene
{
private:
    Tile* _tiles;
    glm::ivec2 _tilemapSize;
    Engine::Texture2D* _texture;
    glm::vec2 _pos;
    glm::vec2 _scale;

    Engine::Graphics* _graphics;
    Engine::SpriteRenderer* _renderer;

public:
    void Initialize() override;
    void Update() override;
    void Draw() override;
    ~MainScene() override;
};


#endif //GAME_MAINSCENE_H
