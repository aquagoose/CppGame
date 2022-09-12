#include "Engine/Game.h"
#include "Engine/SpriteRenderer.h"
#include <iostream>
#include "Engine/Time.h"
#include "Engine/Input.h"
#include "Engine/Bitmap.h"
#include "Tile.h"
#include "IntroScene.h"
#include <glm/gtc/matrix_transform.hpp>
#include <algorithm>

class MyGame : public Engine::Game {
public:
    MyGame(Engine::WindowSettings& settings, Engine::Scene* scene) : Engine::Game(settings, scene) {}

    void Update() override {
        Game::Update();

        if (Engine::Input::KeyPressed(Engine::Keys::Escape))
            Window->Close();
    }

    void Draw() override {
        Graphics->Clear(0, 0, 0);
        //Graphics->SetViewport(glm::ivec4(100, 100, 500, 500));

        Game::Draw();
    }
};

int main() {
    Engine::WindowSettings settings = {
            .Size = glm::vec2(1280, 720),
            .Title = "A game or something"
    };

    MyGame game = MyGame(settings, new IntroScene());
    game.Run();

    return 0;
}
