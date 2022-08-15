/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:02:54 by cmaginot          #+#    #+#             */
/*   Updated: 2022/08/14 22:13:51 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void formTestsNoException()
{
	try
	{
		std::cout << "\033[0;36m    creation of a correct form (grade 42 ";
		std::cout << "to signed, 75 to execute)\033[0m" << std::endl;
		Form *f = new Form("A42", 1, 42);
		std::cout << *f;
		delete f;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void formTestsHighException()
{
	try
	{
		std::cout << "\033[0;36m    test 2.1 creation of a incorrect form ";
		std::cout << "(0 to signed, 75 to execute)\033[0m" << std::endl;
		Form *f = new Form("A43", 0, 42);
		std::cout << *f;
		delete f;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "\033[0;36m    test 2.2 creation of a incorrect form ";
		std::cout << "(1 to signed, 0 to execute)\033[0m" << std::endl;
		Form *f = new Form("A43", 1, 0);
		std::cout << *f;
		delete f;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void formTestsLowException()
{
	try
	{
		std::cout << "\033[0;36m    test 3.1 creation of a incorrect form ";
		std::cout << "(151 to signed, 75 to execute)\033[0m" << std::endl;
		Form *f = new Form("A43", 151, 42);
		std::cout << *f;
		delete f;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "\033[0;36m    test 3.2 creation of a incorrect form ";
		std::cout << "(1 to signed, 151 to execute)\033[0m" << std::endl;
		Form *f = new Form("A43", 1, 151);
		std::cout << *f;
		delete f;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void formSignature()
{
	Bureaucrat *b;
	Form *f;

	try
	{
		std::cout << "\033[0;36m    tests 4.1 : could sign (tie)\033[0m";
		std::cout << std::endl;
		b = new Bureaucrat("Freya", 42);
		f = new Form("matrioshka brain update", 42, 69);
		std::cout << *b << *f;
		b->signForm(*f);
		std::cout << *f;
		delete b;
		delete f;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Bureaucrat exception : " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Bureaucrat exception : " << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		delete b;
		std::cerr << "Form exception : " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		delete b;
		std::cerr << "Form exception : " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\033[0;36m    tests 4.2 : could sign\033[0m";
		std::cout << std::endl;
		b = new Bureaucrat("Freya", 42);
		f = new Form("Moon's exception", 80, 130);
		std::cout << *b << *f;
		b->signForm(*f);
		std::cout << *f;
		delete b;
		delete f;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Bureaucrat exception : " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Bureaucrat exception : " << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		delete b;
		std::cerr << "Form exception : " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		delete b;
		std::cerr << "Form exception : " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\033[0;36m    tests 4.3 : couldn't sign\033[0m";
		std::cout << std::endl;
		b = new Bureaucrat("Freya", 42);
		f = new Form("A42", 1, 42);
		std::cout << *b << *f;
		b->signForm(*f);
		std::cout << *f;
		delete b;
		delete f;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Bureaucrat exception : " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Bureaucrat exception : " << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		delete b;
		std::cerr << "Form exception : " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		delete b;
		std::cerr << "Form exception : " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\033[0;36m    tests 4.4 : double signed\033[0m";
		std::cout << std::endl;
		b = new Bureaucrat("Freya", 42);
		f = new Form("Creation of a cult", 45, 50);
		std::cout << *b << *f;
		b->signForm(*f);
		std::cout << *f;
		b->signForm(*f);
		std::cout << *f;
		delete b;
		delete f;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Bureaucrat exception : " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Bureaucrat exception : " << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		delete b;
		std::cerr << "Form exception : " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		delete b;
		std::cerr << "Form exception : " << e.what() << std::endl;
	}
}


int main()
{
	std::cout << "\033[1;36mForm tests :\033[0m" << std::endl;
	std::cout << "\033[0;36mtests 1 : No exception\033[0m" << std::endl;
	formTestsNoException();
	std::cout << std::endl;
	std::cout << "\033[0;36mtests 2 : Too high\033[0m" << std::endl;
	formTestsHighException();
	std::cout << std::endl;
	std::cout << "\033[0;36mtests 3 : Too low\033[0m" << std::endl;
	formTestsLowException();
	std::cout << std::endl;
	std::cout << "\033[0;36mtests 4 : Sign\033[0m" << std::endl;
	formSignature();
	std::cout << std::endl;
	std::cout << "\033[1;36mEnd of tests\033[0m" << std::endl;
	return (0);
}
