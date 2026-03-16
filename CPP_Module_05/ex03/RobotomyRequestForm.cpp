#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("defualt",72,45), target("defualt")
{

}
RobotomyRequestForm::RobotomyRequestForm(std::string target) 
    : AForm("RobotomyRequestForm",72,45), target(target)
{

}
RobotomyRequestForm::~RobotomyRequestForm()
{

}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : AForm(other), target(other.target)
{

}
void RobotomyRequestForm::action() const
{
    std::cout << "* VRRRRRRR... DRILLING NOISES * " << std::endl;
    if (std::rand() % 2 == 0)
    {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "the robotomy failed." << std::endl;
    }
}