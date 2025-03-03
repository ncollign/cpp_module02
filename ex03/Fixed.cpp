/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:08:50 by ncollign          #+#    #+#             */
/*   Updated: 2025/03/03 13:08:50 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// Constructeur par défaut
Fixed::Fixed() : _fixedPointValue(0) {

}

// Constructeur avec un entier
Fixed::Fixed(const int value) {
	this->_fixedPointValue = value << _fractionalBits;
}

// Constructeur avec un flottant
Fixed::Fixed(const float value) {
	this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

// Constructeur de recopie
Fixed::Fixed(const Fixed &src) {
	*this = src;
}

// Opérateur d’affectation
Fixed &Fixed::operator=(const Fixed &rhs) {
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

// Destructeur
Fixed::~Fixed() {

}

// Conversion en float
float Fixed::toFloat(void) const {
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

// Conversion en int
int Fixed::toInt(void) const {
	return this->_fixedPointValue >> _fractionalBits;
}

// Surcharge de l'opérateur <<
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

int Fixed::getRawBits(void) const {
	return this->_fixedPointValue;
}

Fixed Fixed::abs() const {
	return Fixed(this->toFloat() < 0 ? -this->toFloat() : this->toFloat());
}

// Opérateurs de comparaison
bool Fixed::operator>(const Fixed &rhs) const {
	return this->_fixedPointValue > rhs._fixedPointValue;
}

bool Fixed::operator<(const Fixed &rhs) const {
	return this->_fixedPointValue < rhs._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &rhs) const {
	return this->_fixedPointValue >= rhs._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return this->_fixedPointValue <= rhs._fixedPointValue;
}

bool Fixed::operator==(const Fixed &rhs) const {
	return this->_fixedPointValue == rhs._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return this->_fixedPointValue != rhs._fixedPointValue;
}

// Opérateurs arithmétiques
Fixed Fixed::operator+(const Fixed &rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	if (rhs._fixedPointValue == 0) {
		std::cerr << "Error: Division by zero" << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / rhs.toFloat());
}

// Opérateurs d’incrémentation et décrémentation
Fixed &Fixed::operator++() {
	this->_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->_fixedPointValue++;
	return temp;
}

Fixed &Fixed::operator--() {
	this->_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->_fixedPointValue--;
	return temp;
}

// Fonctions min et max
Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}
