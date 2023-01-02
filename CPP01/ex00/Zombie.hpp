#ifndef Zombie_h
#define Zombie_h

#include <iostream>

using namespace std;

class Zombie {

private:
    string name;

public:
    Zombie(string name);

    ~Zombie();

    void    announce(void);

    Zombie* newZombie(string name);

    void    randomChump(string name);
};

Zombie::Zombie(string name) {
    this->_name = name;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << this->_name << " has been destroyed." << std::endl;
}

void    Zombie::announce( void ) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie  *newZombie(string name)
{
    return (new Zombie(name));
}


void    randomChump(string name)
{
    Zombie random(name);
    random.announce();
}

#endif
