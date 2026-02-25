#include "ScavTrap.hpp"

int main()
{
    std::cout << "----- Creating ScavTrap -----\n";
    ScavTrap scav("Guardian");

    std::cout << "\n----- Testing abilities -----\n";
    scav.attack("Enemy");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();

    std::cout << "\n----- Copy test -----\n";
    ScavTrap copy(scav);

    std::cout << "\n----- End of program -----\n";
    return 0;
}