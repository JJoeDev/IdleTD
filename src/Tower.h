#ifndef TOWER_H_
#define TOWER_H_

#include "Entity.h"
#include <SFML/Graphics.hpp>

class Tower : public Entity{
public:
    Tower(const sf::Vector2f& pos, const int& health, const float& radius);

    void update() override;
    void render(sf::RenderWindow& window) const override;
    sf::Shape& returnShape() override;

    inline sf::Vector2f& getCenter() { return center; }

private:
    sf::CircleShape shape{};

    sf::Vector2f center{0, 0};

    sf::Vertex _directionLine[2];
};

#endif