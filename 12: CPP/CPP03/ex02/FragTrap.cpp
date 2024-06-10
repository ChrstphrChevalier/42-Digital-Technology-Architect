/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:38:12 by waziz             #+#    #+#             */
/*   Updated: 2024/05/21 22:03:14 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    _name = "Default";
    _hitPoint = 100;
    _Energy = 100;
    _attackDamage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _name = name;
    _hitPoint = 100;
    _Energy = 100;
    _attackDamage = 30;
    std::cout << "FragTrap Custom constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap& copy) {
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap& affect) {
    if (this != &affect)
    {
        _name = affect._name;
        _hitPoint = affect._hitPoint;
        _Energy = affect._Energy;
        _attackDamage = affect._attackDamage;
    }
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called." << std::endl;
}

void    FragTrap::highFivesGuys() {
    if (_hitPoint > 0 && _Energy > 0)
        std::cout << _name << "AAaammmmaaazzziiiinng !!! High five bro!" << std::endl;
    else
        std::cout << _name << " cannot High Five, is dead." << std::endl; 
}