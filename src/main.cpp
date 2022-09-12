#include "Engine/Game.h"
#include "Engine/SpriteRenderer.h"
#include <iostream>
#include "Engine/Time.h"
#include "Engine/Input.h"

class MyGame : public Engine::Game {
private:
    Engine::SpriteRenderer* _renderer;
    Engine::Texture2D* _texture;
    Engine::Texture2D* _texture2;
    glm::vec2 _pos;

public:
    MyGame(Engine::WindowSettings& settings) : Engine::Game(settings) {}

    void Initialize() override {
        _renderer = new Engine::SpriteRenderer(Graphics);

        _texture = new Engine::Texture2D("/home/ollie/Pictures/piegfx-logo.png");
        _texture2 = new Engine::Texture2D("/home/ollie/Pictures/GOOSED.png");

        _pos = glm::vec2(0);
    }

    void Update() override {

        if (Engine::Input::KeyPressed(Engine::Keys::Escape))
            Window->Close();

        const float speed = 100;
        if (Engine::Input::KeyDown(Engine::Keys::W))
            _pos.y -= speed * Engine::Time::DeltaTime();
        if (Engine::Input::KeyDown(Engine::Keys::S))
            _pos.y += speed * Engine::Time::DeltaTime();
        if (Engine::Input::KeyDown(Engine::Keys::A))
            _pos.x -= speed * Engine::Time::DeltaTime();
        if (Engine::Input::KeyDown(Engine::Keys::D))
            _pos.x += speed * Engine::Time::DeltaTime();
    }

    void Draw() override {
        //Graphics->Clear(100, 149, 237);
        Graphics->Clear(0, 0, 0);

        _renderer->Begin();
        //_renderer->Draw(_texture, glm::vec2(0), (float) abs(sin((double) Engine::Time::TotalTime()) * 8));
        _renderer->Draw(_texture, glm::vec2(0), 0);
        _renderer->Draw(_texture, glm::vec2(120), 1);
        _renderer->Draw(_texture, glm::vec2(240), 2);
        _renderer->Draw(_texture, glm::vec2(360), 3);
        _renderer->Draw(_texture, glm::vec2(480), 4);
        _renderer->Draw(_texture, glm::vec2(600), 5);

        //_renderer->Draw(_texture2, _pos);
        _renderer->End();
    }

    void Close() override {
        delete _texture;
        delete _texture2;
        delete _renderer;
    }
};

int main() {
    Engine::WindowSettings settings = {
            .Size = glm::vec2(1280, 720),
            .Title = "A game or something"
    };

    MyGame game = MyGame(settings);
    game.Run();

    return 0;
}
