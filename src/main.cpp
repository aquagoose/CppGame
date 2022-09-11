#include "Engine/Game.h"
#include "Engine/SpriteRenderer.h"
#include <iostream>
#include "Engine/Time.h"

class MyGame : public Engine::Game {
private:
    Engine::SpriteRenderer* _renderer;
    Engine::Texture2D* _texture;
    Engine::Texture2D* _texture2;
    int _pos;

public:
    void Initialize() override {
        _renderer = new Engine::SpriteRenderer(Graphics);

        _texture = new Engine::Texture2D("C:/Users/ollie/Pictures/awesomeface.png");
        _texture2 = new Engine::Texture2D("C:/Users/ollie/Pictures/GOOSED.png");
    }

    void Update() override {
        _pos++;

        std::cout << Engine::Time::DeltaTime() << std::endl;
    }

    void Draw() override {
        Graphics->Clear(100, 149, 237);

        _renderer->Begin();
        _renderer->Draw(_texture, glm::vec2(0));
        _renderer->Draw(_texture, glm::vec2(100));
        _renderer->Draw(_texture, glm::vec2(200));
        _renderer->Draw(_texture, glm::vec2(300));
        _renderer->Draw(_texture, glm::vec2(400));
        _renderer->Draw(_texture, glm::vec2(500));

        _renderer->Draw(_texture2, glm::vec2(_pos, 0));
        _renderer->End();
    }

    void Close() override {
        delete _texture;
        delete _texture2;
        delete _renderer;
    }
};

int main() {
    MyGame game = MyGame();
    game.Run();

    return 0;
}
