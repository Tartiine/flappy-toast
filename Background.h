#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>

class Background {
public:
    Background(sf::Texture& texture, float xPosition, float yPosition, int windowWidth, int windowHeight);
    void update(float deltaTime);
    void render(sf::RenderWindow& window) const;
private:
    sf::Sprite sprite;
};

#endif // BACKGROUND_H
