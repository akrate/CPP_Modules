/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:12:56 by aoussama          #+#    #+#             */
/*   Updated: 2025/12/14 10:17:09 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
	std::cout << "PHONEBOOK APPLICATION\n";
    std::string choise;
    while(true)
    {
        std::cout << "\nchoose your operation:\n";
        std::cout << "# ADD:\n";
        std::cout << "# SEARCH:\n";
        std::cout << "# EXIT:\n";
        if (!std::getline(std::cin, choise))
        {
            std::cout << "\nEOF detected. Exiting...\n";
            return 1;                      
        }
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
    return 0;
}