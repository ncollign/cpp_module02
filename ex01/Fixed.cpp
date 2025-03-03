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

// Constructeur par défaut
Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Constructeur avec un entier
Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits; // Décalage binaire pour convertir en virgule fixe
}

// Constructeur avec un flottant
Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(value * (1 << _fractionalBits)); // Multiplication pour ajuster
}

// Constructeur de recopie
Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// Opérateur d'affectation
Fixed &Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		_fixedPointValue = rhs.getRawBits();
	}
	return *this;
}

// Destructeur
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Conversion en float
float Fixed::toFloat(void) const {
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

// Conversion en int
int Fixed::toInt(void) const {
	return _fixedPointValue >> _fractionalBits;
}

// Récupération de la valeur brute
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointValue;
}

// Modification de la valeur brute
void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}

// Surcharge de l'opérateur <<
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat(); // Affiche la valeur sous forme de float
	return out;
}
