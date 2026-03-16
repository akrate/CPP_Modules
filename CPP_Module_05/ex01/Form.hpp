#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
class Bureaucrat;
class Form
{
    private:
        const std::string name;
        bool sign;
        const int sign_grade;
        const int exe_grade;
    public:
        Form();
        Form(std::string name,int sin_grade,int exe_grade);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
        std::string get_name()const;
        bool get_sign()const;
        int get_sign_grade()const;
        int get_exe_grade() const;
        void beSigned(const Bureaucrat& b);
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Form: grade too high";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Form: grade too low to sign";
                }
        };
};
std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif 