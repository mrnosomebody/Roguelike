#ifndef ROGUELIKE_ITEM_H
#define ROGUELIKE_ITEM_H
#include "SFML/Graphics.hpp"
#include "Types.h"
#include <memory>
#include <vector>

class Item {
private:
    std::vector<std::shared_ptr <sf::Texture>> textures;
    bool picked = false;
    sf::Vector2i position;
public:
    Type type;
    Item(Type type,float x, float y,std::string path);
    void pick();
    bool isPicked();
    sf::Vector2i GetPosition();
    sf::Sprite kartinka;
};

#endif //ROGUELIKE_ITEM_H
