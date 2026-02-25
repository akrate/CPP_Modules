#include "FragTrap.hpp"

int main()
{
    std::cout << "----- Creating FragTrap -----\n";
    FragTrap frag1("Hercules");

    std::cout << "\n----- Testing FragTrap abilities -----\n";
    frag1.attack("EnemyBot");       // override attack
    frag1.highFivesGuys();          // special ability
    frag1.takeDamage(40);           // inherited from ClapTrap
    frag1.beRepaired(25);           // inherited from ClapTrap

    std::cout << "\n----- Copy constructor test -----\n";
    FragTrap frag2(frag1);          // copy constructor
    frag2.highFivesGuys();

    std::cout << "\n----- Assignment operator test -----\n";
    FragTrap frag3;
    frag3 = frag1;                  // assignment operator
    frag3.attack("AnotherEnemy");

    std::cout << "\n----- End of program -----\n";

    return 0;
}