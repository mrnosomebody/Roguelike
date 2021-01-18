#include <iostream>
#include "GameWorld.h"



using namespace sf;

GameWorld::GameWorld() {
    gridLength = 16;
    Otrisovka otrisovka;
    player = Knight(1,14);
    Zombie zombie_1(11, 2);
    Zombie zombie_2(11, 3);
    Zombie zombie_3(2, 10);
    Zombie zombie_4(6, 14);
    zombiesList.push_back(zombie_1);
    zombiesList.push_back(zombie_2);
    zombiesList.push_back(zombie_3);
    zombiesList.push_back(zombie_4);
    Dragon dragon_1(2,1);
    Dragon dragon_2(3,13);
    Dragon dragon_3(8,14);
    dragonsList.push_back(dragon_1);
    dragonsList.push_back(dragon_2);
    dragonsList.push_back(dragon_3);
    Item item_1(Type::chest,3,14,"C:/Users/mrnos/CLionProjects/roguelike/imgs/chest.png" );
    Item item_2(Type::chest,10,14,"C:/Users/mrnos/CLionProjects/roguelike/imgs/chest.png" );
    Item item_3(Type::chest,14,3,"C:/Users/mrnos/CLionProjects/roguelike/imgs/chest.png" );
    Item item_4(Type::aid,2,2 ,"C:/Users/mrnos/CLionProjects/roguelike/imgs/heart.png");
    Item item_5(Type::aid,3,12,"C:/Users/mrnos/CLionProjects/roguelike/imgs/heart.png" );
    otrisovka.itemsList.push_back(item_1);
    otrisovka.itemsList.push_back(item_2);
    otrisovka.itemsList.push_back(item_3);
    otrisovka.itemsList.push_back(item_4);
    otrisovka.itemsList.push_back(item_5);

    setUpTiles(otrisovka);

    sf::Clock clock;
    float CurrentFrame = 0;//хранит текущий кадр
    float HeartFrame =0;
    this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Roguelike", sf::Style::Titlebar | sf::Style::Close);
    while (window->isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
        clock.restart(); //перезагружает время
        time /= 800; //скорость игры
        while (window->pollEvent(this->event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        window->clear();
        ///Отрисовка карты
        for (int i = 0; i < gridLength; ++i) {
            for (int j = 0; j < gridLength; ++j) {
                window->draw(otrisovka.draw(otrisovka.tiles[i][j]->type, otrisovka.tiles[i][j]->position));
            }
        }
        ///Отрисовка бомжей
        for (auto& i : zombiesList) {
            window->draw(otrisovka.draw(i.type, i.GetPosition()));
        }

        ///Отрисовка чиновников
        for (auto& i : dragonsList) {
            window->draw(otrisovka.draw(i.type, i.GetPosition()));
        }

        ///Отрисовка приколюх
        for (auto& i : otrisovka.itemsList) {
            window->draw(i.kartinka);
        }

        ///Отрисовка главного фраера
        window->draw(otrisovka.draw(player.type, player.GetPosition()));

        HeartFrame += 0.008 * time;
        if (HeartFrame > 13)
            HeartFrame -= 13;
        if (!otrisovka.itemsList[3].isPicked())
            otrisovka.itemsList[3].kartinka.setTextureRect(IntRect(22 * int(HeartFrame), 0, 25, 25));
        if (!otrisovka.itemsList[4].isPicked())
            otrisovka.itemsList[4].kartinka.setTextureRect(IntRect(22 * int(HeartFrame), 0, 25, 25));

        ///Управление персонажем с анимацией
        if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
            player.dir = 1;
            player.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 4)
                CurrentFrame -= 4;
            otrisovka.sprites[Type::player].setTextureRect(IntRect(50 * int(CurrentFrame), 0, -40, 40));
        }

        if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
            player.dir = 0;
            player.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 4)
                CurrentFrame -= 4;
            otrisovka.sprites[Type::player].setTextureRect(IntRect(50 * int(CurrentFrame), 0, 40, 40));
        }

        if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
            player.dir = 3;
            player.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 4)
                CurrentFrame -= 4;
            otrisovka.sprites[Type::player].setTextureRect(IntRect(50 * int(CurrentFrame), 0, 40, 40));
        }

        if ((Keyboard::isKeyPressed(Keyboard::Down) ||
             (Keyboard::isKeyPressed(Keyboard::S)))) {
            player.dir = 2;
            player.speed = 0.1;
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 4)
                CurrentFrame -= 4;
            otrisovka.sprites[Type::player].setTextureRect(IntRect(50 * int(CurrentFrame), 0, 40, 40));
        }

        if ((Keyboard::isKeyPressed(Keyboard::Space))) {
            CurrentFrame += 0.005 * time;
            if (CurrentFrame > 6)
                CurrentFrame -= 3;
            if(player.dir == 1)
                otrisovka.sprites[Type::player].setTextureRect(IntRect(50 * int(CurrentFrame), 0, -40, 40));
            else{
                otrisovka.sprites[Type::player].setTextureRect(IntRect(50 * int(CurrentFrame), 0, 40, 40));
            }
        }
        player.update(time,otrisovka);
        for (auto& i: zombiesList) {
            i.update(time,otrisovka);
        }
        for (auto& i: dragonsList) {
            i.update(time,otrisovka);
        }
        window->display();
    }
}

GameWorld::~GameWorld() {
    delete this->window;
}


void GameWorld::setUpTiles(Otrisovka& otrisovka) {
    otrisovka.tiles.clear();
    std::vector<GameTile *> firstRow;
    firstRow.push_back(new GameTile(0, 0, Type::wall));
    firstRow.push_back(new GameTile(50, 0, Type::wall));
    firstRow.push_back(new GameTile(100, 0, Type::wall));
    firstRow.push_back(new GameTile(150, 0, Type::wall));
    firstRow.push_back(new GameTile(200, 0, Type::wall));
    firstRow.push_back(new GameTile(250, 0, Type::wall));
    firstRow.push_back(new GameTile(300, 0, Type::wall));
    firstRow.push_back(new GameTile(350, 0, Type::wall));
    firstRow.push_back(new GameTile(400, 0, Type::wall));
    firstRow.push_back(new GameTile(450, 0, Type::wall));
    firstRow.push_back(new GameTile(500, 0, Type::wall));
    firstRow.push_back(new GameTile(550, 0, Type::wall));
    firstRow.push_back(new GameTile(600, 0, Type::wall));
    firstRow.push_back(new GameTile(650, 0, Type::wall));
    firstRow.push_back(new GameTile(700, 0, Type::wall));
    firstRow.push_back(new GameTile(750, 0, Type::wall));
    otrisovka.tiles.push_back(firstRow);

    std::vector<GameTile *> secondRow;
    secondRow.push_back(new GameTile(0, 50, Type::wall));
    secondRow.push_back(new GameTile(50, 50, Type::grass));
    secondRow.push_back(new GameTile(100, 50, Type::grass));
    secondRow.push_back(new GameTile(150, 50, Type::wall));
    secondRow.push_back(new GameTile(200, 50, Type::wall));
    secondRow.push_back(new GameTile(250, 50, Type::wall));
    secondRow.push_back(new GameTile(300, 50, Type::wall));
    secondRow.push_back(new GameTile(350, 50, Type::wall));
    secondRow.push_back(new GameTile(400, 50, Type::wall));
    secondRow.push_back(new GameTile(450, 50, Type::wall));
    secondRow.push_back(new GameTile(500, 50, Type::wall));
    secondRow.push_back(new GameTile(550, 50, Type::wall));
    secondRow.push_back(new GameTile(600, 50, Type::wall));
    secondRow.push_back(new GameTile(650, 50, Type::wall));
    secondRow.push_back(new GameTile(700, 50, Type::wall));
    secondRow.push_back(new GameTile(750, 50, Type::wall));
    otrisovka.tiles.push_back(secondRow);

    std::vector<GameTile *> thirdRow;
    thirdRow.push_back(new GameTile(0, 100, Type::wall));
    thirdRow.push_back(new GameTile(50, 100, Type::grass));
    thirdRow.push_back(new GameTile(100, 100, Type::grass));
    thirdRow.push_back(new GameTile(150, 100, Type::wall));
    thirdRow.push_back(new GameTile(200, 100, Type::grass));
    thirdRow.push_back(new GameTile(250, 100, Type::grass));
    thirdRow.push_back(new GameTile(300, 100, Type::grass));
    thirdRow.push_back(new GameTile(350, 100, Type::grass));
    thirdRow.push_back(new GameTile(400, 100, Type::grass));
    thirdRow.push_back(new GameTile(450, 100, Type::grass));
    thirdRow.push_back(new GameTile(500, 100, Type::grass));
    thirdRow.push_back(new GameTile(550, 100, Type::grass));
    thirdRow.push_back(new GameTile(600, 100, Type::wall));
    thirdRow.push_back(new GameTile(650, 100, Type::wall));
    thirdRow.push_back(new GameTile(700, 100, Type::wall));
    thirdRow.push_back(new GameTile(750, 100, Type::wall));
    otrisovka.tiles.push_back(thirdRow);

    std::vector<GameTile *> fourthRow;
    fourthRow.push_back(new GameTile(0, 150, Type::wall));
    fourthRow.push_back(new GameTile(50, 150, Type::grass));
    fourthRow.push_back(new GameTile(100, 150, Type::wall));
    fourthRow.push_back(new GameTile(150, 150, Type::wall));
    fourthRow.push_back(new GameTile(200, 150, Type::grass));
    fourthRow.push_back(new GameTile(250, 150, Type::grass));
    fourthRow.push_back(new GameTile(300, 150, Type::grass));
    fourthRow.push_back(new GameTile(350, 150, Type::grass));
    fourthRow.push_back(new GameTile(400, 150, Type::grass));
    fourthRow.push_back(new GameTile(450, 150, Type::grass));
    fourthRow.push_back(new GameTile(500, 150, Type::grass));
    fourthRow.push_back(new GameTile(550, 150, Type::grass));
    fourthRow.push_back(new GameTile(600, 150, Type::wall));
    fourthRow.push_back(new GameTile(650, 150, Type::wall));
    fourthRow.push_back(new GameTile(700, 150, Type::grass));
    fourthRow.push_back(new GameTile(750, 150, Type::wall));
    otrisovka.tiles.push_back(fourthRow);

    std::vector<GameTile *> fifthRow;
    fifthRow.push_back(new GameTile(0, 200, Type::wall));
    fifthRow.push_back(new GameTile(50, 200, Type::grass));
    fifthRow.push_back(new GameTile(100, 200, Type::wall));
    fifthRow.push_back(new GameTile(150, 200, Type::grass));
    fifthRow.push_back(new GameTile(200, 200, Type::grass));
    fifthRow.push_back(new GameTile(250, 200, Type::wall));
    fifthRow.push_back(new GameTile(300, 200, Type::wall));
    fifthRow.push_back(new GameTile(350, 200, Type::wall));
    fifthRow.push_back(new GameTile(400, 200, Type::grass));
    fifthRow.push_back(new GameTile(450, 200, Type::wall));
    fifthRow.push_back(new GameTile(500, 200, Type::wall));
    fifthRow.push_back(new GameTile(550, 200, Type::wall));
    fifthRow.push_back(new GameTile(600, 200, Type::wall));
    fifthRow.push_back(new GameTile(650, 200, Type::wall));
    fifthRow.push_back(new GameTile(700, 200, Type::grass));
    fifthRow.push_back(new GameTile(750, 200, Type::wall));
    otrisovka.tiles.push_back(fifthRow);

    std::vector<GameTile *> sixthRow;
    sixthRow.push_back(new GameTile(0, 250, Type::wall));
    sixthRow.push_back(new GameTile(50, 250, Type::grass));
    sixthRow.push_back(new GameTile(100, 250, Type::wall));
    sixthRow.push_back(new GameTile(150, 250, Type::grass));
    sixthRow.push_back(new GameTile(200, 250, Type::grass));
    sixthRow.push_back(new GameTile(250, 250, Type::wall));
    sixthRow.push_back(new GameTile(300, 250, Type::wall));
    sixthRow.push_back(new GameTile(350, 250, Type::wall));
    sixthRow.push_back(new GameTile(400, 250, Type::grass));
    sixthRow.push_back(new GameTile(450, 250, Type::grass));
    sixthRow.push_back(new GameTile(500, 250, Type::grass));
    sixthRow.push_back(new GameTile(550, 250, Type::grass));
    sixthRow.push_back(new GameTile(600, 250, Type::grass));
    sixthRow.push_back(new GameTile(650, 250, Type::wall));
    sixthRow.push_back(new GameTile(700, 250, Type::grass));
    sixthRow.push_back(new GameTile(750, 250, Type::wall));
    otrisovka.tiles.push_back(sixthRow);

    std::vector<GameTile *> seventhRow;
    seventhRow.push_back(new GameTile(0, 300, Type::wall));
    seventhRow.push_back(new GameTile(50, 300, Type::grass));
    seventhRow.push_back(new GameTile(100, 300, Type::wall));
    seventhRow.push_back(new GameTile(150, 300, Type::grass));
    seventhRow.push_back(new GameTile(200, 300, Type::grass));
    seventhRow.push_back(new GameTile(250, 300, Type::grass));
    seventhRow.push_back(new GameTile(300, 300, Type::grass));
    seventhRow.push_back(new GameTile(350, 300, Type::wall));
    seventhRow.push_back(new GameTile(400, 300, Type::wall));
    seventhRow.push_back(new GameTile(450, 300, Type::wall));
    seventhRow.push_back(new GameTile(500, 300, Type::wall));
    seventhRow.push_back(new GameTile(550, 300, Type::wall));
    seventhRow.push_back(new GameTile(600, 300, Type::grass));
    seventhRow.push_back(new GameTile(650, 300, Type::wall));
    seventhRow.push_back(new GameTile(700, 300, Type::grass));
    seventhRow.push_back(new GameTile(750, 300, Type::wall));
    otrisovka.tiles.push_back(seventhRow);

    std::vector<GameTile *> eighthRow;
    eighthRow.push_back(new GameTile(0, 350, Type::wall));
    eighthRow.push_back(new GameTile(50, 350, Type::grass));
    eighthRow.push_back(new GameTile(100, 350, Type::wall));
    eighthRow.push_back(new GameTile(150, 350, Type::grass));
    eighthRow.push_back(new GameTile(200, 350, Type::grass));
    eighthRow.push_back(new GameTile(250, 350, Type::grass));
    eighthRow.push_back(new GameTile(300, 350, Type::grass));
    eighthRow.push_back(new GameTile(350, 350, Type::wall));
    eighthRow.push_back(new GameTile(400, 350, Type::grass));
    eighthRow.push_back(new GameTile(450, 350, Type::grass));
    eighthRow.push_back(new GameTile(500, 350, Type::grass));
    eighthRow.push_back(new GameTile(550, 350, Type::grass));
    eighthRow.push_back(new GameTile(600, 350, Type::grass));
    eighthRow.push_back(new GameTile(650, 350, Type::wall));
    eighthRow.push_back(new GameTile(700, 350, Type::grass));
    eighthRow.push_back(new GameTile(750, 350, Type::wall));
    otrisovka.tiles.push_back(eighthRow);

    std::vector<GameTile *> ninthRow;
    ninthRow.push_back(new GameTile(0, 400, Type::wall));
    ninthRow.push_back(new GameTile(50, 400, Type::grass));
    ninthRow.push_back(new GameTile(100, 400, Type::wall));
    ninthRow.push_back(new GameTile(150, 400, Type::grass));
    ninthRow.push_back(new GameTile(200, 400, Type::wall));
    ninthRow.push_back(new GameTile(250, 400, Type::wall));
    ninthRow.push_back(new GameTile(300, 400, Type::grass));
    ninthRow.push_back(new GameTile(350, 400, Type::wall));
    ninthRow.push_back(new GameTile(400, 400, Type::grass));
    ninthRow.push_back(new GameTile(450, 400, Type::wall));
    ninthRow.push_back(new GameTile(500, 400, Type::wall));
    ninthRow.push_back(new GameTile(550, 400, Type::wall));
    ninthRow.push_back(new GameTile(600, 400, Type::wall));
    ninthRow.push_back(new GameTile(650, 400, Type::wall));
    ninthRow.push_back(new GameTile(700, 400, Type::grass));
    ninthRow.push_back(new GameTile(750, 400, Type::wall));
    otrisovka.tiles.push_back(ninthRow);

    std::vector<GameTile *> tenthRow;
    tenthRow.push_back(new GameTile(0, 450, Type::wall));
    tenthRow.push_back(new GameTile(50, 450, Type::grass));
    tenthRow.push_back(new GameTile(100, 450, Type::grass));
    tenthRow.push_back(new GameTile(150, 450, Type::grass));
    tenthRow.push_back(new GameTile(200, 450, Type::wall));
    tenthRow.push_back(new GameTile(250, 450, Type::wall));
    tenthRow.push_back(new GameTile(300, 450, Type::grass));
    tenthRow.push_back(new GameTile(350, 450, Type::wall));
    tenthRow.push_back(new GameTile(400, 450, Type::grass));
    tenthRow.push_back(new GameTile(450, 450, Type::grass));
    tenthRow.push_back(new GameTile(500, 450, Type::grass));
    tenthRow.push_back(new GameTile(550, 450, Type::grass));
    tenthRow.push_back(new GameTile(600, 450, Type::grass));
    tenthRow.push_back(new GameTile(650, 450, Type::grass));
    tenthRow.push_back(new GameTile(700, 450, Type::grass));
    tenthRow.push_back(new GameTile(750, 450, Type::wall));
    otrisovka.tiles.push_back(tenthRow);

    std::vector<GameTile *> eleventhRow;
    eleventhRow.push_back(new GameTile(0, 500, Type::wall));
    eleventhRow.push_back(new GameTile(50, 500, Type::grass));
    eleventhRow.push_back(new GameTile(100, 500, Type::grass));
    eleventhRow.push_back(new GameTile(150, 500, Type::grass));
    eleventhRow.push_back(new GameTile(200, 500, Type::wall));
    eleventhRow.push_back(new GameTile(250, 500, Type::wall));
    eleventhRow.push_back(new GameTile(300, 500, Type::grass));
    eleventhRow.push_back(new GameTile(350, 500, Type::wall));
    eleventhRow.push_back(new GameTile(400, 500, Type::wall));
    eleventhRow.push_back(new GameTile(450, 500, Type::wall));
    eleventhRow.push_back(new GameTile(500, 500, Type::wall));
    eleventhRow.push_back(new GameTile(550, 500, Type::grass));
    eleventhRow.push_back(new GameTile(600, 500, Type::wall));
    eleventhRow.push_back(new GameTile(650, 500, Type::grass));
    eleventhRow.push_back(new GameTile(700, 500, Type::wall));
    eleventhRow.push_back(new GameTile(750, 500, Type::wall));
    otrisovka.tiles.push_back(eleventhRow);

    std::vector<GameTile *> twelfthRow;
    twelfthRow.push_back(new GameTile(0, 550, Type::wall));
    twelfthRow.push_back(new GameTile(50, 550, Type::grass));
    twelfthRow.push_back(new GameTile(100, 550, Type::wall));
    twelfthRow.push_back(new GameTile(150, 550, Type::wall));
    twelfthRow.push_back(new GameTile(200, 550, Type::wall));
    twelfthRow.push_back(new GameTile(250, 550, Type::wall));
    twelfthRow.push_back(new GameTile(300, 550, Type::grass));
    twelfthRow.push_back(new GameTile(350, 550, Type::wall));
    twelfthRow.push_back(new GameTile(400, 550, Type::grass));
    twelfthRow.push_back(new GameTile(450, 550, Type::grass));
    twelfthRow.push_back(new GameTile(500, 550, Type::grass));
    twelfthRow.push_back(new GameTile(550, 550, Type::grass));
    twelfthRow.push_back(new GameTile(600, 550, Type::wall));
    twelfthRow.push_back(new GameTile(650, 550, Type::grass));
    twelfthRow.push_back(new GameTile(700, 550, Type::wall));
    twelfthRow.push_back(new GameTile(750, 550, Type::wall));
    otrisovka.tiles.push_back(twelfthRow);

    std::vector<GameTile *> thirteenthRow;
    thirteenthRow.push_back(new GameTile(0, 600, Type::wall));
    thirteenthRow.push_back(new GameTile(50, 600, Type::grass));
    thirteenthRow.push_back(new GameTile(100, 600, Type::wall));
    thirteenthRow.push_back(new GameTile(150, 600, Type::grass));
    thirteenthRow.push_back(new GameTile(200, 600, Type::wall));
    thirteenthRow.push_back(new GameTile(250, 600, Type::wall));
    thirteenthRow.push_back(new GameTile(300, 600, Type::grass));
    thirteenthRow.push_back(new GameTile(350, 600, Type::wall));
    thirteenthRow.push_back(new GameTile(400, 600, Type::grass));
    thirteenthRow.push_back(new GameTile(450, 600, Type::wall));
    thirteenthRow.push_back(new GameTile(500, 600, Type::wall));
    thirteenthRow.push_back(new GameTile(550, 600, Type::wall));
    thirteenthRow.push_back(new GameTile(600, 600, Type::wall));
    thirteenthRow.push_back(new GameTile(650, 600, Type::grass));
    thirteenthRow.push_back(new GameTile(700, 600, Type::wall));
    thirteenthRow.push_back(new GameTile(750, 600, Type::wall));
    otrisovka.tiles.push_back(thirteenthRow);

    std::vector<GameTile *> fourteenthRow;
    fourteenthRow.push_back(new GameTile(0, 650, Type::wall));
    fourteenthRow.push_back(new GameTile(50, 650, Type::grass));
    fourteenthRow.push_back(new GameTile(100, 650, Type::wall));
    fourteenthRow.push_back(new GameTile(150, 650, Type::grass));
    fourteenthRow.push_back(new GameTile(200, 650, Type::grass));
    fourteenthRow.push_back(new GameTile(250, 650, Type::grass));
    fourteenthRow.push_back(new GameTile(300, 650, Type::grass));
    fourteenthRow.push_back(new GameTile(350, 650, Type::wall));
    fourteenthRow.push_back(new GameTile(400, 650, Type::grass));
    fourteenthRow.push_back(new GameTile(450, 650, Type::grass));
    fourteenthRow.push_back(new GameTile(500, 650, Type::grass));
    fourteenthRow.push_back(new GameTile(550, 650, Type::grass));
    fourteenthRow.push_back(new GameTile(600, 650, Type::wall));
    fourteenthRow.push_back(new GameTile(650, 650, Type::grass));
    fourteenthRow.push_back(new GameTile(700, 650, Type::wall));
    fourteenthRow.push_back(new GameTile(750, 650, Type::wall));
    otrisovka.tiles.push_back(fourteenthRow);

    std::vector<GameTile *> fifteenthRow;
    fifteenthRow.push_back(new GameTile(0, 700, Type::wall));
    fifteenthRow.push_back(new GameTile(50, 700, Type::grass));
    fifteenthRow.push_back(new GameTile(100, 700, Type::wall));
    fifteenthRow.push_back(new GameTile(150, 700, Type::grass));
    fifteenthRow.push_back(new GameTile(200, 700, Type::grass));
    fifteenthRow.push_back(new GameTile(250, 700, Type::grass));
    fifteenthRow.push_back(new GameTile(300, 700, Type::grass));
    fifteenthRow.push_back(new GameTile(350, 700, Type::wall));
    fifteenthRow.push_back(new GameTile(400, 700, Type::grass));
    fifteenthRow.push_back(new GameTile(450, 700, Type::grass));
    fifteenthRow.push_back(new GameTile(500, 700, Type::grass));
    fifteenthRow.push_back(new GameTile(550, 700, Type::grass));
    fifteenthRow.push_back(new GameTile(600, 700, Type::wall));
    fifteenthRow.push_back(new GameTile(650, 700, Type::grass));
    fifteenthRow.push_back(new GameTile(700, 700, Type::door));
    fifteenthRow.push_back(new GameTile(750, 700, Type::wall));
    otrisovka.tiles.push_back(fifteenthRow);

    std::vector<GameTile *> sixteenthRow;
    sixteenthRow.push_back(new GameTile(0, 750, Type::wall));
    sixteenthRow.push_back(new GameTile(50, 750, Type::wall));
    sixteenthRow.push_back(new GameTile(100, 750, Type::wall));
    sixteenthRow.push_back(new GameTile(150, 750, Type::wall));
    sixteenthRow.push_back(new GameTile(200, 750, Type::wall));
    sixteenthRow.push_back(new GameTile(250, 750, Type::wall));
    sixteenthRow.push_back(new GameTile(300, 750, Type::wall));
    sixteenthRow.push_back(new GameTile(350, 750, Type::wall));
    sixteenthRow.push_back(new GameTile(400, 750, Type::wall));
    sixteenthRow.push_back(new GameTile(450, 750, Type::wall));
    sixteenthRow.push_back(new GameTile(500, 750, Type::wall));
    sixteenthRow.push_back(new GameTile(550, 750, Type::wall));
    sixteenthRow.push_back(new GameTile(600, 750, Type::wall));
    sixteenthRow.push_back(new GameTile(650, 750, Type::wall));
    sixteenthRow.push_back(new GameTile(700, 750, Type::wall));
    sixteenthRow.push_back(new GameTile(750, 750, Type::wall));
    otrisovka.tiles.push_back(sixteenthRow);
}