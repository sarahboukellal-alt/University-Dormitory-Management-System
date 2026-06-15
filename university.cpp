#include "university.h"
#include "room.h"

University::University() : name("ENSIA") {}

University::University(std::string name) : name(name) {}

std::string University::getName() const { return name; }

std::vector<Dormitory>& University::getDormitories() { return dormitories; }

void University::addDormitory(const Dormitory& dorm) {
    dormitories.push_back(dorm);
}

Room* University::findAvailableRoom() {

    for (Dormitory& dorm : dormitories) {


        for (Room& room : dorm.getRooms()) {


            if (!room.isFull()) {
                return &room;
            }
        }
    }
    return nullptr;
}