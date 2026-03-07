#include "FragTrap.hpp"

int main()
{
    std::cout << "----- Creating FragTrap -----\n";
    FragTrap frag1("Hercules");

    std::cout << "\n----- Testing FragTrap abilities -----\n";
    frag1.attack("EnemyBot");
    frag1.highFivesGuys();
    frag1.takeDamage(40);
    frag1.beRepaired(25);

    std::cout << "\n----- Copy constructor test -----\n";
    FragTrap frag2(frag1);
    frag2.highFivesGuys();

    std::cout << "\n----- Assignment operator test -----\n";
    FragTrap frag3;
    frag3 = frag1;
    frag3.attack("AnotherEnemy");

    std::cout << "\n----- End of program -----\n";

    return 0;
}