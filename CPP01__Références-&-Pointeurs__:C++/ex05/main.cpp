/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:39:44 by waziz             #+#    #+#             */
/*   Updated: 2024/05/14 16:50:56 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int main()
{
    Harl        H;
    std::string level;

    do
    {
        std::cout << "Enter level : ";
        std::cin >> level;
        H.complain(level);
    } while (level.compare("exit"));
    return (0);
}