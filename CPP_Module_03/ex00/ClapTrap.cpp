#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : Name(name)
{
    std::cout << "Default constructor called\n";
}
ClapTrap::ClapTrap(const ClapTrap& obj)
{
    std::cout << "Copy constructor called\n";
    *this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
    std::cout << "Copy assignment operator called\n";
    Name = obj.Name;
    Hit = obj.Hit;
    Energy = obj.Energy;
    Attack = obj.Attack;

    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called\n";
}

void ClapTrap::attack(const std::string& target)
{
    std::cout << "ClapTrap "<< Name <<" attacks "
                << target << ", causing "<< Attack 
                << " points of damage!" << std::endl;
    Attack++;
    Energy--;
}
void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);