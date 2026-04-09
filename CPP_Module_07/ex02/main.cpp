#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
    std::cout << "--- Test 1: Empty Array ---" << std::endl;
    Array<int> empty;
    std::cout << "Size of empty: " << empty.size() << std::endl;

    std::cout << "\n--- Test 2: Int Array with size ---" << std::endl;
    Array<int> numbers(5);
    std::cout << "Size: " << numbers.size() << std::endl;
    std::cout << "Default values (should be 0): ";
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
    std::cout << "\n--- Test 3: Out of Bounds Exception ---" << std::endl;
    try {
        std::cout << "Accessing index 10: " << numbers[10] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << "\n--- Test 4: String Array ---" << std::endl;
    Array<std::string> strings(3);
    strings[0] = "Hello";
    strings[1] = "42";
    strings[2] = "School";
    for (unsigned int i = 0; i < strings.size(); i++)
        std::cout << strings[i] << " ";
    std::cout << std::endl;

    return 0;
}