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
    sf::Vector2i exitPosition;
    std::vector<sf::Vector2i> enemyPositions;
    sf::Vector2i playerPosition;
    sf::RenderWindow* window;
    sf::Event event;
    void setInitialState();
    void setUpEnemyPositions();
    void setUpTiles(Otrisovka& otrisovka);
public:
    std::vector<std::vector<GameTile *>> tiles;
    std::vector<Zombie> zombiesList;
    int gridLength;
    GameWorld();
    ~GameWorld();
};

#endif
