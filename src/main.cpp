#include<SFML/Graphics.hpp>

#include "Tower.h"
#include "Enemy.h"

int main(void){
    sf::RenderWindow window(sf::VideoMode(500, 500), "IdleTD");
    window.setFramerateLimit(60);

    Enemy* E = new Enemy(sf::Vector2f{100, 100}, 5);

    Tower* T = new Tower(sf::Vector2f{(float)window.getSize().x / 2, (float)window.getSize().y / 2}, 5, 10);

    E->setTargetPos(T->getCenter());

    while(window.isOpen()){
        sf::Event e;
        while(window.pollEvent(e)){
            if (e.type == sf::Event::Closed)
                window.close();
        }

        E->update();

        window.clear();

        T->render(window);
        E->render(window);

        window.display();
    }

    delete E;
    delete T;

    return 0;
}