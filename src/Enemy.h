#ifndef ENEMY_H_
#define ENEMY_H_

#include "Entity.h"

class Enemy : public Entity{
public:
    Enemy(const sf::Vector2f& pos, const int& health);

    void update() override;
    void render(sf::RenderWindow& window) const override;
    sf::Shape& returnShape() override;

    inline void setTargetPos(const sf::Vector2f& pos) { targetPos = pos; }

private:
    sf::RectangleShape shape;

    sf::Vector2f targetPos{0, 0};
};

#endif