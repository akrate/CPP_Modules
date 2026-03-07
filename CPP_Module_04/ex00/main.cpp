#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "----- BASIC TEST -----" << std::endl;

    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;

    dog->makeSound();
    cat->makeSound();
    meta->makeSound();

    delete meta;
    delete dog;
    delete cat;

    std::cout << "\n----- WRONG ANIMAL TEST -----" << std::endl;

    const WrongAnimal* w1 = new WrongAnimal();
    const WrongAnimal* w2 = new WrongCat();

    w1->makeSound();
    w2->makeSound();

    delete w1;
    delete w2;

    return 0;
}