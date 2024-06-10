/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:44:17 by waziz             #+#    #+#             */
/*   Updated: 2024/05/22 18:33:35 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain()) {
    Type = "Dog";
    std::cout << "Dog : Default constructor called" << std::endl;
}

Dog::Dog(std::string newType) : Animal(newType), _brain(new Brain("Brain")) {
    Type = newType;
    std::cout << "Dog : Custom constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(), _brain(new Brain("Brain")) {
    *this = other;
    std::cout << "Dog : Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& affect) {
    if (this != &affect)
    {
        Type = affect.Type;
        if (_brain)
        {
            delete _brain;
            _brain = new Brain(*affect._brain);
        }
    }
    return (*this);
}

Dog::~Dog() {
    std::cout << "Dog : destructor called" << std::endl;
    delete _brain;
}

void    Dog::makeSound() const {
    std::cout << "Dog : 'Ouaf Ouaf bro'" << std::endl;
}

Brain* Dog::getBrain() const {
    return _brain;
}
