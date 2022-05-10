/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Show.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:45:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/10 18:01:14 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOW_HPP
# define SHOW_HPP

# include <string>
# include <iostream>
# include <fstream>

class Show
{
	private:
		std::string const	_filename1;
		std::string const	_filename2;

	public:
		Show(std::string const filename1, std::string const filename2);
		~Show();

		void	show_all_line();
		void	show_diff();


};//!Show

#endif
