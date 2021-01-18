#include "Item.h"

Item::Item(Type type, float x, float y, std::string path) : type(type) {
    this->position.x = x * 50;
    this->position.y = y * 50;
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

