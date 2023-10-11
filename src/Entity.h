#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include "Player.h"

class Entity{
public:
    Entity() { }
    virtual ~Entity(){ _p = nullptr; }

    virtual void update(const float& deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) const = 0;
    virtual sf::Shape& returnShape()  = 0;

    virtual void setPosition(const sf::Vector2f& pos, sf::Shape& shape) { _pos = pos; shape.setPosition(_pos); }
    virtual void setFillColor(const sf::Color& color, sf::Shape& shape) { shape.setFillColor(color); }

    inline sf::Vector2f& getPosition() { return _pos; }

protected:
    Player* _p;

    sf::Vector2f _pos{};

private:
};

#endif