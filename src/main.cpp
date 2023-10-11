#include<SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <string>
#include <vector>

#include "Entity.h"
#include "Tower.h"
#include "Enemy.h"
#include "Player.h"

//////////////////////////////
// WARNING I USE MANUAL POINTERS TO GET A BETTER UNDERSTANDING OF HOW THEY WORK AND WHY THEY ARE A PAIN TO USE
//////////////////////////////

int main(void){
    sf::RenderWindow window(sf::VideoMode(500, 500), "IdleTD");
    window.setFramerateLimit(60);

    std::vector<Enemy*> enemies;

    Player* p = new Player();

    Tower* T = new Tower(p, sf::Vector2f{(float)window.getSize().x / 2, (float)window.getSize().y / 2}, 5, 10);

    for (int i = 0; i < 1; ++i){
        Enemy* E = new Enemy(p, sf::Vector2f{(float)(rand() % 200 + 10), (float)(rand() % 200 + 10)}, 5);
        E->setTargetPos(T->getCenter());
        enemies.push_back(E);
    }

    sf::Font font;
    font.loadFromFile("../NotoSansMono-Regular.ttf");

    sf::Text moneyText;
    moneyText.setPosition(sf::Vector2f{moneyText.getPosition().x + 5, moneyText.getPosition().y});
    moneyText.setFont(font);
    moneyText.setCharacterSize(24);
    moneyText.setFillColor(sf::Color::Yellow);

    sf::Text damageUpgradeTxt;
    damageUpgradeTxt.setPosition(sf::Vector2f{moneyText.getPosition().x, moneyText.getPosition().y + 25});
    damageUpgradeTxt.setFont(font);
    damageUpgradeTxt.setCharacterSize(24);
    damageUpgradeTxt.setFillColor(sf::Color::Yellow);

    sf::Text attackUpgradeTxt;
    attackUpgradeTxt.setPosition(sf::Vector2f{moneyText.getPosition().x, damageUpgradeTxt.getPosition().y + 25});
    attackUpgradeTxt.setFont(font);
    attackUpgradeTxt.setCharacterSize(24);
    attackUpgradeTxt.setFillColor(sf::Color::Yellow);

    sf::Text rangeUpgradeTxt;
    rangeUpgradeTxt.setPosition(sf::Vector2f{moneyText.getPosition().x, attackUpgradeTxt.getPosition().y + 25});
    rangeUpgradeTxt.setFont(font);
    rangeUpgradeTxt.setCharacterSize(24);
    rangeUpgradeTxt.setFillColor(sf::Color::Yellow);

    sf::Clock clock;
    float deltaTime{0};

    std::string moneyCount{""};
    std::string damagePrice{""};
    std::string attackPrice{""};
    std::string rangePrice{""};

    while(window.isOpen()){
        sf::Event e;
        while(window.pollEvent(e)){
            if (e.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                T->upgradeDamage();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                T->upgradeAttackSpeed();

            if (sf::Keyboard::isKeyPressed((sf::Keyboard::R)))
                T->upgradeRange();
        }

        window.clear();

        T->render(window);
        T->getClosestEnemy(enemies);
        T->update(deltaTime);

        for (Enemy* e : enemies){
            e->update(deltaTime);
            e->render(window);
        }

        moneyCount = "Money: " + std::to_string(p->getMoney());
        damagePrice = "Damage cost: " + std::to_string(T->getDamagePrice());
        attackPrice = "Attack cost: " + std::to_string(T->getAttackPrice());
        rangePrice = "Range cost: " + std::to_string(T->getRangePrice());

        moneyText.setString(moneyCount);
        damageUpgradeTxt.setString(damagePrice);
        attackUpgradeTxt.setString(attackPrice);
        rangeUpgradeTxt.setString(rangePrice);

        window.draw(moneyText);
        window.draw(damageUpgradeTxt);
        window.draw(attackUpgradeTxt);
        window.draw(rangeUpgradeTxt);

        deltaTime = clock.restart().asSeconds();

        window.display();
    }

    delete T;

    for (Enemy* e : enemies){
        delete e;
    }
    enemies.clear();

    delete p;

    return 0;
}