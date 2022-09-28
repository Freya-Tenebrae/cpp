/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/28 19:20:19 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"
# include <list>

int main(void)
{
	std::cout << "\033[1;36m-----mutantStack tests-----\033[0m" << std::endl;
	MutantStack<int> mstack;
	std::list<int> l;

	// push 5 and 17
	mstack.push(5);
	l.push_back(5);
	mstack.push(17);
	l.push_back(17);

	// show top / back
	std::cout << "\033[1;36mtop and back (5 | 17)\033[0m" << std::endl;
	std::cout << "\033[0;32mmutantstack top : \033[0;33m" << mstack.top();
	std::cout << "\033[0m" << std::endl;
	std::cout << "\033[0;32mlist back       : \033[0;33m" << l.back();
	std::cout << "\033[0m" << std::endl;

	// pop / pop_back
	mstack.pop();
	l.pop_back();

	// show size
	std::cout << "\033[1;36mshow size (5)\033[0m" << std::endl;
	std::cout << "\033[0;32mmutantstack size : \033[0;33m" << mstack.size();
	std::cout << "\033[0m" << std::endl;
	std::cout << "\033[0;32mlist size        : \033[0;33m" << l.size();
	std::cout << "\033[0m" << std::endl;

	// push 3 5 737 42 6 0
	mstack.push(3);
	l.push_back(3);
	mstack.push(5);
	l.push_back(5);
	mstack.push(737);
	l.push_back(737);
	mstack.push(42);
	l.push_back(42);
	mstack.push(6);
	l.push_back(6);
	mstack.push(0);
	l.push_back(0);

	// create iterator
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::list<int>::iterator itl = l.begin();
	std::list<int>::iterator itel = l.end();

	// iterate iterator
	++it;
	--it;
	++itl;
	--itl;

	// aff all mutantStack / List with iterator
	std::cout << "\033[1;36mShow all container (5 | 3 | 5 | 737 | 42 | 6 | 0)\033[0m" << std::endl;
	std::cout << "\033[0;33mmutant stack \033[0;32m|\033[0;33m list\033[0m" << std::endl;
	while (it != ite || itl != itel)
	{
	std::cout << "\033[0;33m" << *it << "\033[0;32m|\033[0;33m" << *itl << "\033[0m" << std::endl;
	++it;
	++itl;
	if (it == ite && itl == itel)
		std::cout << "\033[0;33mboth iterator reach the end of the container\033[0;33m" << "\033[0m" << std::endl;
	}
	
	// copy mutantstack in stack and list in list
	std::stack<int> s(mstack);
	std::list<int> l2(l);

	// aff size of both
	std::cout << "\033[1;36mshow size of duplicated container\033[0m" << std::endl;
	std::cout << "\033[0;32mstack copy size : \033[0;33m" << mstack.size() << "\033[0m" << std::endl;
	std::cout << "\033[0;32mlist copy size  : \033[0;33m" << l.size() << "\033[0m" << std::endl;
	std::cout << "\033[1;36mEnd of tests\033[0m";
	return (0);
}