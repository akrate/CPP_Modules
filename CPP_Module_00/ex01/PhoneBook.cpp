/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:17:16 by aoussama          #+#    #+#             */
/*   Updated: 2025/11/13 11:12:36 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() :count(0) ,nextIndex(0) {}

void PhoneBook::addContact(){
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

void PhoneBook::searchContact() const{
    
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nakename" << "|" << std::endl;
              
    for(int i = 0; i < count ; i++)
    {
        contacts[i].displayShort(i);
    }
    std::cout << "enter index to view details: ";
    std::string input;
    std::getline(std::cin,input);

    int index = input[0] - '0';
    
    contacts[index].displayFull();
}