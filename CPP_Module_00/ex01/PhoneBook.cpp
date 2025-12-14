/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:17:16 by aoussama          #+#    #+#             */
/*   Updated: 2025/12/14 11:15:03 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() :count(0) ,nextIndex(0) {}

void PhoneBook::addContact()
{
    Contact newContact;
    newContact.setcontact();
    if (newContact.isEmpty() == false)
    {
        contacts[nextIndex] = newContact;
        nextIndex = (nextIndex + 1) % 8;
        if (count < 8)
        {
            count++;
            std::cout << "Contact added successfully!\n";
        }
    }
}


void PhoneBook::searchContact() const {

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|\n";

    for (int i = 0; i < count; i++) {
        contacts[i].displayShort(i);
    }

    std::string input;
    int index = -1;

    while (true) {
        std::cout << "Enter index to view details: ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\nEOF detected. Exiting search.\n";
            return;
        }
        if (input.length() != 1 || !std::isdigit(input[0])) {
            std::cout << "❌ Invalid input. Enter a single digit.\n";
            continue;
        }
        index = input[0] - '0';
        
        if (index < 0 || index >= 8 || index >= count) {
            if (index >= count && index <= 7)
            {
               std::cout << "❌ Index Not found.\n";
               continue;
            }
            std::cout << "❌ Index out of range.\n";
            continue;
        }
        break;
    }
    contacts[index].displayFull();
}