#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <ctime>

int main() 
{
    std::srand(std::time(0));
    Intern test;

    AForm* rrf;

    rrf = test.makeForm("robotomy request", "Bender");
    if (rrf) {
        std::cout << "Target of created form: " << rrf->get_name() << std::endl;
        delete rrf;
    }

    rrf = test.makeForm("unknown form", "Target");
    
    return 0;
}