#include <iostream>
#include "GameWorld.h"



using namespace sf;

GameWorld::GameWorld() {
    gridLength = 16;
    Otrisovka otrisovka;
    player = Knight(1,14);
    enemiesList.push_back(std::make_unique<Zombie>(11,2));
    enemiesList.push_back(std::make_unique<Zombie>(11,3));
    enemiesList.push_back(std::make_unique<Zombie>(2,10));
    enemiesList.push_back(std::make_unique<Zombie>(6,14));
    enemiesList.push_back(std::make_unique<Dragon>(2,1));
    enemiesList.push_back(std::make_unique<Dragon>(3,13));
    enemiesList.push_back(std::make_unique<Dragon>(8,14));
    itemsList.emplace_back(Type::chest,3,14,"C:/Users/mrnos/CLionProjects/roguelike/imgs/chest.png" );
    itemsList.emplace_back(Type::chest,10,14,"C:/Users/mrnos/CLionProjects/roguelike/imgs/chest.png" );
    itemsList.emplace_back( Type::chest,14,3,"C:/Users/mrnos/CLionProjects/roguelike/imgs/chest.png" );
    itemsList.emplace_back( Type::aid,2,2 ,"C:/Users/mrnos/CLionProjects/roguelike/imgs/heart.png");
    itemsList.emplace_back( Type::aid,3,12,"C:/Users/mrnos/CLionProjects/roguelike/imgs/heart.png" );
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
                window->draw(otrisovka.draw(tiles[i][j]->type, tiles[i][j]->position));
            }
        }
        ///Отрисовка бомжей
        for (auto& i : enemiesList) {
            window->draw(otrisovka.draw(i->type, i->GetPosition()));
        }

        ///Отрисовка приколюх
        for (auto& i : itemsList) {
            window->draw(otrisovka.draw(i.type,i.GetPosition()));
        }

        ///Отрисовка главного фраера
        window->draw(otrisovka.draw(player.type, player.GetPosition()));

        HeartFrame += 0.008 * time;
        if (HeartFrame > 13)
            HeartFrame -= 13;
        if (!itemsList[3].isPicked())
            otrisovka.sprites[Type::aid].setTextureRect(IntRect(22 * int(HeartFrame), 0, 25, 25));
        if (!itemsList[4].isPicked())
            otrisovka.sprites[Type::aid].setTextureRect(IntRect(22 * int(HeartFrame), 0, 25, 25));

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
        update(time,player,otrisovka);
        for (int i=0 ; i< enemiesList.size(); ++i){
            update(time,*enemiesList[i],otrisovka);
        }
        window->display();
    }
}

GameWorld::~GameWorld() {
    delete this->window;
}

void GameWorld::interaction_with_the_map(Knight& player, Otrisovka& otrisovka) {
    for (int i = player.y / 50; i < (player.y+player.height) /50; i++)
    {
        for (int j = player.x / 50; j < (player.x+40)/50 ; j++)
        {
            if (tiles[i][j]->type ==Type::wall) {
                if (player.dy > 0)
                {
                    player.y = i * 50 -player.height;
                }
                if (player.dy < 0) {
                    player.y = i * 50 +50;
                }
                if (player.dx > 0) {
                    player.x = j * 50 - player.width;
                }
                if (player.dx < 0) {
                    player.x = j * 50 + 50;
                }
            }
            if (player.GetPosition().x == itemsList[0].GetPosition().x && player.GetPosition().y == itemsList[0].GetPosition().y+10)
            {
                itemsList[0].type = Type::opened_chest;
            }
            if (player.GetPosition().x == itemsList[1].GetPosition().x && player.GetPosition().y == itemsList[1].GetPosition().y+10)
            {
                itemsList[1].type = Type::opened_chest;
            }
            if (player.GetPosition() == itemsList[2].GetPosition())
            {
                itemsList[2].type = Type::opened_chest;
            }
            if (player.GetPosition().x == itemsList[3].GetPosition().x+10 && player.GetPosition().y == itemsList[3].GetPosition().y+10 &&
                !itemsList[3].isPicked())
            {
                if (player.GetHealth() < 100){
                    if (player.GetHealth() > 70) {
                        player.set_100_hp();
                        itemsList[3].type = Type::took_aid;
                        itemsList[3].pick();
                    }
                    else{
                        player.addHP(30);
                        itemsList[3].type = Type::took_aid;
                        itemsList[3].pick();
                    }
                }
            }
            if (player.GetPosition().x == itemsList[4].GetPosition().x+10 && player.GetPosition().y == itemsList[4].GetPosition().y+10 &&
                !itemsList[4].isPicked())
            {
                if (player.GetHealth() < 100){
                    if (player.GetHealth() > 70) {
                        player.set_100_hp();
                        itemsList[4].type = Type::took_aid;
                        itemsList[4].pick();
                    }
                    else{
                        player.addHP(30);
                        itemsList[4].type = Type::took_aid;
                        itemsList[4].pick();
                    }
                }

            }

        }
    }
}

void GameWorld::update(float time, Knight& player, Otrisovka& otrisovka) {
    switch (player.dir)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
    {
        case 0:
            player.dx = player.speed;
            player.dy = 0;
            break;//по иксу задаем положительную скорость, по игреку зануляем. получаем, что персонаж идет только вправо
        case 1:
            player.dx = -player.speed;
            player.dy = 0;
            break;//по иксу задаем отрицательную скорость, по игреку зануляем. получается, что персонаж идет только влево
        case 2:
            player.dx = 0;
            player.dy = player.speed;
            break;//по иксу задаем нулевое значение, по игреку положительное. получается, что персонаж идет только вниз
        case 3:
            player.dx = 0;
            player.dy = -player.speed;
            break;//по иксу задаем нулевое значение, по игреку отрицательное. получается, что персонаж идет только вверх
    }
    player.x += player.dx * time;//ускорение на время получаем смещение координат и как следствие движение
    player.y += player.dy * time;
    player.speed = 0;//зануляем скорость, чтобы персонаж остановился.
    player.SetPosition(player.x,player.y);
    interaction_with_the_map(player,otrisovka);
}

void GameWorld::interaction_with_the_map(Character& enemy, Otrisovka& otrisovka) {
    for (int i = enemy.y / 50; i < (enemy.y+enemy.height) /50; i++) {
        for (int j = enemy.x / 50; j < (enemy.x + enemy.width) / 50; j++) {
            if (tiles[i][j]->type == Type::wall) {
                if (enemy.dx > 0) {
                    enemy.x = j * 50 - enemy.width;
                    enemy.dx = -0.1;
                    break;
                }
                if (enemy.dx < 0) {
                    enemy.x = j * 50 + 50;
                    enemy.dx = 0.1;
                    break;
                }
            }
        }
    }
}

void GameWorld::update(float time, Character& enemy, Otrisovka& otrisovka) {
    enemy.x += enemy.dx * time;
    enemy.SetPosition(enemy.x,enemy.y);
    interaction_with_the_map(enemy,otrisovka);
    if (enemy.GetHealth() <= 0) {
        enemy.life = false;
    }
}

void GameWorld::setUpTiles(Otrisovka& otrisovka) {
    tiles.clear();
    std::vector<std::shared_ptr<GameTile>> firstRow;
    firstRow.push_back(std::make_shared<GameTile>(0, 0, Type::wall));
    firstRow.push_back(std::make_shared<GameTile>(50, 0, Type::wall));
    firstRow.push_back(std::make_shared<GameTile>(100, 0, Type::wall));
    firstRow.push_back(std::make_shared<GameTile>(150, 0, Type::wall));
    firstRow.push_back(std::make_shared<GameTile>(200, 0, Type::wall));
    firstRow.push_back(std::make_shared<GameTile>(250, 0, Type::wall));
    firstRow.push_back(std::make_shared<GameTile>(300, 0, Type::wall));
    firstRow.push_back(std::make_shared<GameTile>(350, 0, Type::wall));
    firstRow.push_back(std::make_shared<GameTile>(400, 0, Type::wall));
    firstRow.push_back(std::make_shared<GameTile>(450, 0, Type::wall));
    firstRow.push_back(std::make_shared<GameTile>(500, 0, Type::wall));
    firstRow.push_back(std::make_shared<GameTile>(550, 0, Type::wall));
    firstRow.push_back(std::make_shared<GameTile>(600, 0, Type::wall));
    firstRow.push_back(std::make_shared<GameTile>(650, 0, Type::wall));
    firstRow.push_back(std::make_shared<GameTile>(700, 0, Type::wall));
    firstRow.push_back(std::make_shared<GameTile>(750, 0, Type::wall));
    tiles.push_back(firstRow);

    std::vector<std::shared_ptr<GameTile>> secondRow;
    secondRow.push_back(std::make_shared<GameTile>(0, 50, Type::wall));
    secondRow.push_back(std::make_shared<GameTile>(50, 50, Type::grass));
    secondRow.push_back(std::make_shared<GameTile>(100, 50, Type::grass));
    secondRow.push_back(std::make_shared<GameTile>(150, 50, Type::wall));
    secondRow.push_back(std::make_shared<GameTile>(200, 50, Type::wall));
    secondRow.push_back(std::make_shared<GameTile>(250, 50, Type::wall));
    secondRow.push_back(std::make_shared<GameTile>(300, 50, Type::wall));
    secondRow.push_back(std::make_shared<GameTile>(350, 50, Type::wall));
    secondRow.push_back(std::make_shared<GameTile>(400, 50, Type::wall));
    secondRow.push_back(std::make_shared<GameTile>(450, 50, Type::wall));
    secondRow.push_back(std::make_shared<GameTile>(500, 50, Type::wall));
    secondRow.push_back(std::make_shared<GameTile>(550, 50, Type::wall));
    secondRow.push_back(std::make_shared<GameTile>(600, 50, Type::wall));
    secondRow.push_back(std::make_shared<GameTile>(650, 50, Type::wall));
    secondRow.push_back(std::make_shared<GameTile>(700, 50, Type::wall));
    secondRow.push_back(std::make_shared<GameTile>(750, 50, Type::wall));
    tiles.push_back(secondRow);

    std::vector<std::shared_ptr<GameTile>> thirdRow;
    thirdRow.push_back(std::make_shared<GameTile>(0, 100, Type::wall));
    thirdRow.push_back(std::make_shared<GameTile>(50, 100, Type::grass));
    thirdRow.push_back(std::make_shared<GameTile>(100, 100, Type::grass));
    thirdRow.push_back(std::make_shared<GameTile>(150, 100, Type::wall));
    thirdRow.push_back(std::make_shared<GameTile>(200, 100, Type::grass));
    thirdRow.push_back(std::make_shared<GameTile>(250, 100, Type::grass));
    thirdRow.push_back(std::make_shared<GameTile>(300, 100, Type::grass));
    thirdRow.push_back(std::make_shared<GameTile>(350, 100, Type::grass));
    thirdRow.push_back(std::make_shared<GameTile>(400, 100, Type::grass));
    thirdRow.push_back(std::make_shared<GameTile>(450, 100, Type::grass));
    thirdRow.push_back(std::make_shared<GameTile>(500, 100, Type::grass));
    thirdRow.push_back(std::make_shared<GameTile>(550, 100, Type::grass));
    thirdRow.push_back(std::make_shared<GameTile>(600, 100, Type::wall));
    thirdRow.push_back(std::make_shared<GameTile>(650, 100, Type::wall));
    thirdRow.push_back(std::make_shared<GameTile>(700, 100, Type::wall));
    thirdRow.push_back(std::make_shared<GameTile>(750, 100, Type::wall));
    tiles.push_back(thirdRow);

    std::vector<std::shared_ptr<GameTile>> fourthRow;
    fourthRow.push_back(std::make_shared<GameTile>(0, 150, Type::wall));
    fourthRow.push_back(std::make_shared<GameTile>(50, 150, Type::grass));
    fourthRow.push_back(std::make_shared<GameTile>(100, 150, Type::wall));
    fourthRow.push_back(std::make_shared<GameTile>(150, 150, Type::wall));
    fourthRow.push_back(std::make_shared<GameTile>(200, 150, Type::grass));
    fourthRow.push_back(std::make_shared<GameTile>(250, 150, Type::grass));
    fourthRow.push_back(std::make_shared<GameTile>(300, 150, Type::grass));
    fourthRow.push_back(std::make_shared<GameTile>(350, 150, Type::grass));
    fourthRow.push_back(std::make_shared<GameTile>(400, 150, Type::grass));
    fourthRow.push_back(std::make_shared<GameTile>(450, 150, Type::grass));
    fourthRow.push_back(std::make_shared<GameTile>(500, 150, Type::grass));
    fourthRow.push_back(std::make_shared<GameTile>(550, 150, Type::grass));
    fourthRow.push_back(std::make_shared<GameTile>(600, 150, Type::wall));
    fourthRow.push_back(std::make_shared<GameTile>(650, 150, Type::wall));
    fourthRow.push_back(std::make_shared<GameTile>(700, 150, Type::grass));
    fourthRow.push_back(std::make_shared<GameTile>(750, 150, Type::wall));
    tiles.push_back(fourthRow);

    std::vector<std::shared_ptr<GameTile>> fifthRow;
    fifthRow.push_back(std::make_shared<GameTile>(0, 200, Type::wall));
    fifthRow.push_back(std::make_shared<GameTile>(50, 200, Type::grass));
    fifthRow.push_back(std::make_shared<GameTile>(100, 200, Type::wall));
    fifthRow.push_back(std::make_shared<GameTile>(150, 200, Type::grass));
    fifthRow.push_back(std::make_shared<GameTile>(200, 200, Type::grass));
    fifthRow.push_back(std::make_shared<GameTile>(250, 200, Type::wall));
    fifthRow.push_back(std::make_shared<GameTile>(300, 200, Type::wall));
    fifthRow.push_back(std::make_shared<GameTile>(350, 200, Type::wall));
    fifthRow.push_back(std::make_shared<GameTile>(400, 200, Type::grass));
    fifthRow.push_back(std::make_shared<GameTile>(450, 200, Type::wall));
    fifthRow.push_back(std::make_shared<GameTile>(500, 200, Type::wall));
    fifthRow.push_back(std::make_shared<GameTile>(550, 200, Type::wall));
    fifthRow.push_back(std::make_shared<GameTile>(600, 200, Type::wall));
    fifthRow.push_back(std::make_shared<GameTile>(650, 200, Type::wall));
    fifthRow.push_back(std::make_shared<GameTile>(700, 200, Type::grass));
    fifthRow.push_back(std::make_shared<GameTile>(750, 200, Type::wall));
    tiles.push_back(fifthRow);

    std::vector<std::shared_ptr<GameTile>> sixthRow;
    sixthRow.push_back(std::make_shared<GameTile>(0, 250, Type::wall));
    sixthRow.push_back(std::make_shared<GameTile>(50, 250, Type::grass));
    sixthRow.push_back(std::make_shared<GameTile>(100, 250, Type::wall));
    sixthRow.push_back(std::make_shared<GameTile>(150, 250, Type::grass));
    sixthRow.push_back(std::make_shared<GameTile>(200, 250, Type::grass));
    sixthRow.push_back(std::make_shared<GameTile>(250, 250, Type::wall));
    sixthRow.push_back(std::make_shared<GameTile>(300, 250, Type::wall));
    sixthRow.push_back(std::make_shared<GameTile>(350, 250, Type::wall));
    sixthRow.push_back(std::make_shared<GameTile>(400, 250, Type::grass));
    sixthRow.push_back(std::make_shared<GameTile>(450, 250, Type::grass));
    sixthRow.push_back(std::make_shared<GameTile>(500, 250, Type::grass));
    sixthRow.push_back(std::make_shared<GameTile>(550, 250, Type::grass));
    sixthRow.push_back(std::make_shared<GameTile>(600, 250, Type::grass));
    sixthRow.push_back(std::make_shared<GameTile>(650, 250, Type::wall));
    sixthRow.push_back(std::make_shared<GameTile>(700, 250, Type::grass));
    sixthRow.push_back(std::make_shared<GameTile>(750, 250, Type::wall));
    tiles.push_back(sixthRow);

    std::vector<std::shared_ptr<GameTile>> seventhRow;
    seventhRow.push_back(std::make_shared<GameTile>(0, 300, Type::wall));
    seventhRow.push_back(std::make_shared<GameTile>(50, 300, Type::grass));
    seventhRow.push_back(std::make_shared<GameTile>(100, 300, Type::wall));
    seventhRow.push_back(std::make_shared<GameTile>(150, 300, Type::grass));
    seventhRow.push_back(std::make_shared<GameTile>(200, 300, Type::grass));
    seventhRow.push_back(std::make_shared<GameTile>(250, 300, Type::grass));
    seventhRow.push_back(std::make_shared<GameTile>(300, 300, Type::grass));
    seventhRow.push_back(std::make_shared<GameTile>(350, 300, Type::wall));
    seventhRow.push_back(std::make_shared<GameTile>(400, 300, Type::wall));
    seventhRow.push_back(std::make_shared<GameTile>(450, 300, Type::wall));
    seventhRow.push_back(std::make_shared<GameTile>(500, 300, Type::wall));
    seventhRow.push_back(std::make_shared<GameTile>(550, 300, Type::wall));
    seventhRow.push_back(std::make_shared<GameTile>(600, 300, Type::grass));
    seventhRow.push_back(std::make_shared<GameTile>(650, 300, Type::wall));
    seventhRow.push_back(std::make_shared<GameTile>(700, 300, Type::grass));
    seventhRow.push_back(std::make_shared<GameTile>(750, 300, Type::wall));
    tiles.push_back(seventhRow);

    std::vector<std::shared_ptr<GameTile>> eighthRow;
    eighthRow.push_back(std::make_shared<GameTile>(0, 350, Type::wall));
    eighthRow.push_back(std::make_shared<GameTile>(50, 350, Type::grass));
    eighthRow.push_back(std::make_shared<GameTile>(100, 350, Type::wall));
    eighthRow.push_back(std::make_shared<GameTile>(150, 350, Type::grass));
    eighthRow.push_back(std::make_shared<GameTile>(200, 350, Type::grass));
    eighthRow.push_back(std::make_shared<GameTile>(250, 350, Type::grass));
    eighthRow.push_back(std::make_shared<GameTile>(300, 350, Type::grass));
    eighthRow.push_back(std::make_shared<GameTile>(350, 350, Type::wall));
    eighthRow.push_back(std::make_shared<GameTile>(400, 350, Type::grass));
    eighthRow.push_back(std::make_shared<GameTile>(450, 350, Type::grass));
    eighthRow.push_back(std::make_shared<GameTile>(500, 350, Type::grass));
    eighthRow.push_back(std::make_shared<GameTile>(550, 350, Type::grass));
    eighthRow.push_back(std::make_shared<GameTile>(600, 350, Type::grass));
    eighthRow.push_back(std::make_shared<GameTile>(650, 350, Type::wall));
    eighthRow.push_back(std::make_shared<GameTile>(700, 350, Type::grass));
    eighthRow.push_back(std::make_shared<GameTile>(750, 350, Type::wall));
    tiles.push_back(eighthRow);

    std::vector<std::shared_ptr<GameTile>> ninthRow;
    ninthRow.push_back(std::make_shared<GameTile>(0, 400, Type::wall));
    ninthRow.push_back(std::make_shared<GameTile>(50, 400, Type::grass));
    ninthRow.push_back(std::make_shared<GameTile>(100, 400, Type::wall));
    ninthRow.push_back(std::make_shared<GameTile>(150, 400, Type::grass));
    ninthRow.push_back(std::make_shared<GameTile>(200, 400, Type::wall));
    ninthRow.push_back(std::make_shared<GameTile>(250, 400, Type::wall));
    ninthRow.push_back(std::make_shared<GameTile>(300, 400, Type::grass));
    ninthRow.push_back(std::make_shared<GameTile>(350, 400, Type::wall));
    ninthRow.push_back(std::make_shared<GameTile>(400, 400, Type::grass));
    ninthRow.push_back(std::make_shared<GameTile>(450, 400, Type::wall));
    ninthRow.push_back(std::make_shared<GameTile>(500, 400, Type::wall));
    ninthRow.push_back(std::make_shared<GameTile>(550, 400, Type::wall));
    ninthRow.push_back(std::make_shared<GameTile>(600, 400, Type::wall));
    ninthRow.push_back(std::make_shared<GameTile>(650, 400, Type::wall));
    ninthRow.push_back(std::make_shared<GameTile>(700, 400, Type::grass));
    ninthRow.push_back(std::make_shared<GameTile>(750, 400, Type::wall));
    tiles.push_back(ninthRow);

    std::vector<std::shared_ptr<GameTile>> tenthRow;
    tenthRow.push_back(std::make_shared<GameTile>(0, 450, Type::wall));
    tenthRow.push_back(std::make_shared<GameTile>(50, 450, Type::grass));
    tenthRow.push_back(std::make_shared<GameTile>(100, 450, Type::grass));
    tenthRow.push_back(std::make_shared<GameTile>(150, 450, Type::grass));
    tenthRow.push_back(std::make_shared<GameTile>(200, 450, Type::wall));
    tenthRow.push_back(std::make_shared<GameTile>(250, 450, Type::wall));
    tenthRow.push_back(std::make_shared<GameTile>(300, 450, Type::grass));
    tenthRow.push_back(std::make_shared<GameTile>(350, 450, Type::wall));
    tenthRow.push_back(std::make_shared<GameTile>(400, 450, Type::grass));
    tenthRow.push_back(std::make_shared<GameTile>(450, 450, Type::grass));
    tenthRow.push_back(std::make_shared<GameTile>(500, 450, Type::grass));
    tenthRow.push_back(std::make_shared<GameTile>(550, 450, Type::grass));
    tenthRow.push_back(std::make_shared<GameTile>(600, 450, Type::grass));
    tenthRow.push_back(std::make_shared<GameTile>(650, 450, Type::grass));
    tenthRow.push_back(std::make_shared<GameTile>(700, 450, Type::grass));
    tenthRow.push_back(std::make_shared<GameTile>(750, 450, Type::wall));
    tiles.push_back(tenthRow);

    std::vector<std::shared_ptr<GameTile>> eleventhRow;
    eleventhRow.push_back(std::make_shared<GameTile>(0, 500, Type::wall));
    eleventhRow.push_back(std::make_shared<GameTile>(50, 500, Type::grass));
    eleventhRow.push_back(std::make_shared<GameTile>(100, 500, Type::grass));
    eleventhRow.push_back(std::make_shared<GameTile>(150, 500, Type::grass));
    eleventhRow.push_back(std::make_shared<GameTile>(200, 500, Type::wall));
    eleventhRow.push_back(std::make_shared<GameTile>(250, 500, Type::wall));
    eleventhRow.push_back(std::make_shared<GameTile>(300, 500, Type::grass));
    eleventhRow.push_back(std::make_shared<GameTile>(350, 500, Type::wall));
    eleventhRow.push_back(std::make_shared<GameTile>(400, 500, Type::wall));
    eleventhRow.push_back(std::make_shared<GameTile>(450, 500, Type::wall));
    eleventhRow.push_back(std::make_shared<GameTile>(500, 500, Type::wall));
    eleventhRow.push_back(std::make_shared<GameTile>(550, 500, Type::grass));
    eleventhRow.push_back(std::make_shared<GameTile>(600, 500, Type::wall));
    eleventhRow.push_back(std::make_shared<GameTile>(650, 500, Type::grass));
    eleventhRow.push_back(std::make_shared<GameTile>(700, 500, Type::wall));
    eleventhRow.push_back(std::make_shared<GameTile>(750, 500, Type::wall));
    tiles.push_back(eleventhRow);

    std::vector<std::shared_ptr<GameTile>> twelfthRow;
    twelfthRow.push_back(std::make_shared<GameTile>(0, 550, Type::wall));
    twelfthRow.push_back(std::make_shared<GameTile>(50, 550, Type::grass));
    twelfthRow.push_back(std::make_shared<GameTile>(100, 550, Type::wall));
    twelfthRow.push_back(std::make_shared<GameTile>(150, 550, Type::wall));
    twelfthRow.push_back(std::make_shared<GameTile>(200, 550, Type::wall));
    twelfthRow.push_back(std::make_shared<GameTile>(250, 550, Type::wall));
    twelfthRow.push_back(std::make_shared<GameTile>(300, 550, Type::grass));
    twelfthRow.push_back(std::make_shared<GameTile>(350, 550, Type::wall));
    twelfthRow.push_back(std::make_shared<GameTile>(400, 550, Type::grass));
    twelfthRow.push_back(std::make_shared<GameTile>(450, 550, Type::grass));
    twelfthRow.push_back(std::make_shared<GameTile>(500, 550, Type::grass));
    twelfthRow.push_back(std::make_shared<GameTile>(550, 550, Type::grass));
    twelfthRow.push_back(std::make_shared<GameTile>(600, 550, Type::wall));
    twelfthRow.push_back(std::make_shared<GameTile>(650, 550, Type::grass));
    twelfthRow.push_back(std::make_shared<GameTile>(700, 550, Type::wall));
    twelfthRow.push_back(std::make_shared<GameTile>(750, 550, Type::wall));
    tiles.push_back(twelfthRow);

    std::vector<std::shared_ptr<GameTile>> thirteenthRow;
    thirteenthRow.push_back(std::make_shared<GameTile>(0, 600, Type::wall));
    thirteenthRow.push_back(std::make_shared<GameTile>(50, 600, Type::grass));
    thirteenthRow.push_back(std::make_shared<GameTile>(100, 600, Type::wall));
    thirteenthRow.push_back(std::make_shared<GameTile>(150, 600, Type::grass));
    thirteenthRow.push_back(std::make_shared<GameTile>(200, 600, Type::wall));
    thirteenthRow.push_back(std::make_shared<GameTile>(250, 600, Type::wall));
    thirteenthRow.push_back(std::make_shared<GameTile>(300, 600, Type::grass));
    thirteenthRow.push_back(std::make_shared<GameTile>(350, 600, Type::wall));
    thirteenthRow.push_back(std::make_shared<GameTile>(400, 600, Type::grass));
    thirteenthRow.push_back(std::make_shared<GameTile>(450, 600, Type::wall));
    thirteenthRow.push_back(std::make_shared<GameTile>(500, 600, Type::wall));
    thirteenthRow.push_back(std::make_shared<GameTile>(550, 600, Type::wall));
    thirteenthRow.push_back(std::make_shared<GameTile>(600, 600, Type::wall));
    thirteenthRow.push_back(std::make_shared<GameTile>(650, 600, Type::grass));
    thirteenthRow.push_back(std::make_shared<GameTile>(700, 600, Type::wall));
    thirteenthRow.push_back(std::make_shared<GameTile>(750, 600, Type::wall));
    tiles.push_back(thirteenthRow);

    std::vector<std::shared_ptr<GameTile>> fourteenthRow;
    fourteenthRow.push_back(std::make_shared<GameTile>(0, 650, Type::wall));
    fourteenthRow.push_back(std::make_shared<GameTile>(50, 650, Type::grass));
    fourteenthRow.push_back(std::make_shared<GameTile>(100, 650, Type::wall));
    fourteenthRow.push_back(std::make_shared<GameTile>(150, 650, Type::grass));
    fourteenthRow.push_back(std::make_shared<GameTile>(200, 650, Type::grass));
    fourteenthRow.push_back(std::make_shared<GameTile>(250, 650, Type::grass));
    fourteenthRow.push_back(std::make_shared<GameTile>(300, 650, Type::grass));
    fourteenthRow.push_back(std::make_shared<GameTile>(350, 650, Type::wall));
    fourteenthRow.push_back(std::make_shared<GameTile>(400, 650, Type::grass));
    fourteenthRow.push_back(std::make_shared<GameTile>(450, 650, Type::grass));
    fourteenthRow.push_back(std::make_shared<GameTile>(500, 650, Type::grass));
    fourteenthRow.push_back(std::make_shared<GameTile>(550, 650, Type::grass));
    fourteenthRow.push_back(std::make_shared<GameTile>(600, 650, Type::wall));
    fourteenthRow.push_back(std::make_shared<GameTile>(650, 650, Type::grass));
    fourteenthRow.push_back(std::make_shared<GameTile>(700, 650, Type::wall));
    fourteenthRow.push_back(std::make_shared<GameTile>(750, 650, Type::wall));
    tiles.push_back(fourteenthRow);

    std::vector<std::shared_ptr<GameTile>> fifteenthRow;
    fifteenthRow.push_back(std::make_shared<GameTile>(0, 700, Type::wall));
    fifteenthRow.push_back(std::make_shared<GameTile>(50, 700, Type::grass));
    fifteenthRow.push_back(std::make_shared<GameTile>(100, 700, Type::wall));
    fifteenthRow.push_back(std::make_shared<GameTile>(150, 700, Type::grass));
    fifteenthRow.push_back(std::make_shared<GameTile>(200, 700, Type::grass));
    fifteenthRow.push_back(std::make_shared<GameTile>(250, 700, Type::grass));
    fifteenthRow.push_back(std::make_shared<GameTile>(300, 700, Type::grass));
    fifteenthRow.push_back(std::make_shared<GameTile>(350, 700, Type::wall));
    fifteenthRow.push_back(std::make_shared<GameTile>(400, 700, Type::grass));
    fifteenthRow.push_back(std::make_shared<GameTile>(450, 700, Type::grass));
    fifteenthRow.push_back(std::make_shared<GameTile>(500, 700, Type::grass));
    fifteenthRow.push_back(std::make_shared<GameTile>(550, 700, Type::grass));
    fifteenthRow.push_back(std::make_shared<GameTile>(600, 700, Type::wall));
    fifteenthRow.push_back(std::make_shared<GameTile>(650, 700, Type::grass));
    fifteenthRow.push_back(std::make_shared<GameTile>(700, 700, Type::door));
    fifteenthRow.push_back(std::make_shared<GameTile>(750, 700, Type::wall));
    tiles.push_back(fifteenthRow);

    std::vector<std::shared_ptr<GameTile>> sixteenthRow;
    sixteenthRow.push_back(std::make_shared<GameTile>(0, 750, Type::wall));
    sixteenthRow.push_back(std::make_shared<GameTile>(50, 750, Type::wall));
    sixteenthRow.push_back(std::make_shared<GameTile>(100, 750, Type::wall));
    sixteenthRow.push_back(std::make_shared<GameTile>(150, 750, Type::wall));
    sixteenthRow.push_back(std::make_shared<GameTile>(200, 750, Type::wall));
    sixteenthRow.push_back(std::make_shared<GameTile>(250, 750, Type::wall));
    sixteenthRow.push_back(std::make_shared<GameTile>(300, 750, Type::wall));
    sixteenthRow.push_back(std::make_shared<GameTile>(350, 750, Type::wall));
    sixteenthRow.push_back(std::make_shared<GameTile>(400, 750, Type::wall));
    sixteenthRow.push_back(std::make_shared<GameTile>(450, 750, Type::wall));
    sixteenthRow.push_back(std::make_shared<GameTile>(500, 750, Type::wall));
    sixteenthRow.push_back(std::make_shared<GameTile>(550, 750, Type::wall));
    sixteenthRow.push_back(std::make_shared<GameTile>(600, 750, Type::wall));
    sixteenthRow.push_back(std::make_shared<GameTile>(650, 750, Type::wall));
    sixteenthRow.push_back(std::make_shared<GameTile>(700, 750, Type::wall));
    sixteenthRow.push_back(std::make_shared<GameTile>(750, 750, Type::wall));
    tiles.push_back(sixteenthRow);
}