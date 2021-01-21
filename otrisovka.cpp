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


        if (path == "C:/Users/mrnos/CLionProjects/roguelike/imgs/knights.png"
            || path == "C:/Users/mrnos/CLionProjects/roguelike/imgs/zombie.png"
            || path == "C:/Users/mrnos/CLionProjects/roguelike/imgs/enemy.png" || path == "C:/Users/mrnos/CLionProjects/roguelike/imgs/bullet.png") {
            if (path == "C:/Users/mrnos/CLionProjects/roguelike/imgs/bullet.png") {
                sprite.setTextureRect(sf::IntRect(0, 0, 9, 15));
            }else{
            sprite.setTextureRect(sf::IntRect(0, 0, 40, 40));}
        } else {
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
    sprites[Type::chest] = loadSprite("C:/Users/mrnos/CLionProjects/roguelike/imgs/chest.png");
    sprites[Type::opened_chest] = loadSprite("C:/Users/mrnos/CLionProjects/roguelike/imgs/opened_chest.png");
    sprites[Type::aid] = loadSprite("C:/Users/mrnos/CLionProjects/roguelike/imgs/heart.png");
    sprites[Type::took_aid] = loadSprite("C:/Users/mrnos/CLionProjects/roguelike/imgs/took_aid.png");
    sprites[Type::fog] = loadSprite("C:/Users/mrnos/CLionProjects/roguelike/imgs/wall.png");
    sprites[Type::bullet] = loadSprite("C:/Users/mrnos/CLionProjects/roguelike/imgs/bullet.png");
    init_hp_bar();
    init_font();
}

const sf::Sprite &Otrisovka::draw(Type type, sf::Vector2i position) {
    auto &cell = sprites[type];
    if (type == Type::aid || type ==Type::bullet) {
        cell.setPosition(position.x + 14, position.y + 15);
    } else {
        cell.setPosition(position.x, position.y);
    }
    return cell;
}

void Otrisovka::init_font() {
    this->font.loadFromFile("C:/Users/mrnos/CLionProjects/roguelike/imgs/Anagram.ttf");
}
void Otrisovka::init_hp_bar() {
    this->hp_bar_back.setSize(sf::Vector2f(200.f,30.f));
    this->hp_bar_inside.setSize(sf::Vector2f(200.f,30.f));
    this->hp_bar_back.setFillColor(sf::Color(50,50,50,200));
    this->hp_bar_inside.setFillColor(sf::Color(250,20,20,200));
    this->hp_bar_back.setPosition(20.f,810.f);
    this->hp_bar_inside.setPosition(this->hp_bar_back.getPosition());
    this->hp_bar_text.setFont(this->font);
    this->hp_bar_text.setPosition(this->hp_bar_inside.getPosition());
    this->gameover_text.setFont(this->font);
    this->win_text.setFont(this->font);
    this->gameover_text.setString("Game Over");
    this->win_text.setString("You win");
    this->gameover_text.setFillColor(sf::Color::Red);
    this->win_text.setFillColor(sf::Color::Green);
    this->gameover_text.setPosition(350.f,350.f);
    this->win_text.setPosition(350.f,350.f);
}

void Otrisovka::update_hp_bar(int hp) {
    this->hp_bar_inside.setSize(sf::Vector2f(200/100*hp,30.f));
    this->text_string =std::to_string(hp) ;
    this->hp_bar_text.setString(text_string);
}





