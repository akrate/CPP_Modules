/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:12:48 by aoussama          #+#    #+#             */
/*   Updated: 2025/12/14 10:15:48 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"

Contact::Contact(){}

bool Contact::setcontact()
{
    std::cout << "enter frist name: ";
    if (!std::getline(std::cin,firstName))
        return false;
    std::cout << "enter last name: ";
    if (!std::getline(std::cin, lastName))
        return false;
    std::cout << "enter nickname: ";
    if (!std::getline(std::cin,nickName))
        return false;
    std::cout << "enter phone number: ";
    if (!std::getline(std::cin, phoneNumber))
        return false;
    std::cout << "enter darkest secret: ";
    if (!std::getline(std::cin, darkestSecret))
        return false;
    if (firstName.empty()||lastName.empty()||nickName.empty()
                    ||phoneNumber.empty()||darkestSecret.empty())
    {
        std::cout << "Error: all fields must be filled.\n";
        return false;
    }
    return true;
}
void Contact::displayFull() const
{
    std::cout << "Frist Name    ==> " << firstName << "\n";
    std::cout << "Last Name     ==> " << lastName << "\n";
    std::cout << "Nicke Name    ==> " << nickName << "\n";
    std::cout << "phone Number  ==> " << phoneNumber << "\n";
    std::cout << "dakest Secret ==> " << darkestSecret << "\n";
}
static std::string check_len(std::string str)
{
    if (str.length() > 10)
        return str.substr(0,9) + ".";
    return str;
}
void Contact::displayShort(int index) const
{
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << check_len(firstName) << "|"
              << std::setw(10) << check_len(lastName) << "|"
              << std::setw(10) << check_len(nickName) << "|" << "\n";
}
