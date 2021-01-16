#ifndef ROGUELIKE_CHARACTER_H
#define ROGUELIKE_CHARACTER_H

#include <SFML/Graphics.hpp>
#include "Types.h"
#include "GameWorld.h"
#include "otrisovka.h"

class Character {
public:
    float x, y, w, h, dx, dy, speed = 0;
    int dir = 0;
    Type type;
    virtual int GetHealth() = 0;
    virtual int GetMaxHealth() = 0;
    virtual sf::Vector2i GetPosition() = 0;
};

class Knight : public Character {
private:
    int health;
    int max_health;
    int damage;
    sf::Vector2i position;
public:
    Knight();
    Knight(float x, float y);
    int GetHealth() override;
    int GetMaxHealth() override;
    sf::Vector2i GetPosition() override;
    void update(float);
    void interaction_with_the_map(Otrisovka otrisovka);
};

class Zombie : public Character {
private:
    int health;
    int max_health;
    int damage;
    sf::Vector2i position;
public:
    Zombie(float x, float y);
    int GetHealth() override;
    int GetMaxHealth() override;
    sf::Vector2i GetPosition() override;
};

class Dragon : public Character {
private:
    int health;
    int max_health;
    int damage;
    sf::Vector2i position;
public:
    Dragon(float x, float y);
    int GetHealth() override;
    int GetMaxHealth() override;
    sf::Vector2i GetPosition() override;
};
#endif //ROGUELIKE_CHARACTER_H
