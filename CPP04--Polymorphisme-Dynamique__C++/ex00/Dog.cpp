/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:44:17 by waziz             #+#    #+#             */
/*   Updated: 2024/05/22 15:39:58 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
    Type = "Dog";
    std::cout << "Dog : Default constructor called" << std::endl;
}

Dog::Dog(std::string newType) : Animal(newType) {
    Type = newType;
    std::cout << "Dog : Custom constructor called" << std::endl;
}

Dog::Dog(const Dog& other) {
    *this = other;
    std::cout << "Dog : Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& affect) {
    if (this != &affect)
        Type = affect.Type;
    return (*this);
}

Dog::~Dog() {
    std::cout << "Dog : destructor called" << std::endl;
}

void    Dog::makeSound() const {
    std::cout << "Dog : 'Ouaf Ouaf bro'" << std::endl;
}

std::string Dog::getType() const {
    return Type;
}

void    Dog::setType(std::string newType) {
    Type = newType;
}