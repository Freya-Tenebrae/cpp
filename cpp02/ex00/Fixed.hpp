/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/13 16:07:15 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class Fixed
{
	private:
		int					_rawBits;
		static const int	_number = 8;

	public:
		Fixed();
		Fixed(const Fixed &f);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
		Fixed &operator=(const Fixed &f);
};//!Fixed

#endif

// • Membres prive :
// Un entier pour stocker la valeur du nombre en virgule fixe.
// ◦ Un entier constant statique pour stocker le nombre de bits de la partie
// fractionnaire, et dont la valeur sera toujours le littéral entier 8.

// • Membres publics :
// ◦ Un constructeur par défaut qui initialisera la valeur du nombre à virgule fixe
// à 0.
// ◦ Un constructeur de recopie.
// ◦ Une surcharge de l’opérateur d’affectation.
// ◦ Un destructeur.
// ◦ Une fonction membre int getRawBits( void ) const;
// qui retourne la valeur du nombre à virgule fixe sans la convertir.
// ◦ Une fonction membre void setRawBits( int const raw );
// qui initialise la valeur du nombre à virgule fixe avec celle passée en paramètre.