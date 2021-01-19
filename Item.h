#ifndef ROGUELIKE_ITEM_H
#define ROGUELIKE_ITEM_H
#include "SFML/Graphics.hpp"
#include "Types.h"
#include <vector>

class Item {
private:
    bool picked = false;
    sf::Vector2i position;

public:
    Type type;
    Item(Type type,float x, float y,std::string path);
    void pick();
    Type GetType();
    void SetUpType(Type);
    bool isPicked();
    sf::Vector2i GetPosition();
};

#endif //ROGUELIKE_ITEM_H
