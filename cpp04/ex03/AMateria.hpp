/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:59:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/10 18:44:27 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria();
		// AMateria(std::string const & type);
		AMateria(const AMateria &aMateria);
		virtual ~AMateria();
		AMateria		&operator=(const AMateria &aMateria);

		std::string const &		getType() const;
		void					setType(std::string const type);
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) const = 0;

};//!AMateria

#endif