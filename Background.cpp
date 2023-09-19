#include "Background.h"

Background::Background(sf::Texture& texture, float xPosition, float yPosition, int windowWidth, int windowHeight){
    sprite.setTexture(texture);
    sprite.setPosition(xPosition, yPosition);
    // Scale the sprite to match the window size
    sprite.setScale(windowWidth / sprite.getTexture()->getSize().x, windowHeight / sprite.getTexture()->getSize().y);
    // Initialize other attributes as needed
}

void Background::update(float deltaTime){
    float speed = 100.0f; 
    sprite.move(-speed * deltaTime, 0.0f);
    // Check if the background sprite is off the screen
    if (sprite.getPosition().x < -sprite.getGlobalBounds().width) {
        // Move the sprite to the right side of the screen
        sprite.setPosition(sprite.getPosition().x + sprite.getGlobalBounds().width * 2, sprite.getPosition().y);
    }
}

void Background::render(sf::RenderWindow& window) const{
    window.draw(sprite);
}
