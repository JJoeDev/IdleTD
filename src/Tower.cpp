#include "Tower.h"
#include "Enemy.h"
#include "Entity.h"
#include "helpers.hpp"
#include <limits>
#include <vector>

Tower::Tower(const sf::Vector2f& pos, const int& health, const float& radius) : Entity() {
    setPosition(pos, shape);
    setFillColor(sf::Color::Green, shape);

    shape.setRadius(radius);

    center = sf::Vector2f{_pos.x + radius, _pos.y + radius};

    _directionLine[0].position = sf::Vector2f{_pos.x + radius, _pos.y + radius};
    _directionLine[0].color = sf::Color::White;
    _directionLine[1].position = sf::Vector2f{50, 50};
    _directionLine[1].color = sf::Color::Red;
}

Tower::~Tower(){
    delete _closestEnemy;
}

sf::Shape& Tower::returnShape() {
    return shape;
}

void Tower::update(const float& deltaTime){ // TEST CODE REFACTOR ASAP
    static float cooldown;

    if (_closestEnemy != nullptr){
        _directionLine[1].position = _closestEnemy->getPosition();
        if (cooldown <= 0){
            _closestEnemy->damage(1);
            cooldown = 0.5f;
        }
        else {
            cooldown -= 4 * deltaTime;
        }
    }
    else{
        _directionLine[1].position = getCenter();
    }
}

void Tower::render(sf::RenderWindow& window) const {
    window.draw(shape);

    window.draw(_directionLine, 2, sf::Lines);
}

void Tower::getClosestEnemy(const std::vector<Enemy*>& entities){
    float currentClosest = std::numeric_limits<float>::max();

    for (Enemy* e : entities){
        if (!e->isAlive()) continue; // Skip this loop run

        float distance = Helpers::calculateDistance(getCenter(), e->getPosition());
        if (distance < currentClosest){
            currentClosest = distance;
            _closestEnemy = e;
        }
    }
}