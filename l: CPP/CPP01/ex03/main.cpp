/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unnecessary_violence.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:27:34 by waziz             #+#    #+#             */
/*   Updated: 2024/05/14 12:18:12 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"
# include "HumanB.hpp"

int main()
{
    std::cout << std::endl;
    {
        Weapon club = Weapon("crude spiked club");

        HumanA tyson("Tyson", club);
        tyson.attack();
        club.setType("some other type of club");
        tyson.attack();
    }
    std::cout << std::endl;
    {
        Weapon club = Weapon("crude spiked club");

        HumanB nelson("Nelson");
        nelson.attack();

        nelson.setWeapon(club);
        nelson.attack();

        club.setType("some other type of club");
        nelson.attack();
    }
    std::cout << std::endl;
    return (0);
}