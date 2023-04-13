/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2023/04/04 16:10:49 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe():_time_vector_sort(0), _time_deque_sort(0)
{
	std::cout << "\033[0;35mPmergeMe is created\033[0m" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &pm)
{
	*this = pm;
	std::cout << "\033[0;35mPmergeMe is duplicated\033[0m" << std::endl;
}

PmergeMe::~PmergeMe()
{
	std::cout << "\033[0;35mPmergeMe is destroyed\033[0m" << std::endl;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &pm)
{
	this->_v = pm.get_vector();
	this->_d = pm.get_deque();
	this->_time_vector_sort = pm.get_time_vector_sort();
	this->_time_deque_sort = pm.get_time_deque_sort();
	return (*this);
}

std::vector<int>	PmergeMe::get_vector() const
{
	return (_v);
}

void	PmergeMe::set_vector(std::vector<int> v)
{
	_v = v;
}

std::deque<int>	PmergeMe::get_deque() const
{
	return (_d);
}

void	PmergeMe::set_deque(std::deque<int> l)
{
	_d = l;
}

int	PmergeMe::get_time_vector_sort() const
{
	return (_time_vector_sort);
}

void	PmergeMe::set_time_vector_sort(int time)
{
	_time_vector_sort = time;
}

int	PmergeMe::get_time_deque_sort() const
{
	return (_time_deque_sort);
}

void	PmergeMe::set_time_deque_sort(int time)
{
	_time_deque_sort = time;
}

void	PmergeMe::mi_sort_deque()
{
	std::deque<std::deque<int> >		d_pairs;
	std::deque<int>						d_pair;

	for (std::deque<int>::iterator it = _d.begin(); it != _d.end(); it++)
	{
		d_pair.push_back(*it);
		it++;
		if (it != _d.end())
			d_pair.push_back(*it);
		d_pairs.push_back(d_pair);
		d_pair.clear();
		if (it == _d.end())
			break ;
	}

	for (std::deque<std::deque<int> >::iterator it = d_pairs.begin(); it != d_pairs.end(); it++)
	{
		if (it->size() > 1 && (*it)[0] < (*it)[1])
		{
			int	tmp_val = (*it)[0];
			(*it)[0] = (*it)[1];
			(*it)[1] = tmp_val;
		}
	}

	for (std::deque<std::deque<int> >::iterator it = d_pairs.begin(); it != d_pairs.end(); it++)
	{
		for (std::deque<std::deque<int> >::iterator it_2 = it + 1; it_2 != d_pairs.end(); it_2++)
		{
			if ((*it)[0] > (*it_2)[0])
			{
				int	tmp_val = (*it)[0];
				(*it)[0] = (*it_2)[0];
				(*it_2)[0] = tmp_val;
			}
		}
	}

	for (std::deque<std::deque<int> >::iterator it = d_pairs.begin(); it != d_pairs.end(); it++)
	{
		if (it->size() > 1)
		{
			std::deque<int> new_v_pair;
			new_v_pair.push_back((*it)[1]);
			it->erase(it->begin() + 1);
			for (std::deque<std::deque<int> >::iterator it_2 = d_pairs.begin(); it_2 != d_pairs.end(); it_2++)
			{
				if ((*it)[1] < (*it_2)[0])
				{
					it = d_pairs.insert(it_2, new_v_pair);
					break;
				}
				else if (it_2 + 1 == d_pairs.end())
				{
					it = d_pairs.insert(it_2 + 1, new_v_pair);
					break;
				}
			}
		}
	}

	_d.clear();

	for (std::deque<std::deque<int> >::iterator it = d_pairs.begin(); it != d_pairs.end(); it++)
		_d.push_back((*it)[0]);
}

void	PmergeMe::mi_sort_vector()
{
	std::vector<std::vector<int> >			v_pairs;
	std::vector<int>						v_pair;

	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
	{
		v_pair.push_back(*it);
		it++;
		if (it != _v.end())
			v_pair.push_back(*it);
		v_pairs.push_back(v_pair);
		v_pair.clear();
		if (it == _v.end())
			break ;
	}

	for (std::vector<std::vector<int> >::iterator it = v_pairs.begin(); it != v_pairs.end(); it++)
	{
		if (it->size() > 1 && (*it)[0] < (*it)[1])
		{
			int	tmp_val = (*it)[0];
			(*it)[0] = (*it)[1];
			(*it)[1] = tmp_val;
		}
	}

	for (std::vector<std::vector<int> >::iterator it = v_pairs.begin(); it != v_pairs.end(); it++)
	{
		for (std::vector<std::vector<int> >::iterator it_2 = it + 1; it_2 != v_pairs.end(); it_2++)
		{
			if ((*it)[0] > (*it_2)[0])
			{
				int	tmp_val = (*it)[0];
				(*it)[0] = (*it_2)[0];
				(*it_2)[0] = tmp_val;
			}
		}
	}

	for (std::vector<std::vector<int> >::iterator it = v_pairs.begin(); it != v_pairs.end(); it++)
	{
		if (it->size() > 1)
		{
			std::vector<int> new_v_pair;
			new_v_pair.push_back((*it)[1]);
			it->erase(it->begin() + 1);
			for (std::vector<std::vector<int> >::iterator it_2 = v_pairs.begin(); it_2 != v_pairs.end(); it_2++)
			{
				if ((*it)[1] < (*it_2)[0])
				{
					it = v_pairs.insert(it_2, new_v_pair);
					break;
				}
				else if (it_2 + 1 == v_pairs.end())
				{
					it = v_pairs.insert(it_2 + 1, new_v_pair);
					break;
				}
			}
		}
	}

	_v.clear();

	for (std::vector<std::vector<int> >::iterator it = v_pairs.begin(); it != v_pairs.end(); it++)
		_v.push_back((*it)[0]);
}


void	PmergeMe::sort_vector()
{
	timespec ts_beg, ts_end;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts_beg);
	mi_sort_vector();
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts_end);
	_time_vector_sort = ts_end.tv_nsec - ts_beg.tv_nsec;
}

void	PmergeMe::sort_deque()
{
	timespec ts_beg, ts_end;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts_beg);
	mi_sort_deque();
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts_end);
	_time_deque_sort = ts_end.tv_nsec - ts_beg.tv_nsec;
}

void	PmergeMe::aff_init()
{
	std::cout << "\033[0;32mBefore (vector):\033[0;33m";
	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
		std::cout << " " << *it;
	std::cout << "\033[0m" << std::endl;

	std::cout << "\033[0;32mBefore (deque) :\033[0;33m";
	for (std::deque<int>::iterator it = _d.begin(); it != _d.end(); it++)
		std::cout << " " << *it; 
	std::cout << "\033[0m" << std::endl;
}

void	PmergeMe::aff_result()
{
	std::cout << "\033[0;32mTime to process a range of \033[0;33m" << _v.size();
	std::cout << "\033[0;32m elements with \033[0;34mstd::vector \033[0;32m-> \033[0;33m";
	std::cout << _time_vector_sort / 1000 << "." << _time_vector_sort % 1000 << "\033[0;32m µs\033[0m" << std::endl;

	std::cout << "\033[0;32mTime to process a range of \033[0;33m" << _d.size();
	std::cout << "\033[0;32m elements with \033[0;34mstd::deque  \033[0;32m-> \033[0;33m";
	std::cout << _time_deque_sort / 1000 << "." << _time_deque_sort % 1000 << "\033[0;32m µs\033[0m" << std::endl;

	std::cout << "\033[0;32mAfter (vector) :\033[0;33m";
	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
		std::cout << " " << *it;
	std::cout << "\033[0m" << std::endl;

	std::cout << "\033[0;32mAfter (deque)  :\033[0;33m";
	for (std::deque<int>::iterator it = _d.begin(); it != _d.end(); it++)
		std::cout << " " << *it; 
	std::cout << "\033[0m" << std::endl;
}

void	PmergeMe::add_value(int value)
{
	this->_v.push_back(value);
	this->_d.push_back(value);
}

void	PmergeMe::sort()
{
	aff_init();
	sort_vector();
	sort_deque();
	aff_result();
}
