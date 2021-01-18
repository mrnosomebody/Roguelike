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
        if (path =="C:/Users/mrnos/CLionProjects/roguelike/imgs/knights.png"
        || path == "C:/Users/mrnos/CLionProjects/roguelike/imgs/zombie.png"
        || path == "C:/Users/mrnos/CLionProjects/roguelike/imgs/enemy.png")
        {
            sprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
        }
        else {
            sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
        }
        return sprite;
    };
    sprites[Type::player] = loadSprite("C:/Users/mrnos/CLionProjects/roguelike/imgs/knights.png");
    sprites[Type::wall] = loadSprite("C:/Users/mrnos/CLionProjects/roguelike/imgs/wall_1.png");
    sprites[Type::dragon] = loadSprite("C:/Users/mrnos/CLionProjects/roguelike/imgs/enemy.png");
    sprites[Type::door] = loadSprite("C:/Users/mrnos/CLionProjects/roguelike/imgs/door.png");
    sprites[Type::grass] = loadSprite("C:/Users/mrnos/CLionProjects/roguelike/imgs/floor.png");
    sprites[Type::zombie] = loadSprite("C:/Users/mrnos/CLionProjects/roguelike/imgs/zombie.png");
}

const sf::Sprite &Otrisovka::draw(Type type, sf::Vector2i position) {
    auto &cell = sprites[type];
    cell.setPosition(position.x, position.y);
    return cell;
}