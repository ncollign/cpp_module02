/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:00:03 by ncollign          #+#    #+#             */
/*   Updated: 2025/04/25 11:23:04 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
	Retourne la valeur de l'angle grâce à la formule du produit vectoriel
	res > 0 : anti-horaire
	res < 0 : horaire
	res = 0 : angle plat (points colinéaires)
*/
float	sign(Point const &p1, Point const &p2, Point const &p3)
{
	float prod_vectoriel;
	
	prod_vectoriel = (p1.getX().toFloat() - p3.getX().toFloat())
			* (p2.getY().toFloat() - p3.getY().toFloat())
			- (p2.getX().toFloat() - p3.getX().toFloat())
			* (p1.getY().toFloat() - p3.getY().toFloat());
			
    return (prod_vectoriel);
}


bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float d1 = sign(point, a, b);
	float d2 = sign(point, b, c);
	float d3 = sign(point, c, a);
	
	bool result = ((d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0));
	
	return (result);
}