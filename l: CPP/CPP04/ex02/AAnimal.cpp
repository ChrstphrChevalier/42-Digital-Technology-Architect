/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:24:39 by waziz             #+#    #+#             */
/*   Updated: 2024/05/22 15:39:39 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AAnimal.hpp"

AAnimal::AAnimal() : Type("Default") {
    std::cout << "AAnimal : Default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string newType) : Type(newType) {
    std::cout << "AAnimal : Custom constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
    *this = other;
    std::cout << "AAnimal : Copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& affect) {
    if (this != &affect)
        Type = affect.Type;
    return (*this);
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal : destructor called" << std::endl;
}

void    AAnimal::makeSound() const{
    std::cout << "AAnimal : . . . " << std::endl;
}

std::string AAnimal::getType() const {
    return Type;
}

void    AAnimal::setType(std::string newType) {
    Type = newType;
}