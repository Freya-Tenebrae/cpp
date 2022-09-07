/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/06 15:12:43 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "whatever.hpp"

int main(void)
{
	std::cout << "\033[1;36m-----Whatever tests-----\033[0m" << std::endl;
	std::cout << "\033[1;36mTest 1 : int\033[0m" << std::endl;
	{
		int a = 2;
		int b = 3;
		std::cout << "\033[0;32ma = \033[0;33m" << a << "\033[0;32m, ";
		std::cout << "b = \033[0;33m" << b << "\033[0m" << std::endl;

		std::cout << "\033[0;36mTest 1.1 : int swap\033[0m" << std::endl;
		::swap<int>( a, b );
		std::cout << "\033[0;32ma = \033[0;33m" << a << "\033[0;32m, ";
		std::cout << "b = \033[0;33m" << b << "\033[0m" << std::endl;

		std::cout << "\033[0;36mTest 1.2 : int min\033[0m" << std::endl;
		std::cout << "\033[0;32mmin(a, b) = \033[0;33m" << ::min<int>(a, b);
		std::cout << "\033[0m" << std::endl;

		std::cout << "\033[0;36mTest 1.3 : int max\033[0m" << std::endl;
		std::cout << "\033[0;32mmax(a, b) = \033[0;33m" << ::max<int>(a, b);
		std::cout << "\033[0m" << std::endl;
	}
	std::cout << "\033[1;36mTest 2 : string\033[0m" << std::endl;
	{
		std::string c = "chaine1";
		std::string d = "chaine2";
		std::cout << "\033[0;32mc = \033[0;33m" << c << "\033[0;32m, ";
		std::cout << "d = \033[0;33m" << d << "\033[0m" << std::endl;

		std::cout << "\033[0;36mTest 2.1 : string swap\033[0m" << std::endl;
		::swap<std::string>(c, d);
		std::cout << "\033[0;32mc = \033[0;33m" << c << "\033[0;32m, ";
		std::cout << "d = \033[0;33m" << d << "\033[0m" << std::endl;

		std::cout << "\033[0;36mTest 2.2 : string min\033[0m" << std::endl;
		std::cout << "\033[0;32mmin( c, d ) = \033[0;33m" << ::min<std::string>(c, d);
		std::cout << "\033[0m" << std::endl;

		std::cout << "\033[0;36mTest 2.3 : string max\033[0m" << std::endl;
		std::cout << "\033[0;32mmax( c, d ) = \033[0;33m" << ::max<std::string>(c, d);
		std::cout << "\033[0m" << std::endl;
	}
	std::cout << "\033[1;36mTest 3 : float\033[0m" << std::endl;
	{
		float e = 42.42f;
		float f = -690.0f;
		std::cout << "\033[0;32me = \033[0;33m" << e << "\033[0;32m, ";
		std::cout << "f = \033[0;33m" << f << "\033[0m" << std::endl;

		std::cout << "\033[0;36mTest 3.1 : float swap\033[0m" << std::endl;
		::swap<float>(e, f);
		std::cout << "\033[0;32me = \033[0;33m" << e << "\033[0;32m, ";
		std::cout << "f = \033[0;33m" << f << "\033[0m" << std::endl;

		std::cout << "\033[0;36mTest 3.2 : float min\033[0m" << std::endl;
		std::cout << "\033[0;32mmin( e, f ) = \033[0;33m" << ::min<float>(e, f);
		std::cout << "\033[0m" << std::endl;

		std::cout << "\033[0;36mTest 3.3 : float max\033[0m" << std::endl;
		std::cout << "\033[0;32mmax( e, f ) = \033[0;33m" << ::max<float>(e, f);
		std::cout << "\033[0m" << std::endl;
	}

	std::cout << "\033[1;36mEns of tests\033[0m" << std::endl;
	return (0);
}