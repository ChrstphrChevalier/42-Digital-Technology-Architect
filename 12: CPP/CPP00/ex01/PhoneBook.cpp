/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:03:41 by waziz             #+#    #+#             */
/*   Updated: 2024/05/20 13:40:00 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void    PhoneBook::init_pb()
{
    index = 0;
}

void    PhoneBook::add_contact()
{
    if (index == 8)
        index = 0;
    _Contacts[index].init_c(index);
    index++;
}

void    PhoneBook::search_contact()
{
    long long       request = -1;
    std::string     input;
    bool            valid = false;

    if (index == 0)
    {
        std::cout << "No contacts to display." << std::endl;
        return;
    }
    for (int i = 0; i < 8; i++)
        _Contacts[i].view_contact();
    do
    {
        do
        {
            std::cout << "Which contact do you want to display?" << std::endl;
            std::cout << "> ";
            std::getline(std::cin, input);
        } while (input.empty() && !std::cin.eof());
        if (std::cin.eof())
            return ;
        for(size_t i = 0; i < input.size(); i++)
        {
            if (!std::isdigit(input[i]) && input[i] != '-')
            {
                std::cout << "Invalid request" << std::endl;
                return ;
            }
        }
        if (input.length() == 1)
            request = std::stoll(input);
        if (std::cin.good() && request > -1 && request < 8)
            valid = true;
        else
        {
            std::cin.clear();
            std::cout << "Invalid request" << std::endl;
        }
    } while (!valid);
    _Contacts[request].display();
}
