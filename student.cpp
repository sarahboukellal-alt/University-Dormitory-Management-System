#include "student.h"

Student::Student() {
    id = 0;
    fullName = "";
    academicYear = "";
}

Student::Student(int id, std::string name, std::string year) {
    this->id = id;
    this->fullName = name;
    this->academicYear = year;
}

int Student::getId() const {
    return id;
}

std::string Student::getFullName() const {
    return fullName;
}

std::string Student::getAcademicYear() const {
    return academicYear;
}