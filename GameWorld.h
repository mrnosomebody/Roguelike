#ifndef ROGUELIKE_GAMEWORLD_H
#define ROGUELIKE_GAMEWORLD_H

#include <SFML/Graphics.hpp>
#include "GameTile.h"
#include <vector>
#include "Character.h"
#include "otrisovka.h"


class GameWorld {
private:
    Knight player;
    sf::RenderWindow* window;
    sf::Event event;

    void setUpTiles(Otrisovka& otrisovka);
public:
    std::vector<Zombie> zombiesList;
    std::vector<Dragon> dragonsList;
    int gridLength;
    GameWorld();
    ~GameWorld();
};

#endif
