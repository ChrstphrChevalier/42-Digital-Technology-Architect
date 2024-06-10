/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:05:15 by waziz             #+#    #+#             */
/*   Updated: 2024/05/21 12:18:15 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed() : _fixed(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& base) : _fixed(base._fixed) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed&  Fixed::operator=(const Fixed& affect)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &affect)
        setRawBits(affect._fixed);
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_fixed);
}

void    Fixed::setRawBits(const int raw)
{
    _fixed = raw;
}