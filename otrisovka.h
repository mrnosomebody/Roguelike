#ifndef ROGUELIKE_OTRISOVKA_H
#define ROGUELIKE_OTRISOVKA_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>
#include "GameTile.h"
#include "Item.h"

class Otrisovka {
private:
    std::vector<std::shared_ptr <sf::Texture>> textures;
    sf::Font font;
    std::string text_string;
public:
    Otrisovka();
    void init_font();
    void init_hp_bar();
    void update_hp_bar(int);
    sf::Text hp_bar_text;
    sf::Text win_text;
    sf::Text gameover_text;
    sf::RectangleShape hp_bar_back;
    sf::RectangleShape hp_bar_inside;
    std::unordered_map<Type,sf::Sprite> sprites;
    const sf::Sprite& draw(Type type, sf::Vector2i position);
};


#endif //ROGUELIKE_OTRISOVKA_H
