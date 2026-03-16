#include "AForm.hpp"
#include "Bureaucrat.hpp"
AForm::AForm() : name("defualt"), sign(false), sign_grade(100), exe_grade(100)
{

}
AForm::AForm(std::string name,int sin_grade,int exe_grade) 
    : name(name), sign(false), sign_grade(sin_grade), exe_grade(exe_grade)
{
    if (sin_grade < 1 || exe_grade < 1)
        throw GradeTooHighException();
    if (sin_grade > 150 || exe_grade > 150)
        throw GradeTooLowException();
}
AForm::AForm(const AForm& other) 
    : name(other.name), sign(other.sign), sign_grade(other.sign_grade), exe_grade(other.exe_grade)
{  

}
AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->sign = other.sign;
    return *this;
}
AForm::~AForm(){}


std::string AForm::get_name()const
{
    return name;
}
bool AForm::get_sign()const
{
    return sign;
}
int AForm::get_sign_grade()const
{
    return sign_grade;
}
int AForm::get_exe_grade() const
{
    return exe_grade;
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
    out << f.get_name()
        << ", sign grade: " << f.get_sign_grade()
        << ", execute grade: " << f.get_exe_grade()
        << ", signed: " << (f.get_sign() ? "yes" : "no");
    return out;
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > this->sign_grade)
        throw GradeTooLowException();
    sign = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (this->sign == false)
        throw FormNotSignedException();
    if (executor.getGrade() > this->get_exe_grade())
        throw GradeTooLowException();
    this->action();
}