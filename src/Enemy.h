#ifndef ENEMY_H_
#define ENEMY_H_

#include "Entity.h"

class Enemy : public Entity{
public:
    Enemy(const sf::Vector2f& pos, const int& health);

    void update(const float& deltaTime) override;
    void render(sf::RenderWindow& window) const override;
    sf::Shape& returnShape() override;

    inline void setTargetPos(const sf::Vector2f& pos) { targetPos = pos; }
    inline bool& isAlive() { return _alive; }

    inline void damage(const int& amount) { 
        _health -= amount;
        if (_health <= 0) _alive = false;
    }

private:
    int _health{0};
    bool _alive{true};

    sf::RectangleShape shape;

    sf::Vector2f targetPos{0, 0};
};

#endif