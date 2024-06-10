/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:48:57 by waziz             #+#    #+#             */
/*   Updated: 2024/05/14 12:30:00 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static void    destroyer(Zombie *z, int i)
{
    std::string tmp;
    tmp = z->getName();
    i += 1;
    std::cout << tmp << " - " << i << " is eliminated." << std::endl;
}

void    comes_out(int n)
{
    Zombie *Horde = new Zombie[n];

    for (int i = 0; i < n; i++)
        Horde[i].setName("Zombie");
    for (int i = 0; i < n; i++)
        Horde[i].announce(i);
    std::cout << std::endl;
    std::cout << "▄︻デ══━一  SNIPER IN POSITION  一━═デ︻▄" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < n; i++)
        destroyer(&Horde[i], i);
    delete [] Horde;
}
