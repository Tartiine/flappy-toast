#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SFML/Graphics.hpp>

class Obstacle {
public:
    Obstacle(sf::Texture& texture, float yPosition);
    void update(float deltaTime);
    void render(sf::RenderWindow& window) const;
private:
    sf::Sprite sprite;
    std::vector<Obstacle> obstacles;
    float yPosition;
    float xPosition;
};
#endif // OBSTACLE_H
