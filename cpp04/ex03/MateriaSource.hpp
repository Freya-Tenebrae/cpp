/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:54:39 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/10 15:23:17 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_materiaContainer[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &MateriaSource);
		~MateriaSource();
		MateriaSource		&operator=(const MateriaSource &MateriaSource);

		virtual void		learnMateria(AMateria* aMateria);
		virtual AMateria*	createMateria(std::string const & type);

};//!MateriaSource

#endif