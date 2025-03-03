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

#include "Point.hpp"

int main() {
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 5);
	Point p1(5, 2);  // Devrait être à l'intérieur
	Point p2(10, 10); // Devrait être à l'extérieur

	std::cout << "p1 inside triangle: " << (bsp(a, b, c, p1) ? "Yes" : "No") << std::endl;
	std::cout << "p2 inside triangle: " << (bsp(a, b, c, p2) ? "Yes" : "No") << std::endl;

	return 0;
}
