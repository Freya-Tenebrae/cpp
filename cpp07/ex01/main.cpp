/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/05 08:22:34 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "iter.hpp"

void	increment(int &i)
{
	i += 1;
}

void	up(std::string &s)
{
	int i = -1;

	while (s[++i] != '\0')
		s[i] = std::toupper(s[i]);
}

void	power(float &f)
{
	f *= f;
}

int main(void)
{
	std::cout << "\033[1;36m-----Iter tests-----\033[0m" << std::endl;
	std::cout << "\033[1;36mTest 1 : int\033[0m" << std::endl;
	{
		int t[5] = {2, 5, 3, 4, 7};

		std::cout << "int tab : ";
		::iter<int>(t, 5, &show);
		std::cout << std::endl;

		::iter<int>(t, 5, &increment);

		std::cout << "int tab : ";
		::iter<int>(t, 5, &show);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\033[1;36mTest 2 : string\033[0m" << std::endl;
	{
		std::string t[3] = {"coucou :3", "Je suis un test ^^", "meow :3"};

		std::cout << "int tab : ";
		::iter<std::string>(t, 3, &show);
		std::cout << std::endl;

		::iter<std::string>(t, 3, &up);

		std::cout << "int tab : ";
		::iter<std::string>(t, 3, &show);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\033[1;36mTest 3 : float\033[0m" << std::endl;
	{
		float t[7] = {42.0f, 0.0f, -9.0f, 42.42f, 2.2f, -3.0f, 111.111f};

		std::cout << "int tab : ";
		::iter<float>(t, 7, &show);
		std::cout << std::endl;

		::iter<float>(t, 7, &power);

		std::cout << "int tab : ";
		::iter<float>(t, 7, &show);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\033[1;36mEnd of tests\033[0m" << std::endl;
	return (0);
}