#ifndef DORMITORY_H
#define DORMITORY_H

#include <string>
#include <vector>
#include "restaurant.h"

class Room;

class Dormitory {
private:
    std::string name;
    std::vector<Room> rooms;
    Restaurant restaurant;

public:
    Dormitory();
    Dormitory(std::string name);

    std::string getName() const;
    std::vector<Room>& getRooms();
    Restaurant& getRestaurant();

    void addRoom(const Room& room);
    void displayRooms() const;
};

#endif