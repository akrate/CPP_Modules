#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int main()
{
    std::srand(std::time(0));
    Bureaucrat oussama("oussama",1);
    Bureaucrat nouamane("nouamane",150);

    PresidentialPardonForm form1("form1");
    RobotomyRequestForm form2("form2");
    ShrubberyCreationForm form3("form3");
    std::cout << std::endl <<"---------------------------------------------------" << std::endl;
    oussama.signForm(form1);
    oussama.executeForm(form1);
    nouamane.signForm(form1);
    nouamane.executeForm(form1);
    std::cout << std::endl <<"---------------------------------------------------" << std::endl;
    oussama.signForm(form2);
    oussama.executeForm(form2);
    nouamane.signForm(form2);
    nouamane.executeForm(form2);
    std::cout << std::endl <<"---------------------------------------------------" << std::endl;
    oussama.signForm(form3);
    oussama.executeForm(form3);
    nouamane.signForm(form3);
    nouamane.executeForm(form3);
}