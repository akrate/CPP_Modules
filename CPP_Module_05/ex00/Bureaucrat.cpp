#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : name("default"), grade(150)
{

}
Bureaucrat::Bureaucrat(std::string name,int grade) : name(name), grade(grade)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
}
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
    
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        grade = other.grade;
    return *this;
}
std::string Bureaucrat::getName() const
{
    return name;
}
int Bureaucrat::getGrade() const
{
    return grade;
}
void Bureaucrat::increment()
{
    if ((grade - 1) < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;

}
void Bureaucrat::decrement()
{
    if((grade + 1) > 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return out;
}
Bureaucrat::~Bureaucrat(){}