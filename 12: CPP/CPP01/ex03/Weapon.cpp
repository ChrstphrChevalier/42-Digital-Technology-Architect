/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:04:16 by waziz             #+#    #+#             */
/*   Updated: 2024/05/14 12:22:59 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon (std::string type) : _type(type) {}

const std::string& Weapon::getType() const
{
    return (_type);
}

void    Weapon::setType(std::string weapon)
{
    _type = weapon;
}