/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:02:54 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/13 16:28:54 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void promotionTests(Bureaucrat *b)
{
	std::cout << *b << std::endl;
	try
	{
		b->Promoted();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *b << std::endl;
}

void demotionTests(Bureaucrat *b)
{
	std::cout << *b << std::endl;
	try
	{
		b->Demoted();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *b << std::endl;
}

void bureaucratTestsNoException()
{
	try
	{
		std::cout << "\033[0;36m    Test 1.1 : creation of a correct ";
		std::cout << "bureaucrat (grade 42)\033[0m" << std::endl;
		Bureaucrat *b = new Bureaucrat("Freya", 42);
		std::cout << *b << std::endl;
		std::cout << "\033[0;36m    Test 1.2 : correct promotion";
		std::cout << "\033[0m" << std::endl;
		promotionTests(b);
		std::cout << "\033[0;36m    Test 1.3 : correct demotion";
		std::cout << "\033[0m" << std::endl;
		demotionTests(b);
		delete b;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void bureaucratTestsHighException()
{
	try
	{
		std::cout << "\033[0;36m    Test 2.1 : creation of a incorrect ";
		std::cout << "bureaucrat (grade 0)\033[0m" << std::endl;
		Bureaucrat *b = new Bureaucrat("Freya", 0);
		std::cout << *b << std::endl;
		delete b;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "\033[0;36m    Test 3.2 : creation of a correct ";
		std::cout << "bureaucrat (grade 1)\033[0m" << std::endl;
		Bureaucrat *b = new Bureaucrat("Freya", 1);
		std::cout << *b << std::endl;
		std::cout << "\033[0;36m    Test 3.3 : incorrect promotion";
		std::cout << "\033[0m" << std::endl;
		promotionTests(b);
		std::cout << "\033[0;36m    Test 3.4 : correct demotion";
		std::cout << "\033[0m" << std::endl;
		demotionTests(b);
		delete b;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}


void bureaucratTestsLowException()
{
	try
	{
		std::cout << "\033[0;36m    Test 3.1 : creation of a incorrect ";
		std::cout << "bureaucrat (grade 151)\033[0m" << std::endl;
		Bureaucrat *b = new Bureaucrat("Freya", 151);
		std::cout << *b << std::endl;
		delete b;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "\033[0;36m    Test 3.2 : creation of a correct ";
		std::cout << "bureaucrat (grade 150)\033[0m" << std::endl;
		Bureaucrat *b = new Bureaucrat("Freya", 150);
		std::cout << *b << std::endl;
		std::cout << "\033[0;36m    Test 3.3 : incorrect demotion";
		std::cout << "\033[0m" << std::endl;
		demotionTests(b);
		std::cout << "\033[0;36m    Test 3.4 : correct promotion";
		std::cout << "\033[0m" << std::endl;
		promotionTests(b);
		delete b;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}


int main()
{
	std::cout << "\033[1;36mBureaucrat tests :\033[0m" << std::endl;
	std::cout << "\033[0;36mtests 1 : No exception\033[0m" << std::endl;
	bureaucratTestsNoException();
	std::cout << std::endl;
	std::cout << "\033[0;36mtests 2 : Too high\033[0m" << std::endl;
	bureaucratTestsHighException();
	std::cout << std::endl;
	std::cout << "\033[0;36mtests 3 : Too low\033[0m" << std::endl;
	bureaucratTestsLowException();
	std::cout << std::endl;
	std::cout << "\033[1;36mEnd of tests\033[0m" << std::endl;
	return (0);
}
