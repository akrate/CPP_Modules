#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout << "[DEBUG]\nI love having extra bacon for " 
              <<"my 7XL-double-cheese-triple-pickle-specialketchup burger. " 
              <<"I really do!\n";
}

void Harl::info( void )
{
    std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. " 
              <<"You didn’t putenough bacon in my burger! If you did, "
              <<"I wouldn’t be asking for more!\n";
}
void Harl::warning( void )
{
    std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. " 
              <<"I’ve been coming for years, whereas you started working here just last month.\n";
}
void Harl::error( void )
{
    std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain( std::string level )
{
    int Index = -1;

    if (level == "DEBUG")
        Index = 0;
    else if (level == "INFO")
        Index = 1;
    else if (level == "WARNING")
        Index = 2;
    else if (level == "ERROR")
        Index = 3;

    switch (Index)
    {
        case 0:
            debug();
        case 1:
            info();
        case 2:
            warning();
        case 3:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}