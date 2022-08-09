/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:59:41 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/09 16:38:19 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"


class Ice : public AMateria
{
	public:
		Ice();
		// Ice(std::string const & type);
		Ice(const Ice &ice);
		~Ice();
		Ice			&operator=(const Ice &ice);

		virtual AMateria* clone() const;
		virtual void use(/*ICharacter& target*/) const;

};//!Ice

#endif