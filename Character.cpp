#include <iostream>
#include "Character.h"


Knight::Knight() {
    this->type = Type::player;
    this->health = 60;
    this->max_health = 100;
    this->damage = 30;
    this->width= 40;
    this->height= 40;
};

Knight::Knight(float x, float y) : Knight() {
    this->x = x * 50;
    this->y = y * 50;
    this->position.x = x * 50;
    this->position.y = y * 50;
}

int Knight::GetHealth() {
    return health;
}

int Knight::GetMaxHealth() {
    return health;
}

sf::Vector2i Knight::GetPosition() {
    return position;
}

void Knight::addHP(int hp) {
    this->health += hp;
}

void Knight::set_100_hp() {
    this->health=max_health;
}

void Knight::SetPosition(float x, float y) {
    this->position.x=x;
    this->position.y=y;
}

Zombie::Zombie(float x, float y) {
    this->type = Type::zombie;
    this->width= 40;
    this->height= 40;
    this->health = 30;
    this->max_health = 30;
    this->damage = 5;
    this->x = x * 50;
    this->y = y * 50;
    this->position.x = this->x;
    this->position.y = this->y ;
    this->dx=-0.1;
    this->dy=0;
}

int Zombie::GetHealth() {
    return health;
}

int Zombie::GetMaxHealth() {
    return health;
}

sf::Vector2i Zombie::GetPosition() {
    return position;
}

void Zombie::SetPosition(float x, float y) {
    this->position.x=x;
    this->position.y=y;
}

Dragon::Dragon(float x, float y) {
    this->type = Type::dragon;
    this->width= 40;
    this->height= 40;
    this->health = 30;
    this->max_health = 30;
    this->damage = 5;
    this->x = x * 50;
    this->y = y * 50;
    this->position.x = this->x;
    this->position.y = this->y ;
    this->dx=-0.1;
    this->dy=0;
}

int Dragon::GetHealth() {
    return health;
}

int Dragon::GetMaxHealth() {
    return health;
}

sf::Vector2i Dragon::GetPosition() {
    return position;
}

void Dragon::SetPosition(float x, float y) {
    this->position.x=x;
    this->position.y=y;
}
