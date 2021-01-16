#ifndef ROGUELIKE_OTRISOVKA_H
#define ROGUELIKE_OTRISOVKA_H
#include "Character.h"
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>
#include "GameTile.h"

class Otrisovka {
private:
    std::vector<std::shared_ptr <sf::Texture>> textures;

public:
    Otrisovka();
    std::vector<std::vector<GameTile *>> tiles;
    std::unordered_map<Type,sf::Sprite> sprites;
    const sf::Sprite& draw(Type type, sf::Vector2i position);
};


#endif //ROGUELIKE_OTRISOVKA_H
