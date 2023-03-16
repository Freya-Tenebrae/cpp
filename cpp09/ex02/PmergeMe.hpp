/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/16 18:28:25 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <string>
# include <iostream>
# include <fstream>
# include <cstring>
# include <sstream>
# include <iomanip>
# include <time.h>

template <typename T>
void	merge_insert_sort(T &t)
{
	typename T::iterator itr;
	typename T::iterator itrend = t.end();

	for (itr = t.begin(); itr != itrend; ++itr)
    {
        *itr += 1;
    }
}

class PmergeMe
{
	private:
		std::vector<int>	_v;
		std::list<int>		_l;
		int					_time_vector_sort;
		int					_time_list_sort;

		void				sort_vector();
		void				sort_list();
		void				aff_init();
		void				aff_result();

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &pm);
		~PmergeMe();

		PmergeMe		&operator=(const PmergeMe &pm);

		std::vector<int>	get_vector() const;
		void				set_vector(std::vector<int> v);

		std::list<int>		get_list() const;
		void				set_list(std::list<int> l);

		int					get_time_vector_sort() const;
		void				set_time_vector_sort(int time);

		int					get_time_list_sort() const;
		void				set_time_list_sort(int time);

		void				add_value(int value);
		void				sort();

};//!PmergeMe


#endif
