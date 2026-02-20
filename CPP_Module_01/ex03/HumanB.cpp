#include "HumanB.hpp"


void HumanB::attack() const
{
    if (this->weapon)
    {
        std::cout << this->name
                  << " attacks with their "
                  << this->weapon->getType()
                  << std::endl;
    }
    else
    {
        std::cout << this->name
                  << " has no weapon"
                  << std::endl;
    }
}

HumanB::HumanB(std::string name) : weapon(NULL)
{
    this->name = name;
}

HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon& weapon)
{
        this->weapon = &weapon;

}