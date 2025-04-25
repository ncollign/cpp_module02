/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:51:54 by ncollign          #+#    #+#             */
/*   Updated: 2025/04/25 11:24:16 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::Point(Point const &other) : _x(other.getX()), _y(other.getY()) {}

Point &Point::operator=(Point const &other)
{
	// Impossible de modifier des const => Operateur = inutile
	(void)other;
	return (*this);
}

Point::~Point() {}

Fixed Point::getX() const
{
	return(this->_x);
}

Fixed Point::getY() const
{
	return(this->_y);
}
