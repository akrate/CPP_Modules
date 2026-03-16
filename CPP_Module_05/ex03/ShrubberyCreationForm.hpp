#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
class ShrubberyCreationForm : public AForm
{
    // private:
    //     std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        void action() const;
};

#endif