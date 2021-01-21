#ifndef ROGUELIKE_CHARACTER_H
#define ROGUELIKE_CHARACTER_H

#include <SFML/Graphics.hpp>
#include "Types.h"

//class Knight;
//class Zombie;
//class Dragon;

class Character {
protected:
    int health;
    int max_health;
    sf::Vector2i position;
public:
    int damage;
    float x, y, width, height, dx, dy, speed = 0;
    int dir = 0;
    Type type;
    virtual int GetHealth() = 0;
    virtual int GetMaxHealth() = 0;
    virtual sf::Vector2i GetPosition() = 0;
    virtual void SetPosition(float,float) = 0;
    virtual void reduceHp(int)=0;
    bool life = true;
//    virtual bool collide(std::unique_ptr<Character>)=0;
//    virtual bool collide(std::unique_ptr<Knight>)=0;
//    virtual bool collide(std::unique_ptr<Zombie>)=0;
//    virtual bool collide(std::unique_ptr<Dragon>)=0;
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
    void set_0_hp();
    void addHP(int);
    void reduceHp(int) override;
//    bool collide(std::unique_ptr<Character>) override;
//    bool collide(std::unique_ptr<Knight>) override;
//    bool collide(std::unique_ptr<Zombie>) override;
//    bool collide(std::unique_ptr<Dragon>) override;
};

class Zombie : public Character {
public:
    Zombie(float x, float y);
    int GetHealth() override;
    int GetMaxHealth() override;
    sf::Vector2i GetPosition() override;
    void SetPosition(float,float) override;
    void reduceHp(int) override;
//    bool collide(std::unique_ptr<Character>) override;
//    bool collide(std::unique_ptr<Knight>) override;
//    bool collide(std::unique_ptr<Zombie>) override;
//    bool collide(std::unique_ptr<Dragon>) override;
};

class Dragon : public Character {
public:
    Dragon(float x, float y);
    int GetHealth() override;
    int GetMaxHealth() override;
    sf::Vector2i GetPosition() override;
    void SetPosition(float,float) override;
    void reduceHp(int) override;
//    bool collide(std::unique_ptr<Character>) override;
//    bool collide(std::unique_ptr<Knight>) override;
//    bool collide(std::unique_ptr<Zombie>) override;
//    bool collide(std::unique_ptr<Dragon>) override;
};

class Bullet {
private:

    sf::Vector2i position;
    int dir;
public:
    int damage = 50;
    Type type;
    float speed=0.3,dx,dy,x,y,height=15,width=9;
    Bullet(float, float);
    void SetPosition(float,float);
    sf::Vector2i GetPosition();
    bool life = true;
};
#endif //ROGUELIKE_CHARACTER_H
