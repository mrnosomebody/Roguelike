

#ifndef ROGUELIKE_GAMETILE_H
#define ROGUELIKE_GAMETILE_H

#include <SFML/Graphics.hpp>
#include "Types.h"

class GameTile {
public:
    Type type ;
    bool isPassible;
    bool isExit;
    sf::Vector2i position;
    sf::Texture texture;
    sf::Sprite sprite;
    GameTile(int,int,Type);
   // bool setUpSprite(std::string);
};



#endif