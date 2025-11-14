/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:12:56 by aoussama          #+#    #+#             */
/*   Updated: 2025/11/12 18:44:02 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.hpp"
#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#define yellow "\x1B[33m"
#define blue "\x1B[34m"
#define Bblue "\x1B[94m"
#define reset "\033[0m"
int main()
{
    PhoneBook phonebook;
    std::cout << Bblue << "*********************************************************" << reset << std::endl;
	std::cout << Bblue << "*                                                       *" << reset << std::endl;
	std::cout << Bblue << "*  " << yellow << "__        __   _                            _        " << Bblue << "*" << reset << std::endl;
	std::cout << Bblue << "*  " << yellow << "\\ \\      / /__| | ___ ___  _ __ ___   ___  | |_ ___  " << Bblue << "*" << reset << std::endl;
	std::cout << Bblue << "*  " << yellow << " \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\ " << Bblue << "*" << reset << std::endl;
	std::cout << Bblue << "*  " << yellow << "  \\ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) |" << Bblue << "*" << reset << std::endl;
	std::cout << Bblue << "*  " << yellow << "   \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/ " << Bblue << "*" << reset << std::endl;
	std::cout << Bblue << "*                                                       *" << reset << std::endl;
	std::cout << Bblue << "*                " << yellow << "PHONEBOOK APPLICATION" << Bblue << "                  *" << reset << std::endl;
	std::cout << Bblue << "*                                                       *" << reset << std::endl;
	std::cout << Bblue << "*********************************************************" << reset << std::endl;
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::string choise;
    while(true)
    {
        std::cout << "choose your operation\n";
        std::cout << "1 ==> ADD:\n";
        std::cout << "2 ==> SEARCH:\n";
        std::cout << "3 ==> EXIT:\n";
        std::getline(std::cin,choise);
        if (choise == "ADD")
            phonebook.addContact();
        else if (choise == "SEARCH")
            phonebook.searchContact();
        else if (choise == "EXIT")
            break;
        else
            std::cout << "Invalid command.\n";
    }
    std::cout << "Goodbye!\n";
}