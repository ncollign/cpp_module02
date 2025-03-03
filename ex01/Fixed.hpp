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
	Fixed(const int value);              // Nouveau : Constructeur avec un entier
	Fixed(const float value);            // Nouveau : Constructeur avec un flottant
	Fixed(const Fixed &src);            // Constructeur de recopie
	Fixed &operator=(const Fixed &rhs); // Opérateur d'affectation
	~Fixed();                           // Destructeur

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const; // Nouveau : Convertit en float
	int toInt(void) const;     // Nouveau : Convertit en int
};

// Surcharge de l’opérateur <<
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif

