/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:51:26 by waziz             #+#    #+#             */
/*   Updated: 2024/05/22 15:41:12 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    Type = "WrongCat";
    std::cout << "WrongCat : Default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string newType) : WrongAnimal(newType) {
    Type = newType;
    std::cout << "WrongCat : Custom constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
    *this = other;
    std::cout << "WrongCat : Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& affect) {
    if (this != &affect)
    {
        Type = affect.Type;
        _isFalse = affect._isFalse;
    }
    return (*this);
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

void    WrongCat::makeSound() const {
    if (_isFalse)
        std::cout << "WrongCat : 'Miiiiaaaaoouuu bitch'" << std::endl;
    else
        WrongAnimal::makeSound();
}

std::string WrongCat::getType() const {
    return Type;
}

void    WrongCat::setType(std::string newType) {
    Type = newType;
}

void    WrongCat::set_isFalse(bool iF) {
    _isFalse = iF;
}