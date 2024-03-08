#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    void run();

private:
    void handleInput();
    void update();
    void render();

    sf::RenderWindow window;
    sf::Clock clock;

    sf::Texture birdTexture;
    sf::Sprite birdSprite;

    sf::Texture pipeTexture;
    sf::Sprite upperPipe;
    sf::Sprite lowerPipe;

    sf::Vector2f birdVelocity;
    const float gravity;

    const float pipeSpeed;
    const float pipeInterval;

    bool isGameOver;
};

#endif // GAME_H
