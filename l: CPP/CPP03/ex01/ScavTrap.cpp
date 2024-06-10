/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:38:12 by waziz             #+#    #+#             */
/*   Updated: 2024/05/21 21:07:14 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    _name = "Default";
    _hitPoint = 100;
    _Energy = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _name = name;
    _hitPoint = 100;
    _Energy = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap Custom constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& copy) {
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    *this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& affect) {
    if (this != &affect)
    {
        _name = affect._name;
        _hitPoint = affect._hitPoint;
        _Energy = affect._Energy;
        _attackDamage = affect._attackDamage;
    }
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called." << std::endl;
}

void    ScavTrap::guardGate() {
    if (_hitPoint > 0)
        std::cout << "ScavTrap : " << _name << " has Guardian mode activated." << std::endl;
    else
        std::cout << "ScavTrap : " << _name << " is dead." << std::endl;
}