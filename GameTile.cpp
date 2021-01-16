#include "GameTile.h"

GameTile::GameTile( int x, int y, Type type) {
    position = sf::Vector2i(x, y);
    this->type = type;
}

