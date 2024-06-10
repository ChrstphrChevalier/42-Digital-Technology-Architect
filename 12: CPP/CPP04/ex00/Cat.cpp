/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:52:13 by waziz             #+#    #+#             */
/*   Updated: 2024/05/22 15:39:49 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat() : Animal() {
    Type = "Cat";
    std::cout << "Cat : Default constructor called" << std::endl;
}

Cat::Cat(std::string newType) : Animal(newType) {
    Type = newType;
    std::cout << "Cat : Custom constructor called" << std::endl;
}

Cat::Cat(const Cat& other) {
    *this = other;
    std::cout << "Cat : Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& affect) {
    if (this != &affect)
        Type = affect.Type;
    return (*this);
}

Cat::~Cat() {
    std::cout << "Cat : destructor called" << std::endl;
}

void    Cat::makeSound() const {
    std::cout << "Cat : 'Miiiiaaaaoouuu bitch'" << std::endl;
}

std::string Cat::getType() const {
    return Type;
}

void    Cat::setType(std::string newType) {
    Type = newType;
}