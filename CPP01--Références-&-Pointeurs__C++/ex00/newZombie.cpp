/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:30:14 by waziz             #+#    #+#             */
/*   Updated: 2024/05/13 21:24:29 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    Zombie  *newZombie = new Zombie;
    newZombie->setName(name);
    return (newZombie);
}

void    destroyer(Zombie *z)
{
    std::string tmp;
    tmp = z->getName();
    std::cout << tmp << " is eliminated." << std::endl;
    delete z;
}