#include "Zombie.hpp"

Zombie::Zombie(){}

void Zombie::setName(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << this->name << ": is destroy." << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}