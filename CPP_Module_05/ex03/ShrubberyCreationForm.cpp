#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("defualt",145,137), target("defualt")
{

}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm("ShrubberyCreationForm",145,137), target(target)
{

}
ShrubberyCreationForm::~ShrubberyCreationForm()
{

}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other), target(other.target)
{

}
void ShrubberyCreationForm::action() const
{
    std::string file_name = this->target + "_shrubbery";
    std::ofstream opfile(file_name.c_str());
    if (opfile)
    {
        opfile << "   ^   " << std::endl;
        opfile << "  / \\  " << std::endl;
        opfile << " /   \\ " << std::endl;
        opfile.close();
    }
    else 
    {
        std::cout << "can't open file" << std::endl;
    }
}