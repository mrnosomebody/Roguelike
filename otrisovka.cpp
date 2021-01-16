#include "otrisovka.h"

Otrisovka::Otrisovka() {
    auto loadSprite = [this](std::string path) {
        sf::Image image;
        image.loadFromFile(path);
        image.createMaskFromColor(sf::Color::White);
        textures.push_back(std::make_shared<sf::Texture>());
        textures[textures.size() - 1]->loadFromImage(image);
        sf::Sprite sprite;
        sprite.setTexture(*textures[textures.size() - 1]);
        sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
        return sprite;
    };
    sprites[Type::player] = loadSprite("C:/Users/mrnos/CLionProjects/roguelike/imgs/knights.png");
    sprites[Type::wall] = loadSprite("C:/Users/mrnos/CLionProjects/roguelike/imgs/wall_1.png");
    sprites[Type::zombie] = loadSprite("C:/Users/mrnos/CLionProjects/roguelike/imgs/zombie.png");
    sprites[Type::door] = loadSprite("C:/Users/mrnos/CLionProjects/roguelike/imgs/doors_all.png");
    sprites[Type::grass] = loadSprite("C:/Users/mrnos/CLionProjects/roguelike/imgs/floor.png");
}

const sf::Sprite &Otrisovka::draw(Type type, sf::Vector2i position) {
    auto &cell = sprites[type];
    cell.setPosition(position.x, position.y);
    return cell;
}