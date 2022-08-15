/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:02:54 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/15 00:07:05 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	shrubberyCreationtests()
{
	Bureaucrat *b1 = NULL;
	Bureaucrat *b2 = NULL;
	Bureaucrat *b3 = NULL;
	AForm *f;

	try
	{
		b1 = new Bureaucrat("Freya", 130);
		b2 = new Bureaucrat("Kaede", 137);
		b3 = new Bureaucrat("Arik", 140);
		f = new ShrubberyCreationForm("DesertedIsland");
		std::cout << *b1 << *b2 << *b3 << *f;
		std::cout << "\033[0;36m    tests 1.1 : can't execute, not signed\033[0m";
		std::cout << std::endl;
		b1->executeForm(*f);
		b1->signForm(*f);
		std::cout << *f;
		std::cout << "\033[0;36m    tests 1.2: execute\033[0m";
		std::cout << std::endl;
		b1->executeForm(*f);
		std::cout << "\033[0;36m    tests 1.3: execute (2nd time)\033[0m";
		std::cout << std::endl;
		b2->executeForm(*f);
		std::cout << "\033[0;36m    tests 1.4: can't execute, too low\033[0m";
		std::cout << std::endl;
		b3->executeForm(*f);
		delete b1;
		delete b2;
		delete b3;
		delete f;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		if (b1 != NULL)
			delete b1;
		if (b2 != NULL)
			delete b2;
		if (b3 != NULL)
			delete b3;
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
		std::cerr << "Bureaucrat exception : " << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e)
	{
		delete b1;
		delete b2;
		delete b3;
		std::cerr << "Form exception : " << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		delete b1;
		delete b2;
		delete b3;
		std::cerr << "Form exception : " << e.what() << std::endl;
	}
}

void	robotomyRequesttests()
{
	Bureaucrat *b1 = NULL;
	Bureaucrat *b2 = NULL;
	Bureaucrat *b3 = NULL;
	AForm *f;

	try
	{
		b1 = new Bureaucrat("Freya", 25);
		b2 = new Bureaucrat("Kaede", 40);
		b3 = new Bureaucrat("Arik", 50);
		// const RobotomyRequestForm *fl = new RobotomyRequestForm("ClapTrap");
		// f = new RobotomyRequestForm(*fl);
		f = new RobotomyRequestForm("ClapTrap");
		std::cout << *b1 << *b2 << *b3 << *f;
		std::cout << "\033[0;36m    tests 2.1 : can't execute, not signed\033[0m";
		std::cout << std::endl;
		b1->executeForm(*f);
		b1->signForm(*f);
		std::cout << *f;
		std::cout << "\033[0;36m    tests 2.2: execute\033[0m";
		std::cout << std::endl;
		b1->executeForm(*f);
		b1->executeForm(*f);
		b1->executeForm(*f);
		b1->executeForm(*f);
		b1->executeForm(*f);
		std::cout << "\033[0;36m    tests 2.3: execute (2nd time)\033[0m";
		std::cout << std::endl;
		b2->executeForm(*f);
		b2->executeForm(*f);
		b2->executeForm(*f);
		b2->executeForm(*f);
		b2->executeForm(*f);
		std::cout << "\033[0;36m    tests 2.4: can't execute, too low\033[0m";
		std::cout << std::endl;
		b3->executeForm(*f);
		b3->executeForm(*f);
		b3->executeForm(*f);
		b3->executeForm(*f);
		b3->executeForm(*f);
		delete b1;
		delete b2;
		delete b3;
		delete f;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		if (b1 != NULL)
			delete b1;
		if (b2 != NULL)
			delete b2;
		if (b3 != NULL)
			delete b3;
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
		std::cerr << "Bureaucrat exception : " << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e)
	{
		delete b1;
		delete b2;
		delete b3;
		std::cerr << "Form exception : " << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		delete b1;
		delete b2;
		delete b3;
		std::cerr << "Form exception : " << e.what() << std::endl;
	}
}

void	presidentialPardonTests()
{
	Bureaucrat *b1 = NULL;
	Bureaucrat *b2 = NULL;
	Bureaucrat *b3 = NULL;
	AForm *f;

	try
	{
		b1 = new Bureaucrat("Freya", 1);
		b2 = new Bureaucrat("Kaede", 5);
		b3 = new Bureaucrat("Arik", 10);
		f = new PresidentialPardonForm("Joe");
		std::cout << *b1 << *b2 << *b3 << *f;
		std::cout << "\033[0;36m    tests 3.1 : can't execute, not signed\033[0m";
		std::cout << std::endl;
		b1->executeForm(*f);
		b1->signForm(*f);
		std::cout << *f;
		std::cout << "\033[0;36m    tests 3.2: execute\033[0m";
		std::cout << std::endl;
		b1->executeForm(*f);
		std::cout << "\033[0;36m    tests 3.3: execute (2nd time)\033[0m";
		std::cout << std::endl;
		b2->executeForm(*f);
		std::cout << "\033[0;36m    tests 3.4: can't execute, too low\033[0m";
		std::cout << std::endl;
		b3->executeForm(*f);
		delete b1;
		delete b2;
		delete b3;
		delete f;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		if (b1 != NULL)
			delete b1;
		if (b2 != NULL)
			delete b2;
		if (b3 != NULL)
			delete b3;
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
		std::cerr << "Bureaucrat exception : " << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e)
	{
		delete b1;
		delete b2;
		delete b3;
		std::cerr << "Form exception : " << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		delete b1;
		delete b2;
		delete b3;
		std::cerr << "Form exception : " << e.what() << std::endl;
	}
}


int main()
{
	std::cout << "\033[1;36mtests 1 : Shrubbery Creation tests\033[0m";
	std::cout << std::endl;
	shrubberyCreationtests();
	std::cout << std::endl;
	std::cout << "\033[1;36mtests 2 : Robotomy Request tests\033[0m";
	std::cout << std::endl;
	robotomyRequesttests();
	std::cout << std::endl;
	std::cout << "\033[1;36mtests 3 : Presidential Pardon tests\033[0m";
	std::cout << std::endl;
	presidentialPardonTests();
	std::cout << std::endl;
	std::cout << "\033[1;36mEnd of tests\033[0m" << std::endl;
	return (0);
}
