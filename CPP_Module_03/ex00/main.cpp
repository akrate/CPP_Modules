#include "ClapTrap.hpp"

int main()
{
    ClapTrap robot("TEST");

    robot.attack("Bandit");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.takeDamage(10);
    robot.attack("Enemy");
    robot.beRepaired(2);

    return 0;
}