#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>
#include <vector>
#include "dormitory.h"

class University {
private:
    std::string name;
    std::vector<Dormitory> dormitories;

public:
    University();
    University(std::string name);

    std::string getName() const;
    std::vector<Dormitory>& getDormitories();

    void addDormitory(const Dormitory& dorm);

    Room* findAvailableRoom();
};

#endif