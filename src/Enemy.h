#ifndef ENEMY_H_
#define ENEMY_H_

#include "Entity.h"
#include "Player.h"

class Enemy : public Entity{
public:
    Enemy(Player* p, const sf::Vector2f& pos, const int& health);

    void update(const float& deltaTime) override;
    void render(sf::RenderWindow& window) const override;
    sf::Shape& returnShape() override;

    inline void setTargetPos(const sf::Vector2f& pos) { targetPos = pos; }
    inline bool& isAlive() { return _alive; }

    inline void damage(const float& amount) { 
        _health -= amount;
        _p->addMoney((int)amount);
        if (_health <= 0) _alive = false;
    }

private:
    float _health{0};
    bool _alive{true};

    sf::RectangleShape shape;

    sf::Vector2f targetPos{0, 0};
};

#endif