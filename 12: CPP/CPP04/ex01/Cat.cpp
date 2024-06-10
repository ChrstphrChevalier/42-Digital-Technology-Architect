/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:52:13 by waziz             #+#    #+#             */
/*   Updated: 2024/05/22 18:34:39 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain()) {
    Type = "Cat";
    std::cout << "Cat : Default constructor called" << std::endl;
}

Cat::Cat(std::string newType) : Animal(newType), _brain(new Brain("Brain")) {
    Type = newType;
    std::cout << "Cat : Custom constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(), _brain(new Brain("Brain")) {
    *this = other;
    std::cout << "Cat : Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& affect) {
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

Cat::~Cat() {
    std::cout << "Cat : destructor called" << std::endl;
    delete _brain;
}

void    Cat::makeSound() const {
    std::cout << "Cat : 'Miiiiaaaaoouuu bitch'" << std::endl;
}

Brain*      Cat::getBrain() const {
    return _brain;
}
