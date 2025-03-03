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

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    Fixed();                        // Constructeur par défaut
    Fixed(const Fixed &src);        // Constructeur de recopie
    Fixed &operator=(const Fixed &rhs); // Opérateur d'affectation
    ~Fixed();                       // Destructeur

    int getRawBits(void) const;     // Récupère la valeur brute
    void setRawBits(int const raw); // Définit la valeur brute
};

#endif
