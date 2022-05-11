/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Switch.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:45:33 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/11 10:37:19 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWITCH_HPP
# define SWITCH_HPP

# include <string>
# include <iostream>
# include <fstream>

class Switch
{
	private:
		std::string const	_filename;
		std::string const	_strToReplace;
		std::string const	_strReplacing;

		bool	fill_buffer(std::string *buffer);
		void	switching(std::string *buffer);
		void	createNew_file(std::string buffer);

	public:
		Switch(std::string const filename, std::string const s1, \
														std::string const s2);
		~Switch();

		void		replacing();

};//!Switch

#endif
