/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:09:13 by ncollign          #+#    #+#             */
/*   Updated: 2025/04/25 11:35:55 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

void test(const std::string& description, const Point& a, const Point& b, const Point& c, const Point& p)
{
    std::cout << description << " : " << (bsp(a, b, c, p) ? "Inside" : "Outside") << std::endl;
}

int main()
{
	// Triangle principal
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);

	// Cas classiques
	Point inside(5.0f, 5.0f);
	Point outside(15.0f, 5.0f);
	Point onEdge(5.0f, 0.0f);
	Point onVertex(0.0f, 0.0f);

	// Cas subtils
	Point almostOnEdge(5.0f, 0.01f);
	Point almostOnVertex(0.01f, 0.01f);
	Point veryFar(100.0f, 100.0f);

	// Triangle dégénéré (aligné)
	Point aFlat(0.0f, 0.0f);
	Point bFlat(5.0f, 0.0f);
	Point cFlat(10.0f, 0.0f);
	Point onFlat(5.0f, 0.0f);
	Point nearFlat(5.0f, 0.001f);

	std::cout << "=== Tests normaux ===" << std::endl;
	test("Inside", a, b, c, inside);
	test("Outside", a, b, c, outside);
	test("On Edge", a, b, c, onEdge);
	test("On Vertex", a, b, c, onVertex);

	std::cout << "\n=== Tests limites ===" << std::endl;
	test("Almost on Edge", a, b, c, almostOnEdge);
	test("Almost on Vertex", a, b, c, almostOnVertex);
	test("Very Far", a, b, c, veryFar);

	std::cout << "\n=== Tests triangle dégénéré ===" << std::endl;
	test("On flat edge", aFlat, bFlat, cFlat, onFlat);
	test("Near flat edge", aFlat, bFlat, cFlat, nearFlat);

	return (0);
}