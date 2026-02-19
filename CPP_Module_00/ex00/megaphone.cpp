/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:07:47 by aoussama          #+#    #+#             */
/*   Updated: 2025/12/08 12:11:00 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 1;
    } else if (ac > 2)
    {
        std::cout << "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.\n";
        return 1;
    }
    std::string str = av[1];
    for (int i = 0; str[i]; ++i)
    {
        std::cout << (char)std::toupper(str[i]);
    }
    std::cout << '\n';
    return 0;
}