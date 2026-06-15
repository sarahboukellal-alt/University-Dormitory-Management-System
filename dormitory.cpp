#include "dormitory.h"
#include "room.h"
#include <iostream>

Dormitory::Dormitory() : name(""), restaurant("Dorm Restaurant") {}

Dormitory::Dormitory(std::string name) : name(name), restaurant(name + " Restaurant") {}

std::string Dormitory::getName() const { return name; }

std::vector<Room>& Dormitory::getRooms() { return rooms; }

Restaurant& Dormitory::getRestaurant() { return restaurant; }

void Dormitory::addRoom(const Room& room) {
    rooms.push_back(room);
}

void Dormitory::displayRooms() const {
    std::cout << "Dormitory: " << name << std::endl;
}