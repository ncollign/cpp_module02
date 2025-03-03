/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:36:27 by ncollign          #+#    #+#             */
/*   Updated: 2025/03/03 13:36:27 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


static Fixed area(Point const a, Point const b, Point const c) {
	return (Fixed(0.5f) * ((a.getX() * (b.getY() - c.getY())) +
	                      (b.getX() * (c.getY() - a.getY())) +
	                      (c.getX() * (a.getY() - b.getY())))).abs();
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed totalArea = area(a, b, c);
	Fixed area1 = area(point, b, c);
	Fixed area2 = area(a, point, c);
	Fixed area3 = area(a, b, point);

	return (totalArea == (area1 + area2 + area3));
}
