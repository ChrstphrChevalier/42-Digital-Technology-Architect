/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <waziz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:05:15 by waziz             #+#    #+#             */
/*   Updated: 2024/05/19 16:28:34 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed() : _fixed(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _fixed(value << _bit) {
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _fixed(std::roundf(value * (1 <<  _bit))) {
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) : _fixed(copy._fixed) {
    // std::cout << "Copy constructor called" << std::endl;
}

Fixed&  Fixed::operator=(const Fixed& affect) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &affect)
        _fixed = affect._fixed;
    return (*this);
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

bool Fixed::operator>(const Fixed& other) const {
    return _fixed > other._fixed;
}

bool Fixed::operator<(const Fixed& other) const {
    return _fixed < other._fixed;
}

bool Fixed::operator>=(const Fixed& other) const {
    return _fixed >= other._fixed;
}

bool Fixed::operator<=(const Fixed& other) const {
    return _fixed <= other._fixed;
}

bool Fixed::operator==(const Fixed& other) const {
    return _fixed == other._fixed;
}

bool Fixed::operator!=(const Fixed& other) const {
    return _fixed != other._fixed;
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.toFloat() != 0)
        return Fixed(toFloat() / other.toFloat());
    else {
        std::cerr << "Error division by zero" << std::endl;
        return Fixed();
    }
}

Fixed&    Fixed::operator++(void)
{
    setRawBits(getRawBits() + 1);
    return (*this);
}

Fixed&    Fixed::operator--(void)
{
    setRawBits(getRawBits() - 1);
    return (*this);
}

Fixed    Fixed::operator++(int)
{
    Fixed    prev = *this;
    setRawBits(getRawBits() + 1);
    return (prev);
}

Fixed    Fixed::operator--(int)
{
    Fixed    prev = *this;
    setRawBits(getRawBits() - 1);
    return (prev);
}

Fixed&  Fixed::min(Fixed& a, Fixed& b) {
    return ((a < b) ? a : b);
}

const Fixed&  Fixed::min(const Fixed& a, const Fixed& b) {
    return ((a < b) ? a : b);
}

Fixed&  Fixed::max(Fixed& a, Fixed& b) {
    return ((a > b) ? a : b);
}

const Fixed&  Fixed::max(const Fixed& a, const Fixed& b) {
    return ((a > b) ? a : b);
}

int Fixed::getRawBits() const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (_fixed);
}

void    Fixed::setRawBits(const int raw)
{
    _fixed = raw;
}

float   Fixed::toFloat()    const
{
    return (static_cast<float>(_fixed) / (1 << _bit));
}

int Fixed::toInt()  const
{
    return (_fixed >> _bit);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}