/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:09:13 by ncollign          #+#    #+#             */
/*   Updated: 2025/03/03 13:09:13 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a after pre-increment: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a after post-increment: " << a << std::endl;

	std::cout << "b: " << b << std::endl;
	std::cout << "Max(a, b): " << Fixed::max(a, b) << std::endl;

	return 0;
}
