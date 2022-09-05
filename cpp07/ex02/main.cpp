/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 20:17:02 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/05 09:46:55 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"

int main(void)
{
	std::cout << "\033[1;36m-----Iter tests-----\033[0m" << std::endl;
	std::cout << "\033[1;36mTest 1 : int\033[0m" << std::endl;
	{
		std::cout << "\033[0;36mInit a\033[0m" << std::endl;
		Array<int>	a(5);
		std::cout << "\033[0;36mget size of a\033[0m" << std::endl;
		std::cout << "\033[0;32mSize of a : \033[0;33m" << a.size() << "\033[0m";
		std::cout << std::endl;
		std::cout << "\033[0;36mShow a\033[0m" << std::endl;
		std::cout << "\033[0;32ma : \033[0m";
		a.show();
		std::cout << std::endl;
		std::cout << "\033[0;36mFill a with value\033[0m" << std::endl;
		a[0] = 2;
		a[1] = 5;
		a[2] = 3;
		a[3] = 4;
		a[4] = 7;
		std::cout << "\033[0;36mShow a\033[0m" << std::endl;
		std::cout << "\033[0;32ma : \033[0m";
		a.show();
		std::cout << std::endl;
		std::cout << "\033[0;36mCopy a to b\033[0m" << std::endl;
		Array<int>	b(a);
		std::cout << "\033[0;36mget size of b\033[0m" << std::endl;
		std::cout << "\033[0;32mSize of b : \033[0;33m" << b.size() << "\033[0m";
		std::cout << std::endl;
		std::cout << "\033[0;36mShow b\033[0m" << std::endl;
		std::cout << "\033[0;32mb : \033[0m";
		b.show();
		std::cout << std::endl;
		std::cout << "\033[0;36mFill b with other value\033[0m" << std::endl;
		b[0] = 42;
		b[1] = 55;
		b[2] = 300;
		b[3] = 444;
		b[4] = 69;
		std::cout << "\033[0;36mShow a and b\033[0m" << std::endl;
		std::cout << "\033[0;32ma : \033[0m";
		a.show();
		std::cout << std::endl;
		std::cout << "\033[0;32mb : \033[0m";
		b.show();
		std::cout << std::endl;
		std::cout << "\033[0;36mtests out of access\033[0m" << std::endl;
		try
		{
			b[5] = 666;
			std::cout << "bla" << std::endl;
		}
		catch (Array<int>::OutException &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			int value = a[-1];
			std::cout << "a[-1] : " << value << std::endl;
		}
		catch (Array<int>::OutException &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[1;36mTest 2 : string\033[0m" << std::endl;
	{
				std::cout << "\033[0;36mInit c\033[0m" << std::endl;
		Array<std::string>	c(3);
		std::cout << "\033[0;36mget size of c\033[0m" << std::endl;
		std::cout << "\033[0;32mSize of c : \033[0;33m" << c.size() << "\033[0m";
		std::cout << std::endl;
		std::cout << "\033[0;36mShow c\033[0m" << std::endl;
		std::cout << "\033[0;32mc : \033[0m";
		c.show();
		std::cout << std::endl;
		std::cout << "\033[0;36mFill c with value\033[0m" << std::endl;
		c[0] = "coucou :3";
		c[1] = "Je suis un test ^^";
		c[2] = "meow :3";
		std::cout << "\033[0;36mShow c\033[0m" << std::endl;
		std::cout << "\033[0;32mc : \033[0m";
		c.show();
		std::cout << std::endl;
		std::cout << "\033[0;36mCopy c to d\033[0m" << std::endl;
		Array<std::string>	d(c);
		std::cout << "\033[0;36mget size of d\033[0m" << std::endl;
		std::cout << "\033[0;32mSize of d : \033[0;33m" << d.size() << "\033[0m";
		std::cout << std::endl;
		std::cout << "\033[0;36mShow d\033[0m" << std::endl;
		std::cout << "\033[0;32md : \033[0m";
		d.show();
		std::cout << std::endl;
		std::cout << "\033[0;36mFill d with other value\033[0m" << std::endl;
		d[0] = "o/";
		d[1] = "Je suis un deuxieme test qui remplace le premier :p";
		d[2] = "prrrrrrrrrrrr";
		std::cout << "\033[0;36mShow c and d\033[0m" << std::endl;
		std::cout << "\033[0;32mc : \033[0m";
		c.show();
		std::cout << std::endl;
		std::cout << "\033[0;32md : \033[0m";
		d.show();
		std::cout << std::endl;
		std::cout << "\033[0;36mtests out of access\033[0m" << std::endl;
		try
		{
			d[3] = "i'm impossible";
			std::cout << "bla" << std::endl;
		}
		catch (Array<std::string>::OutException &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::string value = c[-1];
			std::cout << "c[-1] : " << value << std::endl;
		}
		catch (Array<std::string>::OutException &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[1;36mTest 3 : float\033[0m" << std::endl;
	{
		std::cout << "\033[0;36mInit e\033[0m" << std::endl;
		Array<float>	e(7);
		std::cout << "\033[0;36mget size of e\033[0m" << std::endl;
		std::cout << "\033[0;32mSize of e : \033[0;33m" << e.size() << "\033[0m";
		std::cout << std::endl;
		std::cout << "\033[0;36mShow e\033[0m" << std::endl;
		std::cout << "\033[0;32me : \033[0m";
		e.show();
		std::cout << std::endl;
		std::cout << "\033[0;36mFill e with value\033[0m" << std::endl;
		e[0] = 42.0f;
		e[1] = 0.0f;
		e[2] = -9.0f;
		e[3] = 42.42f;
		e[4] = 2.2f;
		e[5] = -3.0f;
		e[6] = 111.111f;
		std::cout << "\033[0;36mShow e\033[0m" << std::endl;
		std::cout << "\033[0;32me : \033[0m";
		e.show();
		std::cout << std::endl;
		std::cout << "\033[0;36mCopy e to f\033[0m" << std::endl;
		Array<float>	f(e);
		std::cout << "\033[0;36mget size of f\033[0m" << std::endl;
		std::cout << "\033[0;32mSize of f : \033[0;33m" << f.size() << "\033[0m";
		std::cout << std::endl;
		std::cout << "\033[0;36mShow b\033[0m" << std::endl;
		std::cout << "\033[0;32mf : \033[0m";
		f.show();
		std::cout << std::endl;
		std::cout << "\033[0;36mFill f with other value\033[0m" << std::endl;
		f[0] = 429.0f;
		f[1] = 0.0000001f;
		f[2] = 9.9f;
		f[3] = 434.0f;
		f[4] = 242.242f;
		f[5] = -333.0f;
		f[6] = 69.420f;
		std::cout << "\033[0;36mShow e and f\033[0m" << std::endl;
		std::cout << "\033[0;32me : \033[0m";
		e.show();
		std::cout << std::endl;
		std::cout << "\033[0;32mf : \033[0m";
		f.show();
		std::cout << std::endl;
		std::cout << "\033[0;36mtests out of access\033[0m" << std::endl;
		try
		{
			f[7] = 666.0f;
			std::cout << "bla" << std::endl;
		}
		catch (Array<float>::OutException &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			float value = e[-1];
			std::cout << "e[-1] : " << value << std::endl;
		}
		catch (Array<float>::OutException &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "\033[1;36mEnd of tests\033[0m" << std::endl;
	return (0);
}