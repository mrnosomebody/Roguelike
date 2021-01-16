#include <iostream>
#include "Character.h"


Knight::Knight() {
    this->type = Type::player;
    this->health = 100;
    this->max_health = 100;
    this->damage = 10;
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


void Knight::interaction_with_the_map(Otrisovka otrisovka) {

    for (int i = y / 50; i < (y + 50) /
                             50; i++) //проходимся по тайликам, контактирующим с игроком, то есть по всем квадратикам размера 32*32, которые мы окрашивали в 9 уроке. про условия читайте ниже.
    {
        for (int j = x / 50; j < (x + 50) /
                                 50; j++)//икс делим на 32, тем самым получаем левый квадратик, с которым персонаж соприкасается. (он ведь больше размера 32*32, поэтому может одновременно стоять на нескольких квадратах). А j<(x + w) / 32 - условие ограничения координат по иксу. то есть координата самого правого квадрата, который соприкасается с персонажем. таким образом идем в цикле слева направо по иксу, проходя по от левого квадрата (соприкасающегося с героем), до правого квадрата (соприкасающегося с героем)
        {
            if (otrisovka.tiles[i][j]->type ==
                Type::wall)//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
            {
                if (dy > 0)//если мы шли вниз,
                {
                    y = i * 50 -
                        50;//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
                }
                if (dy < 0) {
                    y = i * 50 +
                        50;//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
                }
                if (dx > 0) {
                    x = j * 50 - 50;//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
                }
                if (dx < 0) {
                    x = j * 50 + 50;//аналогично идем влево
                }
            }
        }
    }
}

void Knight::update(float time) {
    Otrisovka otrisovka;
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
    otrisovka.sprites[Type::player].setPosition(x, y); //выводим спрайт в позицию x y
    interaction_with_the_map(otrisovka);
}


Zombie::Zombie(float x, float y) {
    this->type = Type::zombie;
    this->health = 30;
    this->max_health = 30;
    this->damage = 5;
    this->position.x = x * 50;
    this->position.y = y * 50;
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

Dragon::Dragon(float x, float y) {
    this->type = Type::zombie;
    this->health = 30;
    this->max_health = 30;
    this->damage = 5;
    this->position.x = x * 50;
    this->position.y = y * 50;
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