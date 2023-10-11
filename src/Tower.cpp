#include "Tower.h"
#include "Enemy.h"
#include "Entity.h"
#include "helpers.hpp"
#include <SFML/System/Vector2.hpp>
#include <cstddef>
#include <iostream>
#include <limits>
#include <vector>

Tower::Tower(Player* p, const sf::Vector2f& pos, const int& health, const float& radius) : Entity() {
    setPosition(pos, shape);
    setFillColor(sf::Color::Green, shape);

    shape.setRadius(radius);

    center = sf::Vector2f{_pos.x + radius, _pos.y + radius};

    _directionLine[0].position = sf::Vector2f{_pos.x + radius, _pos.y + radius};
    _directionLine[0].color = sf::Color::White;
    _directionLine[1].position = sf::Vector2f{50, 50};
    _directionLine[1].color = sf::Color::Red;

    _p = p;

    testCircle.setRadius(_range);
    testCircle.setPosition(sf::Vector2f{_pos.x - _range, _pos.y - _range});
    testCircle.setFillColor(sf::Color{200, 150, 0, 150});
}

Tower::~Tower(){
    //delete _closestEnemy; // Dont delete this pointer as the cleanup will do it when game is not running
    _closestEnemy = nullptr;
}

sf::Shape& Tower::returnShape() {
    return shape;
}

void Tower::update(const float& deltaTime){
    static float coolDown{_attack};

    if (_closestEnemy != nullptr && _closestEnemy->isAlive()){ // Look for better solutions
        if (_enemyDistance <= _range && coolDown <= 0){
            _directionLine[1].position = _closestEnemy->getPosition();
            _closestEnemy->damage(_damage);
            coolDown = _attack;
        }
        else if (_range < _enemyDistance && _directionLine[1].position != getCenter())
            _directionLine[1].position = getCenter();
        else if (coolDown > 0)
            coolDown -= deltaTime;
    }
    else
        _directionLine[1].position = getCenter();
}

void Tower::render(sf::RenderWindow& window) const {
    window.draw(shape);

    window.draw(_directionLine, 2, sf::Lines);

    window.draw(testCircle);
}

void Tower::getClosestEnemy(const std::vector<Enemy*>& entities){
    float currentClosest = std::numeric_limits<float>::max();

    for (Enemy* e : entities){
        if (!e->isAlive()) continue; // Skip this loop run

        float distance = Helpers::calculateDistance(getCenter(), e->getPosition());
        if (distance < currentClosest){
            currentClosest = distance;
            _closestEnemy = e;
            _enemyDistance = distance;
        }
    }
}

void Tower::upgradeAttackSpeed(){
    if (calculatePrice(_attackUpgrade, _attackPrice))
        _attack -= 0.1;
}

void Tower::upgradeDamage(){
    if (calculatePrice(_damageUpgrade, _damagePrice))
        _damage++;
}

void Tower::upgradeRange(){
    if (calculatePrice(_rangeUpgrade, _rangePrice))
        _range += 5;


    testCircle.setRadius(_range);
    testCircle.setPosition(sf::Vector2f{_pos.x - _range, _pos.y - _range});
}

// PRIVATE

bool Tower::calculatePrice(unsigned short& upgrade, float& upgradePrice){
    if (_p->getMoney() >= upgradePrice){
        upgrade++;
        _p->subMoney(upgradePrice);
        upgradePrice += 0.05f * upgrade * 2 + 0 * upgrade + 0; // f(x) = ax² + bx + c

        return true;
    }

    return false;
}