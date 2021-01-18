#ifndef ROGUELIKE_CHARACTER_H
#define ROGUELIKE_CHARACTER_H

#include <SFML/Graphics.hpp>
#include "Types.h"

class Character {
protected:
    int health;
    int max_health;
    int damage;
    sf::Vector2i position;
public:
    float x, y, width, height, dx, dy, speed = 0;
    int dir = 0;
    Type type;
    virtual int GetHealth() = 0;
    virtual int GetMaxHealth() = 0;
    virtual sf::Vector2i GetPosition() = 0;
    virtual void SetPosition(float,float) = 0;
    bool life = true;
};

class Knight : public Character {
public:
    Knight();
    Knight(float x, float y);
    int GetHealth() override;
    int GetMaxHealth() override;
    sf::Vector2i GetPosition() override;
    void SetPosition(float,float) override;
    void set_100_hp();
    void addHP(int);
};

class Zombie : public Character {
public:
    Zombie(float x, float y);
    int GetHealth() override;
    int GetMaxHealth() override;
    sf::Vector2i GetPosition() override;
    void SetPosition(float,float) override;
};

class Dragon : public Character {
public:
    Dragon(float x, float y);
    int GetHealth() override;
    int GetMaxHealth() override;
    sf::Vector2i GetPosition() override;
    void SetPosition(float,float) override;
};
#endif //ROGUELIKE_CHARACTER_H
