#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("Default"), Hit(10), Energy(10), Attack(0)
{
    std::cout << "ClapTrap default constructor called\n";
}
ClapTrap::ClapTrap(std::string name) : Name(name),Hit(10),Energy(10),Attack(0)
{
    std::cout << "ClapTrap " << Name << " constructed!\n";
}
ClapTrap::ClapTrap(const ClapTrap& obj)
{
    std::cout << "ClapTrap " << Name << " copied!\n";
    Name = obj.Name;
    Hit = obj.Hit;
    Energy = obj.Energy;
    Attack = obj.Attack;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
    std::cout << "ClapTrap " << Name << " assigned!\n";
    Name = obj.Name;
    Hit = obj.Hit;
    Energy = obj.Energy;
    Attack = obj.Attack;

    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << Name << " destructed!\n";
}

void ClapTrap::attack(const std::string& target)
{
    if (Hit == 0)
    {
        std::cout << "ClapTrap " << Name << " has no hit points and cannot attack.\n";
        return;
    }
    if (Energy == 0)
    {
        std::cout << "ClapTrap " << Name << " has no energy points and cannot attack.\n";
        return;
    }
    std::cout << "ClapTrap "<< Name <<" attacks "
                << target << ", causing "<< Attack 
                << " points of damage!" << std::endl;
    Energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (Hit == 0)
    {
        std::cout << "ClapTrap " << Name << " is already destroyed!\n";
        return;
    }
    if (amount >= (unsigned int)Hit)
    {
        Hit = 0;
    }else
    {
        Hit -= amount;
    }
    std::cout << "ClapTrap " << Name << " takes " << amount
              << " points of damage! Hit points left: " << Hit << "\n";
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (Hit == 0)
    {
        std::cout << "ClapTrap " << Name << " is destroyed and cannot be repaired.\n";
        return;
    }
    if (Energy == 0)
    {
        std::cout << "ClapTrap " << Name << " has no energy points and cannot repair.\n";
        return;
    }
    Hit += amount;
    Energy--;
    std::cout << "ClapTrap " << Name << " repairs itself for " << amount
              << " hit points! Hit points now: " << Hit << "\n";
}