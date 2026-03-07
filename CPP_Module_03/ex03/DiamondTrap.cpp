#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() 
    : ClapTrap("default_clap_name"),
        ScavTrap("default"),
        FragTrap("default"),
        Name("default")
{
    Hit = 100;
    Energy = 50;
    Attack = 30;
    std::cout << "DiamondTrap " << this->Name << " constructed\n";
}

DiamondTrap::DiamondTrap(std::string name) 
    : ClapTrap(name + "_clap_name"),
        ScavTrap(name),
        FragTrap(name),
        Name(name)
{
    Hit = 100;
    Energy = 50;
    Attack = 30;
    std::cout << "DiamondTrap " << this->Name << " constructed\n";
}
DiamondTrap::DiamondTrap(const DiamondTrap& obj)
    : ClapTrap(obj),
      ScavTrap(obj),
      FragTrap(obj),
      Name(obj.Name)
{
    std::cout << "DiamondTrap copy constructor called\n";
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
    ClapTrap::operator=(obj);
    Name = obj.Name;
    std::cout << "DiamondTrap assignment operator called\n";
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << Name << " destroyed\n";
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << Name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::Name << std::endl;
}