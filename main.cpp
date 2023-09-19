#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Obstacle.h"
#include <cstdlib> 
#include <ctime>

 
float g_moveSpeed = 0.2f;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Flappy Toast");

    // Load the background texture
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("C:/Users/sosob/OneDrive/Bureau/ENSISA/Informatique/Cpp/FlappyToast/ressources/background.png")) {
        // handle error...
    }

    // Load the obstacle texture
    sf::Texture obstacleTexture;
    if (!obstacleTexture.loadFromFile("C:/Users/sosob/OneDrive/Bureau/ENSISA/Informatique/Cpp/FlappyToast/ressources/obstacle.png")) {
        // handle error...
    }

    // Create two instances of the background placed side by side
    Background background1(backgroundTexture, 0, 0, window.getSize().x, window.getSize().y);
    Background background2(backgroundTexture, window.getSize().x, 0, window.getSize().x, window.getSize().y);
    // TODO: Add more backgrounds with different variations

    //TODO: Fixing  obstacle loading too late
    //TODO: Generate between 2 and 3 object by "frame" for the moment
    // Seed the random number generator
    std::srand(std::time(nullptr));

    // Generate a random number between 2 and 3
    int numObjects = std::rand() % 2 + 2;
    //TODO: ADD generateRandomObstacles function that add the obstacles to the vector and an erase function to clean the vector also don't forget to check if obstacles aren't on top of another
    std::vector<Obstacle> obstacles;
    for (int i = 0; i < numObjects; ++i) {
        Obstacle obstacle(obstacleTexture, 190.0f);
        obstacles.push_back(obstacle);
    }

    //Loading sprites
    sf::Texture t1;
    if (!t1.loadFromFile("C:/Users/sosob/OneDrive/Bureau/ENSISA/Informatique/Cpp/FlappyToast/ressources/Toast_1.png")) {
        // error...
    }

    sf::Texture t2;
    if (!t2.loadFromFile("C:/Users/sosob/OneDrive/Bureau/ENSISA/Informatique/Cpp/FlappyToast/ressources/Toast_2.png")) {
        // error...
    }

    //Initializing sprites
    sf::Sprite sprite;
    sprite.setScale(5, 5);
    sprite.setTexture(t1);
    sprite.setPosition(200, 200);

    int frame = 0;
    sf::Clock clock;
    sf::Time frameTime = sf::seconds(0.4f); // Change frame every 0.4 seconds

    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (clock.getElapsedTime() > frameTime)
        {
            // Switch texture every frame
            if (frame == 0)
                sprite.setTexture(t1);
            else if (frame == 1)
                sprite.setTexture(t2);

            // Increment frame
            frame = (frame + 1) % 2;

            // Restart clock
            clock.restart();
        }

        // Handle keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            // Only move up if the sprite's y position is greater than the minimum
            if (sprite.getPosition().y > -40) {
                sprite.move(sf::Vector2f(0.0f, -g_moveSpeed));
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            // Only move down if the sprite's y position is less than the maximum
            if (sprite.getPosition().y < 500) {
                sprite.move(sf::Vector2f(0.0f, g_moveSpeed));
            }
        }

        // Update the backgrounds
        background1.update(deltaTime.asSeconds());
        background2.update(deltaTime.asSeconds());
        // Update the obstacles
        for (Obstacle& obstacle : obstacles) {
            obstacle.update(deltaTime.asSeconds());
        }

        window.clear();

        // Render the backgrounds
        background1.render(window);
        background2.render(window);
        // Render the obstacles
        for (const Obstacle& obstacle : obstacles) {
            obstacle.render(window);
        }

        window.draw(sprite);
        // TODO: Complexify movement of the toast
        // TODO: Obstacles generation
        // TODO: Collision detection
        // TODO: Scoring
        // TODO: GameState evolution
        window.display();
    }
    return 0;
}