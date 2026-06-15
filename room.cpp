#include "room.h"
Room::Room() : roomNumber(""), capacity(0) {}

Room::Room(std::string number, int cap) : roomNumber(number), capacity(cap) {}


std::string Room::getRoomNumber() const {
    return roomNumber;
}
int Room::getCapacity() const {
    return capacity;
}

const std::vector<Student>& Room::getResidents() const {
    return residents;
}

bool Room::addStudent(const Student& s) {
    if (residents.size() < static_cast<size_t>(capacity)) {
        residents.push_back(s);
        return true;
    }
    return false;
}

bool Room::removeStudent(const std::string& studentId) {

    if (studentId.empty()) {
        return false;
    }


    int targetId = std::stoi(studentId);


    for (int i = 0; i < residents.size(); ++i) {


        if (residents[i].getId() == targetId) {


            residents.erase(residents.begin() + i);
            return true;
        }
    }

    return false;
}

bool Room::isFull() const {
    return residents.size() >= static_cast<size_t>(capacity);
}