#include "Form.hpp"
#include "Bureaucrat.hpp"
Form::Form() : name("defualt"), sign(false), sign_grade(100), exe_grade(100)
{

}
Form::Form(std::string name,int sin_grade,int exe_grade) 
    : name(name), sign(false), sign_grade(sin_grade), exe_grade(exe_grade)
{
    if (sin_grade < 1 || exe_grade < 1)
        throw GradeTooHighException();
    if (sin_grade > 150 || exe_grade > 150)
        throw GradeTooLowException();
}
Form::Form(const Form& other) 
    : name(other.name), sign(other.sign), sign_grade(other.sign_grade), exe_grade(other.exe_grade)
{  

}
Form& Form::operator=(const Form& other)
{
    if (this != &other)
        this->sign = other.sign;
    return *this;
}
Form::~Form(){}


std::string Form::get_name()const
{
    return name;
}
bool Form::get_sign()const
{
    return sign;
}
int Form::get_sign_grade()const
{
    return sign_grade;
}
int Form::get_exe_grade() const
{
    return exe_grade;
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
    out << f.get_name()
        << ", sign grade: " << f.get_sign_grade()
        << ", execute grade: " << f.get_exe_grade()
        << ", signed: " << (f.get_sign() ? "yes" : "no");
    return out;
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > this->sign_grade)
        throw GradeTooLowException();
    sign = true;
}