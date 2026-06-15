#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
#include <vector>

class Restaurant {
private:
    std::string name;
    std::vector<std::string> lunchMenu;

public:
    Restaurant();
    Restaurant(std::string name);

    std::string getName() const;
    const std::vector<std::string>& getLunchMenu() const;
    void addMenuItem(const std::string& item);
    void displayMenu() const;
};

#endif