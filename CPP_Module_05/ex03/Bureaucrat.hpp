#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name,int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        std::string getName() const;
        ~Bureaucrat();
        int getGrade() const;
        void increment();
        void decrement();
        void signForm(AForm& f) const;
        void executeForm(AForm const & form);
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "this Grade Too High";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "this Grade Too Low";
                }
        };

};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);



#endif 