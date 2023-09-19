#include "Obstacle.h"
#include <cstdlib> // for std::rand and std::srand
#include <ctime> // for std::time

Obstacle::Obstacle(sf::Texture& texture, float yPosition)
    : yPosition(yPosition) // Store the original y position 
{
    sprite.setTexture(texture);
    // Generate a random y-position between yPositionOriginal - 100 and yPositionOriginal + 100
    float randomYPosition = yPosition - 50 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX/(100)));
    //TODO: Check if another obstacle is already here
    float randomXPosition = 0.0f + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX/(600.0f)));
    bool isPositionOccupied = true;

    while (isPositionOccupied) {
        isPositionOccupied = false;
        for (Obstacle& obstacle : obstacles) {
            if (obstacle.xPosition == randomXPosition) {
                isPositionOccupied = true;
                break;
            }
        }
        if (isPositionOccupied) {
            randomXPosition = 0.0f + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX/(600.0f)));
        }
    }
    xPosition = randomXPosition;
    sprite.setPosition(randomXPosition, randomYPosition);
    sprite.setScale(10,14);
}

void Obstacle::update(float deltaTime){
    float speed = 100.0f; 
    sprite.move(-speed * deltaTime, 0.0f);
    // Check if the obstacle sprite is off the screen
    if (sprite.getPosition().x < -sprite.getGlobalBounds().width) {
        // Generate a random y-position between yPosition - 100 and yPosition + 100
        float randomYPosition = yPosition - 50 + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX/(10)));

        // Move the sprite to the right side of the screen at the new random y-position
        sprite.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width * 2, randomYPosition);
    }
}

void Obstacle::render(sf::RenderWindow& window) const{
    window.draw(sprite);
}