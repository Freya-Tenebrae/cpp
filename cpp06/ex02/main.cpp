/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:02:54 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/02 19:07:02 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Identify.hpp"

int main()
{
	std::cout << "\033[1;36mInit\033[0m" << std::endl;
	Identify *id = new Identify();
	Base *base;

	std::cout << "\033[1;36mA\033[0m" << std::endl;
	base = new A();
	id->identify(base);
	id->identify(*base);
	delete base;

	std::cout << "\033[1;36mB\033[0m" << std::endl;
	base = new B();
	id->identify(base);
	id->identify(*base);
	delete base;

	std::cout << "\033[1;36mC\033[0m" << std::endl;
	base = new C();
	id->identify(base);
	id->identify(*base);
	delete base;

	std::cout << "\033[1;36mGenerate\033[0m" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "\033[0;36mGenerattion " << i << "\033[0m" << std::endl;
		base = id->generate();
		id->identify(base);
		id->identify(*base);
		delete base;
	}

	std::cout << "\033[1;36mDelete Identify\033[0m" << std::endl;
	delete id;

	std::cout << "\033[1;36mEnd of tests\033[0m" << std::endl;
	return (0);
}