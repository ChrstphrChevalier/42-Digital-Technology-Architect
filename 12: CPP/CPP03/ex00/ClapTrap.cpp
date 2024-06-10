/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:23:03 by waziz             #+#    #+#             */
/*   Updated: 2024/05/21 18:42:22 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoint(10), _Energy(10), _attackDamage(0) {
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _hitPoint(10), _Energy(10), _attackDamage(0) {
    if (name.empty())
        _name = "EmptyBoy";
    else
        _name = name;
    std::cout << "ClapTrap Custom constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& copy) {
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& affect) {
    if (this != &affect)
    {
        _name = affect._name;
        _hitPoint = affect._hitPoint;
        _Energy = affect._Energy;
        _attackDamage = affect._attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap Destructor called." << std::endl;
}

void        ClapTrap::attack(const std::string& target) {
    if (_hitPoint > 0 && _Energy > 0)
    {
        std::cout << "ClapTrap : " << _name << " attack " << target << " causing " << _attackDamage << " Points of damage." << std::endl;
        _Energy -= 1;
    }
    else
        std::cout << "ClapTrap : " << _name << " try to attack " << target << " but failed. (Not enough hitPoint)" << std::endl;
}

void        ClapTrap::takeDamage(unsigned int amount) {
    if (amount >= _hitPoint)
    {
        _hitPoint = 0;
        std::cout << "ClapTrap : " << _name << " take " << amount << " damage. He died." << std::endl;
    }
    else
    {
        _hitPoint -= amount;
        std::cout << "ClapTrap : " << _name << " take " << amount << " damage." << std::endl;
    }
}

void        ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoint > 0 && _Energy > 0)
    {
        _hitPoint += amount;
        _Energy -= 1;
        std::cout << "ClapTrap : " << _name << " healed itself " << amount << " point." << std::endl;
    }
    else
        std::cout << "ClapTrap : " << _name << " cannot healed itself " << amount << " point(dead or no energy)." << std::endl;
}

void        ClapTrap::setName(std::string newName) {
    if (newName.empty())
        _name = "EmptyBoy";
    else
        _name = newName;
}

std::string ClapTrap::getName() const {
    return _name;
}

void        ClapTrap::getProfil() const {
    std::cout << _name << " has " << _hitPoint << " lifePoints and " << _Energy << " energyPoints." << std::endl;
}