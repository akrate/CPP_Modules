#include "Zombie.hpp"

int main()
{
    Zombie *zombie1 = newZombie("foo");
    zombie1->announce();

    delete zombie1;
    randomChump("Foo");
}