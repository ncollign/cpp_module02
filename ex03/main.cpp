/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:09:13 by ncollign          #+#    #+#             */
/*   Updated: 2025/04/25 10:36:01 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;

	a++;
	std::cout << a << std::endl;
	std::cout << "Test incrémentation : " << ++a << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	
	return 0;

	/*
		_fractionalBits est égal à 8
		Ce qui signifie qu'on réserve 8 bits pour la partie fractionnaire.
		=> 2^8 = 256
		Chaque unité est donc divisé par 256

		L'incrémentation ajoute donc : 1 / 256 = 0.00390625
	*/
}
