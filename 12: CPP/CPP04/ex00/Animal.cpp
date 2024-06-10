/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:24:39 by waziz             #+#    #+#             */
/*   Updated: 2024/05/22 15:39:39 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

Animal::Animal() : Type("Default") {
    std::cout << "Animal : Default constructor called" << std::endl;
}

Animal::Animal(std::string newType) : Type(newType) {
    std::cout << "Animal : Custom constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
    *this = other;
    std::cout << "Animal : Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& affect) {
    if (this != &affect)
        Type = affect.Type;
    return (*this);
}

Animal::~Animal() {
    std::cout << "Animal : destructor called" << std::endl;
}

void    Animal::makeSound() const{
    std::cout << "Animal : . . . " << std::endl;
}

std::string Animal::getType() const {
    return Type;
}

void    Animal::setType(std::string newType) {
    Type = newType;
}