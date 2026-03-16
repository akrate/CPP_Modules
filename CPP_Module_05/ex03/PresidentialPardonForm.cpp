#include "PresidentialPardonForm.hpp"
PresidentialPardonForm::PresidentialPardonForm() : AForm("defualt", 25, 5),target("defualt")
{
    
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
    : AForm("PresidentialPardonForm", 25, 5), target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other) 
    : AForm(other), target(other.target)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::action() const
{
    std::cout << "has been pardoned by Zaphod Beeblebrox. " << target;
}
