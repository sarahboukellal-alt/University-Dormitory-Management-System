#include "restaurant.h"
#include <iostream>

using namespace std;

Restaurant::Restaurant() {
    name = "SIDI ABDELLAH REATURANT";
    lunchMenu.push_back("Couscous Poulet");
    lunchMenu.push_back("Chorba Frik");
    lunchMenu.push_back("Tajine Zitoun");
}

Restaurant::Restaurant(string name) {
    this->name = name;
}

string Restaurant::getName() const { return name; }

const vector<string>& Restaurant::getLunchMenu() const { return lunchMenu; }

void Restaurant::addMenuItem(const string& item) {
    lunchMenu.push_back(item);
}

void Restaurant::displayMenu() const {
    std::cout << "--- Menu : " << name << " ---" << std::endl;


    for (int i = 0; i < lunchMenu.size(); ++i) {


        std::string item = lunchMenu[i];


        std::cout << "- " << item << std::endl;
    }
}