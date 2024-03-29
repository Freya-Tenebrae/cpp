/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/09 15:53:27 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal();
		Animal(const Animal &animal);
		virtual ~Animal();
		Animal		&operator=(const Animal &animal);

		std::string const	getType()const;
		void				setType(std::string const type);

		virtual void		makeSound()const;

};//!Animal
/* ************************************************************************** */
/* OPERATOR OVERLOADING                                                       */
/* ************************************************************************** */

#endif
