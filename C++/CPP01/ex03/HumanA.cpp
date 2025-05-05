/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:45:24 by waziz             #+#    #+#             */
/*   Updated: 2024/05/14 12:03:23 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& w) : _name(name), _w(w) {}

void    HumanA::attack() const
{
    std::cout << _name << " attacks with their " << _w.getType() << std::endl;
}