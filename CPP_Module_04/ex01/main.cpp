#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int main()
{
    const int SIZE = 4;
    Animal* animals[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        if (i < SIZE / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    std::cout << "\n--- Testing makeSound ---\n";

    for (int i = 0; i < SIZE; i++)
        animals[i]->makeSound();
    std::cout << "\n--- Testing Deep Copy ---\n";

    Dog originalDog;
    originalDog.getBrain()->ideas[0] = "Food";

    Dog copiedDog = originalDog; 

    std::cout << "Original Dog Brain idea[0]: " 
              << originalDog.getBrain()->ideas[0] << std::endl; 
    std::cout << "Copied Dog Brain idea[0]: " 
              << copiedDog.getBrain()->ideas[0] << std::endl;   
    std::cout << "=====================================" << std::endl;
    Cat originalCat;
    originalCat.getBrain()->ideas[0] = "Chasing mice";

    Cat copiedCat;
    copiedCat = originalCat; 
    copiedCat.getBrain()->ideas[0] = "Sleeping";

    std::cout << "Original Cat Brain idea[0]: " 
              << originalCat.getBrain()->ideas[0] << std::endl; 
    std::cout << "Copied Cat Brain idea[0]: " 
              << copiedCat.getBrain()->ideas[0] << std::endl;  
        std::cout << "\n--- Deleting Animals array ---\n";
    for (int i = 0; i < SIZE; i++)
        delete animals[i];

    return 0;
}