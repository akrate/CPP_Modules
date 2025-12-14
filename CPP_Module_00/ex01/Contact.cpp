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

void Contact::setcontact(){
    // std::cout << "enter frist name: ";
    // std::getline(std::cin,firstName);
    while (firstName.empty())
    {
        std::cout << "enter frist name: ";
        if (!std::getline(std::cin,firstName))
        {
            std::cout << "dkhl chi 9lwa  ";
            std::cout << "Error: all fields must be filled.\n";
            *this = Contact();
            return ;
        }
    }
    // std::cout << "enter last name: ";
    // std::getline(std::cin, lastName);
    while (lastName.empty())
    {
        std::cout << "enter last name: ";
        std::getline(std::cin, lastName);
    }
    // std::cout << "enter nickname: ";
    // std::getline(std::cin,nickName);
    while (nickName.empty())
    {
        std::cout << "enter nickname: ";
        std::getline(std::cin,nickName);
    }
    // std::cout << "enter phone number: ";
    // std::getline(std::cin, phoneNumber);
    while (phoneNumber.empty())
    {
        std::cout << "enter phone number: ";
        std::getline(std::cin, phoneNumber);
    }
    // std::cout << "enter darkest secret: ";
    // std::getline(std::cin, darkestSecret);
    while (darkestSecret.empty())
    {
        std::cout << "enter darkest secret: ";
        std::getline(std::cin, darkestSecret);
    }
    if (firstName.empty()||lastName.empty()||nickName.empty()||phoneNumber.empty()||darkestSecret.empty())
    {
        std::cout << "Error: all fields must be filled.\n";
        *this = Contact();
    }
}
bool Contact::isEmpty() const {
    return firstName.empty();
}
void Contact::displayFull() const{
    std::cout << "Frist Name ==> " << firstName << std::endl;
    std::cout << "Last Name ==> " << lastName << std::endl;
    std::cout << "Nicke Name ==> "<< nickName << std::endl;
    std::cout << "phone Number ==>" << phoneNumber << std::endl;
    std::cout << "dakest Secret == >" << darkestSecret << std::endl;
}
static std::string check_len(std::string str)
{
    if (str.length() > 10)
        return str.substr(0,9) + ".";
    return str;
}
void Contact::displayShort(int index) const{
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << check_len(firstName) << "|"
              << std::setw(10) << check_len(lastName) << "|"
              << std::setw(10) << check_len(nickName) << "|" << std::endl;
}
