#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
class Bureaucrat;
class AForm
{
    private:
        const std::string name;
        bool sign;
        const int sign_grade;
        const int exe_grade;
    public:
        AForm();
        AForm(std::string name,int sin_grade,int exe_grade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        std::string get_name()const;
        bool get_sign()const;
        int get_sign_grade()const;
        int get_exe_grade() const;
        void beSigned(const Bureaucrat& b);
        void execute(Bureaucrat const & executor) const;
        virtual void action() const = 0;
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
        class FormNotSignedException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Form: cannot execute because it's not signed";
                }
        };
};
std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif 