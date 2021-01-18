#ifndef ROGUELIKE_CHARACTER_H
#define ROGUELIKE_CHARACTER_H

#include <SFML/Graphics.hpp>
#include "Types.h"
#include "otrisovka.h"

class Character {
protected:
    int health;
    int max_health;
    int damage;
    sf::Vector2i position;
public:
    float x, y, dx, dy, speed = 0;
    int dir = 0;
    Type type;
    virtual int GetHealth() = 0;
    virtual int GetMaxHealth() = 0;
    virtual sf::Vector2i GetPosition() = 0;
    virtual void update(float,Otrisovka& )=0;
    virtual void interaction_with_the_map(Otrisovka& )=0;
    virtual void addHP(int )=0;
    bool life = true;
};

class Knight : public Character {
public:
    Knight();
    Knight(float x, float y);
    int GetHealth() override;
    int GetMaxHealth() override;
    sf::Vector2i GetPosition() override;
    void update(float,Otrisovka&) override;
    void interaction_with_the_map(Otrisovka&) override;
    void addHP(int) override;
};

class Zombie : public Character {
public:
    Zombie(float x, float y);
    int GetHealth() override;
    int GetMaxHealth() override;
    sf::Vector2i GetPosition() override;
    void update(float,Otrisovka&) override;
    void interaction_with_the_map(Otrisovka&) override;
    void addHP(int) override;
};

class Dragon : public Character {
public:
    Dragon(float x, float y);
    int GetHealth() override;
    int GetMaxHealth() override;
    sf::Vector2i GetPosition() override;
    void update(float,Otrisovka&) override;
    void interaction_with_the_map(Otrisovka&) override;
    void addHP(int) override;
};
#endif //ROGUELIKE_CHARACTER_H
