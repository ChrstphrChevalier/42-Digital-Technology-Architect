/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:48:00 by waziz             #+#    #+#             */
/*   Updated: 2024/05/22 19:50:36 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

Brain::Brain() {
    _name = "Default";
    _index = 0;
    for (int i = 0; i < 100; i++)
        _ideas[i] = "Empty idea " + std::to_string(i + 1);
    std::cout << "Brain : Default constructor called" << std::endl;
}

Brain::Brain(std::string name) {
    _name = name;
    _index = 0;
    for (int i = 0; i < 100; i++)
        _ideas[i] = "Empty idea " + std::to_string(i + 1);
    std::cout << "Brain : Custom constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    _name = other._name;
    for (int i = 0; i < 100; i++)
        _ideas[i] = other._ideas[i];
    _index = other._index;
    std::cout << "Brain : Copy constructor called" << std::endl;
}

Brain&  Brain::operator=(const Brain& affect) {
    if (this != &affect)
    {
        _name = affect._name;
        _index = affect._index;
        for (int i = 0; i < 100; i++)
            _ideas[i] = affect._ideas[i];
    }
    return (*this);
}

Brain::~Brain() {
    std::cout << "Brain : Destructor called" << std::endl;
}

std::string Brain::getName() const {
    return _name;
}

void    Brain::getIdea(long long n) const {
    if (n > 0 && n < 100)
        for(long long i = 0; i < n; i++)
            std::cout << _ideas[i] << std::endl;
    else
        std::cout << "Invalid parameter." << std::endl;
}

void    Brain::setIdea(std::string idea) {
    _ideas[_index] = idea;
    if (_index < 100)
        _index++;
    else
    {
        std::cout << "My new ideas overwrite the older ones" << std::endl;
        _index = 0;
    }
}
