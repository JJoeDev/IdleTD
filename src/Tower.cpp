#include "Tower.h"

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

sf::Shape& Tower::returnShape() {
    return shape;
}

void Tower::update(){

}

void Tower::render(sf::RenderWindow& window) const {
    window.draw(shape);

    window.draw(_directionLine, 2, sf::Lines);
}