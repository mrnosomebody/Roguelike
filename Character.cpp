#include <iostream>
#include "Character.h"


Knight::Knight() {
    this->type = Type::player;
    this->health = 100;
    this->max_health = 100;
    this->damage = 30;
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


void Knight::interaction_with_the_map(Otrisovka& otrisovka) {
    for (int i = y / 50; i < (y+40) /50; i++)
    {
        for (int j = x / 50; j < (x+40)/50 ; j++)
        {
            if (otrisovka.tiles[i][j]->type ==Type::wall) {
                if (dy > 0)
                {
                    y = i * 50 -40;
                }
                if (dy < 0) {
                    y = i * 50 +50;
                }
                if (dx > 0) {
                    x = j * 50 - 40;
                }
                if (dx < 0) {
                    x = j * 50 + 50;
                }
            }
            if (this->GetPosition().x == otrisovka.itemsList[0].GetPosition().x && this->GetPosition().y == otrisovka.itemsList[0].GetPosition().y+10)
            {
                otrisovka.itemsList[0].kartinka.setTextureRect((sf::IntRect(50, 0, 50, 50)));
            }
            if (this->GetPosition().x == otrisovka.itemsList[1].GetPosition().x && this->GetPosition().y == otrisovka.itemsList[1].GetPosition().y+10)
            {
                otrisovka.itemsList[1].kartinka.setTextureRect((sf::IntRect(50, 0, 50, 50)));
            }
            if (this->GetPosition() == otrisovka.itemsList[2].GetPosition())
            {
                otrisovka.itemsList[2].kartinka.setTextureRect((sf::IntRect(50, 0, 50, 50)));
            }
            if (this->GetPosition().x == otrisovka.itemsList[3].GetPosition().x+10 && this->GetPosition().y == otrisovka.itemsList[3].GetPosition().y+10 &&
                !otrisovka.itemsList[3].isPicked())
            {
                if (this->GetHealth() < 100){
                    if (this->GetHealth() > 70) {
                        this->health = max_health;
                        otrisovka.itemsList[3].kartinka.setTextureRect((sf::IntRect(50, 50, 25, 25)));
                        otrisovka.itemsList[3].pick();
                    }
                    else{
                        this->addHP(30);
                        otrisovka.itemsList[3].kartinka.setTextureRect((sf::IntRect(50, 50, 25, 25)));
                        otrisovka.itemsList[3].pick();
                    }
                }

            }
            if (this->GetPosition().x == otrisovka.itemsList[4].GetPosition().x+10 && this->GetPosition().y == otrisovka.itemsList[4].GetPosition().y+10 &&
                !otrisovka.itemsList[4].isPicked())
            {
                if (this->GetHealth() < 100){
                    if (this->GetHealth() > 70) {
                        this->health = max_health;
                        otrisovka.itemsList[4].kartinka.setTextureRect((sf::IntRect(50, 50, 25, 25)));
                        otrisovka.itemsList[4].pick();
                    }
                    else{
                        this->addHP(30);
                        otrisovka.itemsList[4].kartinka.setTextureRect((sf::IntRect(50, 50, 25, 25)));
                        otrisovka.itemsList[4].pick();
                    }
                }

            }

        }
    }
}

void Knight::update(float time, Otrisovka& otrisovka) {
    switch (dir)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
    {
        case 0:
            dx = speed;
            dy = 0;
            break;//по иксу задаем положительную скорость, по игреку зануляем. получаем, что персонаж идет только вправо
        case 1:
            dx = -speed;
            dy = 0;
            break;//по иксу задаем отрицательную скорость, по игреку зануляем. получается, что персонаж идет только влево
        case 2:
            dx = 0;
            dy = speed;
            break;//по иксу задаем нулевое значение, по игреку положительное. получается, что персонаж идет только вниз
        case 3:
            dx = 0;
            dy = -speed;
            break;//по иксу задаем нулевое значение, по игреку отрицательное. получается, что персонаж идет только вверх
    }
    x += dx * time;//ускорение на время получаем смещение координат и как следствие движение
    y += dy * time;
    speed = 0;//зануляем скорость, чтобы персонаж остановился.
    this->position.x = x;
    this->position.y = y;
    interaction_with_the_map(otrisovka);
}


Zombie::Zombie(float x, float y) {
    this->type = Type::zombie;
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

void Zombie::addHP(int hp) {
    this->health += hp;
}

int Zombie::GetMaxHealth() {
    return health;
}

sf::Vector2i Zombie::GetPosition() {
    return position;
}

void Zombie::interaction_with_the_map(Otrisovka & otrisovka) {
    for (int i = y / 50; i < (y+40) /50; i++) {
        for (int j = x / 50; j < (x + 40) / 50; j++) {
            if (otrisovka.tiles[i][j]->type == Type::wall) {
                if (dx > 0) {
                    x = j * 50 - 40;
                    dx = -0.1;
                    break;
                }
                if (dx < 0) {
                    x = j * 50 + 50;
                    dx = 0.1;
                    break;
                }
            }
        }
    }
}

void Zombie::update(float time, Otrisovka &otrisovka) {
    x += dx * time;
    this->position.x = x;
    interaction_with_the_map(otrisovka);
    if (this->health <= 0) {
        life = false;
    }
}

Dragon::Dragon(float x, float y) {
    this->type = Type::dragon;
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

void Dragon::addHP(int hp) {
    this->health += hp;
}

void Dragon::interaction_with_the_map(Otrisovka & otrisovka) {
    for (int i = y / 50; i < (y+40) /50; i++) {
        for (int j = x / 50; j < (x + 40) / 50; j++) {
            if (otrisovka.tiles[i][j]->type == Type::wall) {
                if (dx > 0) {
                    x = j * 50 - 40;
                    dx = -0.1;
                    break;
                }
                if (dx < 0) {
                    x = j * 50 + 50;
                    dx = 0.1;
                    break;
                }
            }
        }
    }
}

void Dragon::update(float time, Otrisovka &otrisovka) {
    x += dx * time;
    this->position.x = x;
    interaction_with_the_map(otrisovka);
    if (this->health <= 0) {
        life = false;
    }
}