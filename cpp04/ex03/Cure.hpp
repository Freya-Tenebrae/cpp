/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:59:43 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/09 16:38:14 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"


class Cure : public AMateria
{
	public:
		Cure();
		// Cure(std::string const & type);
		Cure(const Cure &cure);
		~Cure();
		Cure			&operator=(const Cure &cure);

		virtual AMateria* clone() const;
		virtual void use(/*ICharacter& target*/) const;

};//!Cure

#endif