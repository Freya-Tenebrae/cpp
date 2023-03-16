/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2023/03/16 18:27:24 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe():_time_vector_sort(0), _time_list_sort(0)
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
	this->_l = pm.get_list();
	this->_time_vector_sort = pm.get_time_vector_sort();
	this->_time_list_sort = pm.get_time_list_sort();
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

std::list<int>	PmergeMe::get_list() const
{
	return (_l);
}

void	PmergeMe::set_list(std::list<int> l)
{
	_l = l;
}

int	PmergeMe::get_time_vector_sort() const
{
	return (_time_vector_sort);
}

void	PmergeMe::set_time_vector_sort(int time)
{
	_time_vector_sort = time;
}

int	PmergeMe::get_time_list_sort() const
{
	return (_time_list_sort);
}

void	PmergeMe::set_time_list_sort(int time)
{
	_time_list_sort = time;
}

void	PmergeMe::sort_vector()
{
	timespec ts_beg, ts_end;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts_beg);
	merge_insert_sort(_v);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts_end);
	_time_vector_sort = ts_end.tv_nsec - ts_beg.tv_nsec;
}

void	PmergeMe::sort_list()
{
	timespec ts_beg, ts_end;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts_beg);
	merge_insert_sort(_l);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts_end);
	_time_list_sort = ts_end.tv_nsec - ts_beg.tv_nsec;
}

void	PmergeMe::aff_init()
{
	std::cout << "\033[0;32mBefore (vector):\033[0;33m";
	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
		std::cout << " " << *it;
	std::cout << "\033[0m" << std::endl;

	std::cout << "\033[0;32mBefore (list)  :\033[0;33m";
	for (std::list<int>::iterator it = _l.begin(); it != _l.end(); it++)
		std::cout << " " << *it; 
	std::cout << "\033[0m" << std::endl;
}

void	PmergeMe::aff_result()
{
	std::cout << "\033[0;32mTime to process a range of \033[0;33m" << _v.size();
	std::cout << "\033[0;32m elements with \033[0;34mstd::vector \033[0;32m-> \033[0;33m";
	std::cout << _time_vector_sort << "\033[0;32m ns\033[0m" << std::endl;

	std::cout << "\033[0;32mTime to process a range of \033[0;33m" << _l.size();
	std::cout << "\033[0;32m elements with \033[0;34mstd::list   \033[0;32m-> \033[0;33m";
	std::cout << _time_list_sort << "\033[0;32m ns\033[0m" << std::endl;

	std::cout << "\033[0;32mAfter (vector) :\033[0;33m";
	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
		std::cout << " " << *it;
	std::cout << "\033[0m" << std::endl;

	std::cout << "\033[0;32mAfter (list)   :\033[0;33m";
	for (std::list<int>::iterator it = _l.begin(); it != _l.end(); it++)
		std::cout << " " << *it; 
	std::cout << "\033[0m" << std::endl;
}

void	PmergeMe::add_value(int value)
{
	this->_v.push_back(value);
	this->_l.push_back(value);
}

void	PmergeMe::sort()
{
	aff_init();
	sort_vector();
	sort_list();
	aff_result();
}
