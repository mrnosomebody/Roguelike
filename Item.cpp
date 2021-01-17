#include "Item.h"

Item::Item(Type type, float x, float y, std::string path) : type(type) {
    this->position.x = x * 50;
    this->position.y = y * 50;
    auto loadSprite = [this](std::string path_) {
        sf::Image image;
        image.loadFromFile(path_);
        image.createMaskFromColor(sf::Color::White);
        textures.push_back(std::make_shared<sf::Texture>());
        textures[textures.size() - 1]->loadFromImage(image);
        sf::Sprite sprite;
        sprite.setTexture(*textures[textures.size() - 1]);
        if (path_ == "C:/Users/mrnos/CLionProjects/roguelike/imgs/heart.png")
            sprite.setTextureRect(sf::IntRect(0, 0, 25, 25));
        else{
            sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
        }
        return sprite;
    };
    kartinka = loadSprite(path);
    if (path == "C:/Users/mrnos/CLionProjects/roguelike/imgs/heart.png")
        kartinka.setPosition(position.x+12,position.y+12);
    else {
        kartinka.setPosition(position.x,position.y);
    }
}

void Item::pick() {
    picked = true;
}

bool Item::isPicked() {
    return picked;
}

sf::Vector2i Item::GetPosition() {
    return position;
}

