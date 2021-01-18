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
    void update(float,Knight&, Otrisovka& );
    void update(float,Character&, Otrisovka& );
    void interaction_with_the_map(Knight&, Otrisovka& );
    void interaction_with_the_map(Character&, Otrisovka& );
    std::vector<std::vector<std::shared_ptr<GameTile>>> tiles;
    std::vector<std::unique_ptr<Character>> enemiesList;
    std::vector<Item> itemsList;
    int gridLength;
    GameWorld();
    ~GameWorld();
};

#endif
