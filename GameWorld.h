#ifndef ROGUELIKE_GAMEWORLD_H
#define ROGUELIKE_GAMEWORLD_H

#include <SFML/Graphics.hpp>
#include "GameTile.h"
#include <vector>
#include "Character.h"
#include "otrisovka.h"



class GameWorld {
private:
    Otrisovka otrisovka;
    Knight player;
    std::unique_ptr<sf::RenderWindow> window;
    sf::Event event;
    sf::Clock clock;
    int gridLength;
    float CurrentFrame = 0;//хранит текущий кадр
    float HeartFrame =0;
    std::vector<std::vector<std::shared_ptr<GameTile>>> tiles;
    std::vector<std::unique_ptr<Character>> enemiesList;
    std::vector<std::unique_ptr<Bullet>> bulletsList;
    std::vector<Item> itemsList;
    void setUpTiles();
    void update(float,Knight&);
    void update(float,Character&);
    void update(float,Bullet&, int);
    void interaction_with_the_map(Bullet&);
    void interaction_with_the_map(Knight&);
    void interaction_with_the_map(Character&);
public:
    GameWorld();
    void run();
};

#endif
