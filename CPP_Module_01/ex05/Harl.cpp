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
    void (Harl::*ptrHarl[4])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    std::string name[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    int i = 0;
    while (i < 4)
    {
        if (name[i] == level)
        {
            (this->*ptrHarl[i])();
            return ;
        }
        i++;
    }
    std::cout << "[UNKNOWN] Harl doesn't know this level!" << std::endl;
}