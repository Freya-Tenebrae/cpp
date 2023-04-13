/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/31 17:47:55 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <iostream>
# include <fstream>
# include <cstring>
# include <sstream>
# include <iomanip>
# include <time.h>

class PmergeMe
{
	private:
		std::vector<int>	_v;
		std::deque<int>		_d;
		int					_time_vector_sort;
		int					_time_deque_sort;

		void				mi_sort_deque();
		void				mi_sort_vector();
		void				sort_vector();
		void				sort_deque();
		void				aff_init();
		void				aff_result();

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &pm);
		~PmergeMe();

		PmergeMe		&operator=(const PmergeMe &pm);

		std::vector<int>	get_vector() const;
		void				set_vector(std::vector<int> v);

		std::deque<int>		get_deque() const;
		void				set_deque(std::deque<int> d);

		int					get_time_vector_sort() const;
		void				set_time_vector_sort(int time);

		int					get_time_deque_sort() const;
		void				set_time_deque_sort(int time);

		void				add_value(int value);
		void				sort();

};//!PmergeMe


#endif
