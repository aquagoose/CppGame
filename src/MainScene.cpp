//
// Created by ollie on 12/09/22.
//

#include "MainScene.h"
#include "Engine/Bitmap.h"
#include "Engine/Texture2D.h"
#include "Engine/Time.h"
#include "Engine/Input.h"
#include "Engine/Game.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

void MainScene::Initialize()
{
    _graphics = Engine::Game::Instance()->Graphics;
    _renderer = Engine::Game::Instance()->Renderer;

    Engine::Bitmap bp = Engine::Bitmap("/home/ollie/Downloads/testmap.png");
    _tilemapSize = bp.Size();
    _tiles = new Tile[_tilemapSize.x * _tilemapSize.y];

    uint8_t* data = bp.Data();
    for (int y = 0; y < _tilemapSize.y; y++)
    {
        for (int x = 0; x < _tilemapSize.x; x++)
        {
            int loc = (y * _tilemapSize.x + x) * 4;
            if (data[loc] == 255)
            {
                std::cout << "|W";
                _tiles[y * _tilemapSize.x + x] = Tile {
                        .Position = glm::ivec2(x, y),
                        .Source = glm::ivec4(32, 0, 32, 32)
                };
            }
            else if (data[loc] == 0)
            {
                std::cout << "|G";
                _tiles[y * _tilemapSize.x + x] = Tile {
                        .Position = glm::ivec2(x, y),
                        .Source = glm::ivec4(0, 0, 32, 32)
                };
            }
        }
        std::cout << "|" << std::endl;
    }

    _texture = new Engine::Texture2D("/home/ollie/Downloads/testset.png");

    _pos = glm::vec2(0);
    _scale = glm::vec2(3);
}

void MainScene::Update()
{
    if (Engine::Input::KeyDown(Engine::Keys::W))
        _pos.y -= 50 * Engine::Time::DeltaTime();
    if (Engine::Input::KeyDown(Engine::Keys::S))
        _pos.y += 50 * Engine::Time::DeltaTime();
    if (Engine::Input::KeyDown(Engine::Keys::D))
        _pos.x += 50 * Engine::Time::DeltaTime();
    if (Engine::Input::KeyDown(Engine::Keys::A))
        _pos.x -= 50 * Engine::Time::DeltaTime();

    glm::ivec2 maxSize = glm::ivec2(glm::vec2(_tilemapSize) * _scale) * 32;
    // Lock camera
    if (_pos.x <= 0)
        _pos.x = 0;
    if (_pos.y <= 0)
        _pos.y = 0;
    if (_graphics->Viewport().z + (int) _pos.x * _scale.x >= maxSize.x)
        _pos.x = float(maxSize.x - _graphics->Viewport().z) / _scale.x;
    if (_graphics->Viewport().w + (int) _pos.y * _scale.y >= maxSize.y)
        _pos.y = float(maxSize.y - _graphics->Viewport().w) / _scale.y;
}

void MainScene::Draw()
{
    glm::mat4 transform = glm::mat4(1.0);
    transform = glm::scale(transform, glm::vec3(_scale, 1.0f));
    transform = glm::translate(transform, glm::vec3(-_pos, 0));

    // Works out what part of the tilemap to draw on screen. This should be able to handle billions of tiles as it
    // only renders the tiles that are visible.
    // The std::min and max aren't strictly necessary since the camera view should be locked, however this can handle
    // if there is such an occasion where it is not locked without causing undefined behaviour.
    int minX = (int) std::max(floor((_pos.x * _scale.x) / _scale.x / 32.0) + 1, 0.0);
    int minY = (int) std::max(floor((_pos.y * _scale.y) / _scale.y / 32.0) + 1, 0.0);
    int maxX = (int) std::min(ceil(((float) _graphics->Viewport().z + _pos.x * _scale.x) / _scale.x / 32.0) - 1, (double) _tilemapSize.x);
    int maxY = (int) std::min(ceil(((float) _graphics->Viewport().w + _pos.y * _scale.y) / _scale.y / 32.0) - 1, (double) _tilemapSize.y);

    _renderer->Begin(transform);
    for (int y = minY; y < maxY; y++)
    {
        for (int x = minX; x < maxX; x++)
        {
            Tile* tile = &_tiles[y * _tilemapSize.y + x];
            _renderer->Draw(_texture, glm::vec2(tile->Position) * glm::vec2(32), tile->Source);
        }
    }
    _renderer->End();
}

MainScene::~MainScene()
{
    delete _texture;
    delete _tiles;
    delete _renderer;

    Scene::~Scene();
}
