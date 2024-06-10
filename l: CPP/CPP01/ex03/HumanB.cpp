/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:09:26 by waziz             #+#    #+#             */
/*   Updated: 2024/05/14 12:25:34 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB (std::string name) : _name(name) {
    _w = NULL;
}

void    HumanB::setWeapon(Weapon& w)
{
    _w = &w;
}

void    HumanB::attack() const
{
    if (!_w || _w->getType() == "")
        std::cout << _name << " cannot attack without a weapon." << std::endl;
    else
        std::cout << _name << " attacks with their " << _w->getType() << std::endl;
}