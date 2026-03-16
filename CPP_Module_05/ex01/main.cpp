#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat bob("Bob", 50);
    Bureaucrat alice("Alice", 20);

    Form tax("TaxForm", 30, 10);

    bob.signForm(tax);
    alice.signForm(tax);

    std::cout << tax << std::endl;
}