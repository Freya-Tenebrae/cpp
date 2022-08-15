/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:02:54 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/15 02:43:13 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

void tests(Bureaucrat *b1, Bureaucrat *b2, Bureaucrat *b3, Bureaucrat *b4, \
																	AForm *form)
{
	std::cout << *form;
	std::cout << "\033[0;36m    tests .2 : can't execute, not signed\033[0m";
	std::cout << std::endl;
	b1->executeForm(*form);
	std::cout << "\033[0;36m    tests .3 : signe form\033[0m";
	std::cout << std::endl;
	b4->signForm(*form);
	b3->signForm(*form);
	b2->signForm(*form);
	b1->signForm(*form);
	std::cout << "\033[0;36m    tests .4: execute\033[0m";
	std::cout << std::endl;
	b4->executeForm(*form);
	b3->executeForm(*form);
	b2->executeForm(*form);
	b1->executeForm(*form);
	std::cout << "\033[0;36m    tests .5: form deletion\033[0m";
	std::cout << std::endl;
	delete form;
	std::cout << std::endl;
}

int main()
{
	Bureaucrat	*b1 = NULL;
	Bureaucrat	*b2 = NULL;
	Bureaucrat	*b3 = NULL;
	Bureaucrat	*b4 = NULL;
	AForm		*form = NULL;
	Intern		*someRandomIntern = NULL;

	try
	{
		std::cout << "\033[1;36mInit var\033[0m";
		std::cout << std::endl;
		b1 = new Bureaucrat("Arik", 1);
		std::cout << *b1;
		b2 = new Bureaucrat("Kaede", 30);
		std::cout << *b2;
		b3 = new Bureaucrat("Freya", 75);
		std::cout << *b3;
		b4 = new Bureaucrat("Mummius", 150);
		std::cout << *b4;
		someRandomIntern = new Intern();
		std::cout << std::endl;

		std::cout << "\033[1;36mtests 1 : Intern Shrubbery Creation tests\033[0m";
		std::cout << std::endl;
		std::cout << "\033[0;36m    tests .1 : init by intern\033[0m";
		std::cout << std::endl;
		form = someRandomIntern->makeForm("shrubbery creation", "Moon");
		tests(b1, b2, b3, b4, form);

		std::cout << "\033[1;36mtests 2 : Intern Robotomy Request tests\033[0m";
		std::cout << std::endl;
		std::cout << "\033[0;36m    tests .1 : init by intern\033[0m";
		std::cout << std::endl;
		form = someRandomIntern->makeForm("robotomy request", "Bender");
		tests(b1, b2, b3, b4, form);

		std::cout << "\033[1;36mtests 3 : Intern Presidential Pardon tests\033[0m";
		std::cout << std::endl;
		std::cout << "\033[0;36m    tests .1 : init by intern\033[0m";
		std::cout << std::endl;
		form = someRandomIntern->makeForm("presidential pardon", "Jack");
		tests(b1, b2, b3, b4, form);

		std::cout << "\033[1;36mDelete other var\033[0m";
		std::cout << std::endl;
		delete b1;
		delete b2;
		delete b3;
		delete b4;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		if (b1 != NULL)
			delete b1;
		if (b2 != NULL)
			delete b2;
		if (b3 != NULL)
			delete b3;
		if (b4 != NULL)
			delete b4;
		std::cerr << "Bureaucrat exception : " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		if (b1 != NULL)
			delete b1;
		if (b2 != NULL)
			delete b2;
		if (b3 != NULL)
			delete b3;
		if (b4 != NULL)
			delete b4;
		std::cerr << "Bureaucrat exception : " << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e)
	{
		delete b1;
		delete b2;
		delete b3;
		delete b4;
		std::cerr << "Form exception : " << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		delete b1;
		delete b2;
		delete b3;
		delete b4;
		std::cerr << "Form exception : " << e.what() << std::endl;
	}
	std::cout << "\033[1;36mEnd of tests\033[0m" << std::endl;
	return (0);
}
