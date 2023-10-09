#include "Enemy.h"

Enemy::Enemy(const sf::Vector2f& pos, const int& health) : Entity(){
    setPosition(pos, shape);
    setFillColor(sf::Color::Red, shape);

    _health = health;

    shape.setSize(sf::Vector2f{10, 10});

    shape.setOrigin(shape.getSize().x / 2, shape.getSize().y / 2);
}

sf::Shape& Enemy::returnShape() {
    return shape;
}

void Enemy::update(const float& deltaTime){
    if (_health <= 0) return;

    sf::Vector2f moveTarget = _pos;

    float targetX = _pos.x - targetPos.x;
    float targetY = _pos.y - targetPos.y;

    if (targetX < -1) // use 1 and -1 to give it a safe space to not move in
        moveTarget.x++;
    else if (targetX > 1)
        moveTarget.x--;

    if (targetY < -1)
        moveTarget.y++;
    else if (targetY > 1)
        moveTarget.y--;

    setPosition(moveTarget, shape);
}

void Enemy::render(sf::RenderWindow& window) const {
    //if (_health <= 0) return;
    window.draw(shape);
}