#ifndef HELPERS_HPP_
#define HELPERS_HPP_

#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace Helpers{
    inline float calculateDistance(const sf::Vector2f& point1, const sf::Vector2f& point2){
        float destX = point1.x - point2.x;
        float destY = point1.y - point2.y;

        return std::sqrt(destX * destX + destY * destY);
    }
}

#endif