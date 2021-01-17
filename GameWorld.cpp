#include "GameWorld.h"


using namespace sf;

GameWorld::GameWorld() {
    gridLength = 8;
    Otrisovka otrisovka;
    player = Knight(gridLength - 1, gridLength - 1);
    Zombie zombie_1(0, 2);
    Zombie zombie_2(6, 0);
    Zombie zombie_3(2, 7);
    zombiesList.push_back(zombie_1);
    zombiesList.push_back(zombie_2);
    zombiesList.push_back(zombie_3);
    setInitialState();
    setUpTiles(otrisovka);

    sf::Clock clock;
    float CurrentFrame = 0;//хранит текущий кадр
    this->window = new sf::RenderWindow(sf::VideoMode(400, 400), "Roguelike", sf::Style::Titlebar | sf::Style::Close);
    while (window->isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
        clock.restart(); //перезагружает время
        time /= 600; //скорость игры
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
        for (auto i : zombiesList) {
            window->draw(otrisovka.draw(i.type, i.GetPosition()));
        }
        ///Отрисовка главного фраера
        window->draw(otrisovka.draw(player.type, player.GetPosition()));

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

        player.update(time,otrisovka);


        window->display();
    }
}

GameWorld::~GameWorld() {
    delete this->window;
}

void GameWorld::setInitialState() {
    exitPosition.x = 1;
    exitPosition.y = 0;
    playerPosition.x = player.GetPosition().x;
    playerPosition.y = player.GetPosition().y;
    setUpEnemyPositions();
}

void GameWorld::setUpEnemyPositions() {
    enemyPositions.clear();
    for (auto &i : zombiesList) {
        enemyPositions.push_back(i.GetPosition());
    }
}

void GameWorld::setUpTiles(Otrisovka& otrisovka) {
    otrisovka.tiles.clear();
    std::vector<GameTile *> firstRow;
    firstRow.push_back(new GameTile(0, 0, Type::wall));
    firstRow.push_back(new GameTile(50, 0, Type::door));
    firstRow.push_back(new GameTile(100, 0, Type::wall));
    firstRow.push_back(new GameTile(150, 0, Type::wall));
    firstRow.push_back(new GameTile(200, 0, Type::wall));
    firstRow.push_back(new GameTile(250, 0, Type::wall));
    firstRow.push_back(new GameTile(300, 0, Type::grass));
    firstRow.push_back(new GameTile(350, 0, Type::wall));
    otrisovka.tiles.push_back(firstRow);

    std::vector<GameTile *> secondRow;
    secondRow.push_back(new GameTile(0, 50, Type::wall));
    secondRow.push_back(new GameTile(50, 50, Type::grass));
    secondRow.push_back(new GameTile(100, 50, Type::grass));
    secondRow.push_back(new GameTile(150, 50, Type::grass));
    secondRow.push_back(new GameTile(200, 50, Type::grass));
    secondRow.push_back(new GameTile(250, 50, Type::grass));
    secondRow.push_back(new GameTile(300, 50, Type::grass));
    secondRow.push_back(new GameTile(350, 50, Type::wall));
    otrisovka.tiles.push_back(secondRow);

    std::vector<GameTile *> thirdRow;
    thirdRow.push_back(new GameTile(0, 100, Type::grass));
    thirdRow.push_back(new GameTile(50, 100, Type::grass));
    thirdRow.push_back(new GameTile(100, 100, Type::grass));
    thirdRow.push_back(new GameTile(150, 100, Type::wall));
    thirdRow.push_back(new GameTile(200, 100, Type::grass));
    thirdRow.push_back(new GameTile(250, 100, Type::grass));
    thirdRow.push_back(new GameTile(300, 100, Type::wall));
    thirdRow.push_back(new GameTile(350, 100, Type::wall));
    otrisovka.tiles.push_back(thirdRow);

    std::vector<GameTile *> fourthRow;
    fourthRow.push_back(new GameTile(0, 150, Type::wall));
    fourthRow.push_back(new GameTile(50, 150, Type::grass));
    fourthRow.push_back(new GameTile(100, 150, Type::grass));
    fourthRow.push_back(new GameTile(150, 150, Type::wall));
    fourthRow.push_back(new GameTile(200, 150, Type::grass));
    fourthRow.push_back(new GameTile(250, 150, Type::grass));
    fourthRow.push_back(new GameTile(300, 150, Type::grass));
    fourthRow.push_back(new GameTile(350, 150, Type::wall));
    otrisovka.tiles.push_back(fourthRow);

    std::vector<GameTile *> fifthRow;
    fifthRow.push_back(new GameTile(0, 200, Type::wall));
    fifthRow.push_back(new GameTile(50, 200, Type::grass));
    fifthRow.push_back(new GameTile(100, 200, Type::grass));
    fifthRow.push_back(new GameTile(150, 200, Type::wall));
    fifthRow.push_back(new GameTile(200, 200, Type::wall));
    fifthRow.push_back(new GameTile(250, 200, Type::grass));
    fifthRow.push_back(new GameTile(300, 200, Type::grass));
    fifthRow.push_back(new GameTile(350, 200, Type::grass));
    otrisovka.tiles.push_back(fifthRow);

    std::vector<GameTile *> sixthRow;
    sixthRow.push_back(new GameTile(0, 250, Type::grass));
    sixthRow.push_back(new GameTile(50, 250, Type::grass));
    sixthRow.push_back(new GameTile(100, 250, Type::grass));
    sixthRow.push_back(new GameTile(150, 250, Type::grass));
    sixthRow.push_back(new GameTile(200, 250, Type::wall));
    sixthRow.push_back(new GameTile(250, 250, Type::grass));
    sixthRow.push_back(new GameTile(300, 250, Type::grass));
    sixthRow.push_back(new GameTile(350, 250, Type::wall));
    otrisovka.tiles.push_back(sixthRow);

    std::vector<GameTile *> seventhRow;
    seventhRow.push_back(new GameTile(0, 300, Type::wall));
    seventhRow.push_back(new GameTile(50, 300, Type::wall));
    seventhRow.push_back(new GameTile(100, 300, Type::grass));
    seventhRow.push_back(new GameTile(150, 300, Type::grass));
    seventhRow.push_back(new GameTile(200, 300, Type::grass));
    seventhRow.push_back(new GameTile(250, 300, Type::grass));
    seventhRow.push_back(new GameTile(300, 300, Type::wall));
    seventhRow.push_back(new GameTile(350, 300, Type::wall));
    otrisovka.tiles.push_back(seventhRow);

    std::vector<GameTile *> eighthRow;
    eighthRow.push_back(new GameTile(0, 350, Type::wall));
    eighthRow.push_back(new GameTile(50, 350, Type::wall));
    eighthRow.push_back(new GameTile(100, 350, Type::grass));
    eighthRow.push_back(new GameTile(150, 350, Type::wall));
    eighthRow.push_back(new GameTile(200, 350, Type::wall));
    eighthRow.push_back(new GameTile(250, 350, Type::grass));
    eighthRow.push_back(new GameTile(300, 350, Type::grass));
    eighthRow.push_back(new GameTile(350, 350, Type::grass));
    otrisovka.tiles.push_back(eighthRow);
}