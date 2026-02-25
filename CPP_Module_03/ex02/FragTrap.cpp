#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default") 
{
    Hit = 100;
    Energy = 100;
    Attack = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    Hit = 100;
    Energy = 100;
    Attack = 30;
    std::cout << "FragTrap constructor called for " << this->Name << std::endl;
}
FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj)
{
     std::cout << "FragTrap copy constructor called\n";
}
FragTrap& FragTrap::operator=(const FragTrap& obj) 
{
    ClapTrap::operator=(obj);
    std::cout << "FragTrap assignment operator called\n";
    return *this;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap destroyed" << std::endl;
}
void FragTrap::attack(const std::string& target)
{
    if (Hit == 0)
    {
        std::cout << "FragTrap " << Name << " has no hit points and cannot attack.\n";
        return;
    }
    if (Energy == 0)
    {
        std::cout << "FragTrap " << Name << " has no energy points and cannot attack.\n";
        return;
    }
    std::cout << "FragTrap "<< Name <<" attacks "
                << target << ", causing "<< Attack 
                << " points of damage!" << std::endl;
    Energy--;
}
void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name 
              << " is requesting a positive high five! ✋" 
              << std::endl;
}

