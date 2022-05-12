/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:45:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/12 12:44:57 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class Harl;

typedef struct	s_complain
{
	std::string	level;
	void (Harl::*complainLevel) (void);
}				t_complain;

class Harl
{
	private:
		static int	const	_nComplain = 4;
		t_complain			_complain[4];

		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
		int	const	getNumberedLevel(std::string level);

	public:
		Harl();
		~Harl();

		void		complain(std::string level);
		void		totalyFiltered(void);
		void		harlFilter(std::string const filter);
};//!Harl

#endif
