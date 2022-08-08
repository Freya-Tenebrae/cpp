/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:59:43 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/08 16:47:17 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"


class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cat &cat);
		~Cure();
		virtual Cure			&operator=(const Cat &cat);

};//!Animal