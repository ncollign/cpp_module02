/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:36:15 by ncollign          #+#    #+#             */
/*   Updated: 2025/03/03 13:36:15 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructeur par défaut
Point::Point() : _x(0), _y(0) {}

// Constructeur avec coordonnées
Point::Point(const float x, const float y) : _x(x), _y(y) {}

// Constructeur de recopie
Point::Point(const Point &src) : _x(src._x), _y(src._y) {}

// Opérateur d'affectation (inutile car tout est `const`)
Point &Point::operator=(const Point &rhs) {
	(void)rhs;
	return *this;
}

// Destructeur
Point::~Point() {}

// Accesseurs
Fixed Point::getX() const { return _x; }
Fixed Point::getY() const { return _y; }
