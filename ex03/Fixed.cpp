/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:08:50 by ncollign          #+#    #+#             */
/*   Updated: 2025/04/25 10:25:46 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _rawBits(0)
{
	
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{

}

Fixed::Fixed(const int value)
{
	this->_rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	_rawBits = roundf(value * (1 << _fractionalBits));
}

int Fixed::getRawBits() const
{
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

float Fixed::toFloat() const
{
	float result = this->_rawBits / (float)(1 << _fractionalBits);
	return (result);
}

int Fixed::toInt() const
{
	int result = this->_rawBits >> _fractionalBits;
	return (result);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->_rawBits > other._rawBits);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->_rawBits < other._rawBits);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->_rawBits >= other._rawBits);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->_rawBits <= other._rawBits);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->_rawBits == other._rawBits);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->_rawBits != other._rawBits);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed &Fixed::operator++()
{
	this->_rawBits++;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_rawBits++;
	return(temp);
}

Fixed &Fixed::operator--()
{
	this->_rawBits--;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_rawBits--;
	return(temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return(a);
	else
		return(b);
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return(a);
	else
		return(b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return(a);
	else
		return(b);
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return(a);
	else
		return(b);
}