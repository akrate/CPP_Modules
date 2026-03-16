#include "Intern.hpp"

Intern::Intern()
{

}
Intern::Intern(const Intern& other){
    *this = other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}
Intern::~Intern(){}

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string names[] = {"robotomy request"
        ,"presidential pardon"
        ,"shrubbery creation"};
    int i = 0;
    while (i < 3)
    {
        if (name == names[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            switch (i)
            {
                case 0: return new RobotomyRequestForm(target);
                case 1: return new PresidentialPardonForm(target);
                case 2: return new ShrubberyCreationForm(target);
            }
        }
        i++;
    }
    std::cout << "Error: Form name '" << name << "' doesn't exist!" << std::endl;
    return NULL;
}