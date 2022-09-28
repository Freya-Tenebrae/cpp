/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/28 18:50:04 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	affShortestSpan(Span *s)
{
	try
	{
		std::cout << "\033[0;32mShortest span : \033[0;33m";
		std::cout << s->shortestSpan() << "\033[0m" << std::endl;
	}
	catch (Span::TooFewNumberException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
void	affLongestSpan(Span *s)
{
	try
	{
		std::cout << "\033[0;32mLongest span  : \033[0;33m";
		std::cout << s->longestSpan() << "\033[0m" << std::endl;
	}
	catch (Span::TooFewNumberException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main(void)
{
	std::cout << "\033[1;36m-----span tests-----\033[0m" << std::endl;
	std::cout << "\033[1;36mTest 1 : Init part 1 and test add number\033[0m";
	std::cout << std::endl;
	std::cout << "\033[0;36mTest 1.1 : Construc and fill halfway a span\033[0m";
	std::cout << std::endl;
	Span sp1 = Span(5);
	sp1.addNumber(6);
	sp1.addNumber(3);
	std::cout << "\033[0;32msp1 :\033[0m" << sp1;
	std::cout << "\033[0;36mTest 1.2 : Copy constructor\033[0m";
	std::cout << std::endl;
	Span sp2(sp1);
	std::cout << "\033[0;32msp2 :\033[0m" << sp2;
	std::cout << "\033[0;36mTest 1.3 : fill 2 span\033[0m";
	std::cout << std::endl;
	sp1.addNumber(12);
	sp1.addNumber(9);
	sp1.addNumber(15);
	std::cout << "\033[0;32msp1 :\033[0m" << sp1;
	sp2.addNumber(18);
	sp2.addNumber(3);
	sp2.addNumber(7);
	std::cout << "\033[0;32msp2 :\033[0m" << sp2;
	std::cout << "\033[0;36mTest 1.4 : create 3 other span\033[0m";
	std::cout << std::endl;
	Span sp3 = Span(5);
	sp3.addNumber(3);
	sp3.addNumber(9);
	sp3.addNumber(27);
	std::cout << "\033[0;32msp3 :\033[0m" << sp3;
	Span sp4 = Span(2);
	std::cout << "\033[0;32msp4 :\033[0m" << sp4;
	Span sp5 = Span(3);
	sp5.addNumber(3);
	std::cout << "\033[0;32msp5 :\033[0m" << sp5;
	std::cout << "\033[0;36mTest 1.5 : create and overload a span\033[0m";
	std::cout << std::endl;
	Span sp6 = Span(3);
	try
	{
		sp6.addNumber(1);
		sp6.addNumber(2);
		sp6.addNumber(3);
		std::cout << "\033[0;32msp6 :\033[0m" << sp6;
		sp6.addNumber(4);
	}
	catch (Span::SpanFullException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[0;32msp6 :\033[0m" << sp6;

	std::cout << std::endl;

	std::cout << "\033[1;36mTest 2 : ShortestSpan and LongestSpan test\033[0m";
	std::cout << std::endl;
	std::cout << "\033[1;36mTest 2.1 : correct Span\033[0m" << std::endl;
	std::cout << "\033[0;32msp1 :\033[0m" << sp1;
	affShortestSpan(&sp1);
	affLongestSpan(&sp1);

	std::cout << "\033[1;36mTest 2.2 : half copied Span\033[0m" << std::endl;
	std::cout << "\033[0;32msp2 :\033[0m" << sp2;
	affShortestSpan(&sp2);
	affLongestSpan(&sp2);

	std::cout << "\033[1;36mTest 2.3 : Span not full\033[0m" << std::endl;
	std::cout << "\033[0;32msp3 :\033[0m" << sp3;
	affShortestSpan(&sp3);
	affLongestSpan(&sp3);

	std::cout << "\033[1;36mTest 2.4 : empty Span\033[0m" << std::endl;
	std::cout << "\033[0;32msp4 :\033[0m" << sp4;
	affShortestSpan(&sp4);
	affLongestSpan(&sp4);

	std::cout << "\033[1;36mTest 2.5 : Span with only one element\033[0m" << std::endl;
	std::cout << "\033[0;32msp5 :\033[0m" << sp5;
	affShortestSpan(&sp5);
	affLongestSpan(&sp5);

	std::cout << std::endl;

	std::cout << "\033[1;36mTest 3 : 10 000+ tests\033[0m" << std::endl;
	Span sp7 = Span(125000);
	for (int i = 0 ; i < 125000; i++)
		sp7.addNumber(1 + i * 2);
	std::cout << "\033[0;32msp7 : size  : 125000" << std::endl;
	std::cout << "      value : {1, 3, ... , 249997, 249999}\033[0m" << std::endl;
	// std::cout << "\033[0;32msp7 :\033[0m" << sp7; // commented for more lisibility
	affShortestSpan(&sp7);
	affLongestSpan(&sp7);
	std::cout << std::endl;

	std::cout << "\033[1;36mTest 4 : range tests\033[0m" << std::endl;
	std::cout << "\033[0;36mTest 4.1 : small range\033[0m" << std::endl;
	Span sp8 = Span(42);
	sp8.fillWithRandom();
	std::cout << "\033[0;32msp8 :\033[0m" << sp8;
	affShortestSpan(&sp8);
	affLongestSpan(&sp8);
	std::cout << "\033[0;36mTest 4.2 : half range\033[0m" << std::endl;
	Span sp9 = Span(12);
	sp9.addNumber(0);
	sp9.addNumber(42);
	sp9.addNumber(57);
	sp9.addNumber(6111939);
	sp9.addNumber(3);
	sp9.addNumber(-69);
	sp9.fillWithRandom();
	std::cout << "\033[0;32msp9 :\033[0m" << sp9;
	affShortestSpan(&sp9);
	affLongestSpan(&sp9);
	std::cout << "\033[0;36mTest 4.3 : huge range\033[0m" << std::endl;
	Span sp10 = Span(42000);
	sp10.fillWithRandom();
	// std::cout << "\033[0;32msp10 :\033[0m" << sp10;
	affShortestSpan(&sp10);
	affLongestSpan(&sp10);
	std::cout << std::endl;

	std::cout << "\033[1;36mEnd of tests\033[0m" << std::endl;
	return (0);
}
