#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"


class DiamondTrap : public ScavTrap , public FragTrap
{
    private:
        std::string Name;
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& obj);
        DiamondTrap& operator=(const DiamondTrap& obj);
        ~DiamondTrap();
        using ScavTrap::attack;
        void whoAmI();
};

#endif