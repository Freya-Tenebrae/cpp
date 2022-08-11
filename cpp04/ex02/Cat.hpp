/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:47:29 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/11 14:55:51 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain* _brain;

	public:
		Cat();
		Cat(const Cat &cat);
		~Cat();
		Cat			&operator=(const Cat &cat);

		Brain const			*getBrain()const;
		void				setBrain(const Brain *brain);
		std::string const	getIdea(int i)const;
		void				setIdea(std::string const idea, int i);

		virtual void	makeSound()const;

};//!Animal
/* ************************************************************************** */
/* OPERATOR OVERLOADING                                                       */
/* ************************************************************************** */

#endif
