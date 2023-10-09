#ifndef TOWER_H_
#define TOWER_H_

#include "Enemy.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Tower : public Entity{
public:
    Tower(const sf::Vector2f& pos, const int& health, const float& radius);
    ~Tower() override;

    void update(const float& deltaTime) override;
    void render(sf::RenderWindow& window) const override;
    sf::Shape& returnShape() override;

    void getClosestEnemy(const std::vector<Enemy*>& enemies);

    inline sf::Vector2f& getCenter() { return center; }

private:
    Enemy* _closestEnemy{nullptr};

    sf::CircleShape shape{};

    sf::Vector2f center{0, 0};

    sf::Vertex _directionLine[2];
};

#endif