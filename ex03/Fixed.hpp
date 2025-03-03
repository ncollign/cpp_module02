/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:08:54 by ncollign          #+#    #+#             */
/*   Updated: 2025/03/03 13:08:54 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

public:
	Fixed();                            // Constructeur par défaut
	Fixed(const int value);              // Constructeur avec un entier
	Fixed(const float value);            // Constructeur avec un flottant
	Fixed(const Fixed &src);            // Constructeur de recopie
	Fixed &operator=(const Fixed &rhs); // Opérateur d'affectation
	~Fixed();                           // Destructeur
	Fixed abs() const;

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	// Opérateurs de comparaison
	bool operator>(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;

	// Opérateurs arithmétiques
	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;

	// Opérateurs d’incrémentation et décrémentation
	Fixed &operator++();   // Pré-incrémentation (++a)
	Fixed operator++(int); // Post-incrémentation (a++)
	Fixed &operator--();   // Pré-décrémentation (--a)
	Fixed operator--(int); // Post-décrémentation (a--)

	// Fonctions statiques min et max
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

// Surcharge de l’opérateur <<
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
