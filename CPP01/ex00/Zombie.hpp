#ifndef Zombie_h
#define Zombie_h

#include <iostream>

using namespace std;

class Zombie {

private:
    string name;

public:
    Zombie();

    string get_name();

    void set_name(string);

    void to_string();
};

Zombie::Zombie() {
    name = 0;
}

string Zombie::get_name() { return name; }

void Zombie::set_name(string new_name) { name = new_name; }

void Zombie::to_string() {
    cout << "name" << name << endl;
}

#endif
