/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieland.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:00:51 by waziz             #+#    #+#             */
/*   Updated: 2024/05/13 22:37:58 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int     horde;
    bool    valid = false;

    do
    {
        std::cout << "How many zombies are there in the horde?" << std::endl;
        std::cout << "> ";
        std::cin >> horde;
        if (std::cin.good() && horde > 1)
            valid = true;
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << " !! ONLY NUMBERS GREATER THAN ONE !!" << std::endl;
        }
    } while (!valid);
    comes_out(horde);
    return (0);
}