#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    int id;
    std::string fullName;
    std::string academicYear;

public:
    Student();
    Student(int id, std::string name, std::string year);

    int getId() const;
    std::string getFullName() const;
    std::string getAcademicYear() const;
};

#endif