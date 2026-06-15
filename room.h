#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "student.h"

class Room {
private:
    std::string roomNumber;
    int capacity;
    std::vector<Student> residents;

public:
    Room();
    Room(std::string number, int cap);

    std::string getRoomNumber() const;
    int getCapacity() const;
    const std::vector<Student>& getResidents() const;

    bool addStudent(const Student& s);
    bool removeStudent(const std::string& studentId);
    bool isFull() const;
};

#endif