#ifndef TOWER_H_
#define TOWER_H_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <vector>

#include "Enemy.h"
#include "Entity.h"
#include "Player.h"

class Tower : public Entity{
public:
    Tower(Player* p, const sf::Vector2f& pos, const int& health, const float& radius);
    ~Tower() override;

    void update(const float& deltaTime) override;
    void render(sf::RenderWindow& window) const override;
    sf::Shape& returnShape() override;

    void getClosestEnemy(const std::vector<Enemy*>& enemies);

    inline sf::Vector2f& getCenter() { return center; }
    inline float& getDamagePrice() { return _damagePrice; }
    inline float& getAttackPrice() { return _attackPrice; }
    inline float& getRangePrice() { return _rangePrice; }

    void upgradeDamage();
    void upgradeAttackSpeed();
    void upgradeRange();

private:
    bool calculatePrice(unsigned short& upgrade, float& upgradeCost);

    sf::CircleShape testCircle;

    Enemy* _closestEnemy{nullptr};
    float _enemyDistance{0};

    sf::CircleShape shape{};

    sf::Vector2f center{0, 0};

    sf::Vertex _directionLine[2];

    float _damage{1.0f}; // Damage done per hit
    float _attack{1.0f}; // Speed of attack (seconds)
    float _range{100.0f}; // Randge of attack

    float _damagePrice{25};
    float _attackPrice{25};
    float _rangePrice{25};

    unsigned short _damageUpgrade{0};
    unsigned short _attackUpgrade{0};
    unsigned short _rangeUpgrade{0};
};

#endif