/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:15:59 by waziz             #+#    #+#             */
/*   Updated: 2024/05/20 12:34:18 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void    Welcome()
{
    std::cout << std::endl;
    std::cout << "📖 MY AWESOME PHONEBOOK 📖" << std::endl;
    std::cout << std::endl;
    std::cout << "--------------RULES---------------" << std::endl;
    std::cout << "ADD\t: to add a Contact." << std::endl;
    std::cout << "SEARCH\t: to search for a Contact." << std::endl;
    std::cout << "EXIT\t: to quite the PhoneBook." << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << std::endl;
}

int main()
{
    PhoneBook Directory;
    std::string input = "";

    Welcome();
    Directory.init_pb();
    while (!std::cin.eof())
    {
        if (input.compare("EXIT") == 0)
            break ;
        if (input.compare("ADD") == 0)
            Directory.add_contact();
        if (input.compare("SEARCH") == 0)
            Directory.search_contact();
        if (!std::cin.eof())
        {
            do
            {
                std::cout << "PhoneBook> ";
                std::getline(std::cin, input);
            }
            while (!std::cin.eof() && input.empty());
        }
        if (std::cin.eof())
        {
            std::cout << std::endl;
            std::cout << "Exiting.." << std::endl;
        }
    }
    return (0);
}