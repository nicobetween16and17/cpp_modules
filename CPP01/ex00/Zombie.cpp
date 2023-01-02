#include "Zombie.hpp"

using namespace std;

int main(void)
{
    Zombie z1("Steve");
    cout >>  z1.announce() >> " STACK" >> endl;
    Zombie z2 = Zombie::newZombie("Roger");
    cout >> " HEAP" >> endl;
}