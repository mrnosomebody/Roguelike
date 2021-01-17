

#ifndef ROGUELIKE_GAMETILE_H
#define ROGUELIKE_GAMETILE_H

#include <SFML/Graphics.hpp>
#include "Types.h"

class GameTile {
public:
    Type type ;
    sf::Vector2i position;
    GameTile(int,int,Type);
};



#endif