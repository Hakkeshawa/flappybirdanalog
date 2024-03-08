#include "Game.h"

Game::Game()
    : window(sf::VideoMode(800, 600), "Flappy Bird"),
      birdVelocity(0, 0),
      gravity(0, 0.5f),
      pipeSpeed(-0.2f),
      pipeInterval(200.0f),
      isGameOver(false) {
    
    if (!birdTexture.loadFromFile("bird.png") || !pipeTexture.loadFromFile("pipe.png")) {
    }

    birdSprite.setTexture(birdTexture);
    birdSprite.setPosition(100, 300);

    upperPipe.setTexture(pipeTexture);
    lowerPipe.setTexture(pipeTexture);

    upperPipe.setPosition(800, 0);
    lowerPipe.setPosition(800, 400);
}

void Game::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
            if (!isGameOver) {
                birdVelocity.y = -0.2f;
            } else {
                birdSprite.setPosition(100, 300);
                upperPipe.setPosition(800, 0);
                lowerPipe.setPosition(800, 400);
                isGameOver = false;
            }
        }
    }
}

void Game::update() {
    if (!isGameOver) {

        birdVelocity += gravity;
        birdSprite.move(birdVelocity);

        // Update pipes
        upperPipe.move(pipeSpeed, 0);
        lowerPipe.move(pipeSpeed, 0);
        
        if (birdSprite.getPosition().y < 0 || birdSprite.getPosition().y > 600
            || birdSprite.getGlobalBounds().intersects(upperPipe.getGlobalBounds())
            || birdSprite.getGlobalBounds().intersects(lowerPipe.getGlobalBounds())) {
            isGameOver = true;
        }

        if (upperPipe.getPosition().x < -100) {
            upperPipe.setPosition(800, 0);
            lowerPipe.setPosition(800, 400);
        }
    }
}

void Game::render() {
    window.clear();

    window.draw(birdSprite);
    window.draw(upperPipe);
    window.draw(lowerPipe);

    window.display();
}

void Game::run() {
    while (window.isOpen()) {
        handleInput();
        update();
        render();
    }
}
