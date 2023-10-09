#include<SFML/Graphics.hpp>
#include <vector>

#include "Entity.h"
#include "Tower.h"
#include "Enemy.h"

//////////////////////////////
// WARNING I USE MANUAL POINTERS TO GET A BETTER UNDERSTANDING OF HOW THEY WORK AND WHY THEY ARE A PAIN TO USE
//////////////////////////////

int main(void){
    sf::RenderWindow window(sf::VideoMode(500, 500), "IdleTD");
    window.setFramerateLimit(60);

    std::vector<Enemy*> enemies;

    Tower* T = new Tower(sf::Vector2f{(float)window.getSize().x / 2, (float)window.getSize().y / 2}, 5, 10);

    for (int i = 0; i < 5; ++i){
        Enemy* E = new Enemy(sf::Vector2f{(float)(rand() % 200 + 10), (float)(rand() % 200 + 10)}, 5);
        E->setTargetPos(T->getCenter());
        enemies.push_back(E);
    }

    sf::Clock clock;
    float deltaTime{0};

    while(window.isOpen()){
        sf::Event e;
        while(window.pollEvent(e)){
            if (e.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        T->render(window);
        T->getClosestEnemy(enemies);
        T->update(deltaTime);

        for (Enemy* e : enemies){
            e->update(deltaTime);
            e->render(window);
        }

        deltaTime = clock.restart().asSeconds();

        window.display();
    }

    delete T;

    for (Enemy* e : enemies){
        delete e;
    }
    enemies.clear();

    return 0;
}