#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default")
{
    Hit = 100;
    Energy = 50;
    Attack = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}
ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    Hit = 100;
    Energy = 50;
    Attack = 20;
    std::cout << "ScavTrap constructor called for " << this->Name << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    ClapTrap::operator=(other);
    std::cout << "ScavTrap assignment operator called\n";
    return *this;
}
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called\n";
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << Name << " destroyed\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (Hit == 0)
    {
        std::cout << "ScavTrap " << Name << " has no hit points and cannot attack.\n";
        return;
    }
    if (Energy == 0)
    {
        std::cout << "ScavTrap " << Name << " has no energy points and cannot attack.\n";
        return;
    }
    std::cout << "ScavTrap "<< Name <<" attacks "
                << target << ", causing "<< Attack 
                << " points of damage!" << std::endl;
    Energy--;
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << Name
              << " is now in Gate keeper mode!\n";
}
