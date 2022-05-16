/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:02:54 by cmaginot          #+#    #+#             */
/*   Updated: 2022/05/16 20:49:31 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#

std::string	printTF(bool value)
{
	std::string output = "";

	if (value == true)
		output += "\033[1;32mTrue\033[0m";
	else
		output += "\033[1;31mFalse\033[0m";
	return (output);
}

int main(int argc, char const *argv[])
{

	Point t1(1, 1);
	Point t2(3, 5);
	Point t3(5, 1);
	Point a;				// outside
	Point b(2, 2);			// inside
	Point c(2, 3);			// on line
	Point d(2, 4);			// outside
	Point e(3, 3);			// inside
	Point f(5, 1);			// on point
	Point g(t1);			// on point
	Point h;				// outside
	Point i(5, 5);			// outside
	Point j(1.5f, 1.8f);	// inside
	Point k(1.5f, 2);	// outside
	h = e;

	std::cout << "\033[1;36mVariables :\033[0m" << std::endl;
	std::cout << "point t1      : " << t1 << std::endl;
	std::cout << "point t2      : " << t2 << std::endl;
	std::cout << "point t3      : " << t3 << std::endl;
	std::cout << "point a       : " << a << std::endl;
	std::cout << "point b       : " << b << std::endl;
	std::cout << "point c       : " << c << std::endl;
	std::cout << "point d       : " << d << std::endl;
	std::cout << "point e       : " << e << std::endl;
	std::cout << "point f       : " << f << std::endl;
	std::cout << "point g (t1)  : " << g << std::endl;
	std::cout << "point h (e)   : " << h << std::endl;
	std::cout << "point i       : " << i << std::endl;
	std::cout << "point j       : " << j << std::endl;
	std::cout << "point k       : " << j << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;36mBSP tests (triangle is t1, t2, t3) :\033[0m";
	std::cout << std::endl;
	std::cout << "a on triangle : " << printTF(bsp(t1, t2, t3, a)) << std::endl;
	std::cout << "b on triangle : " << printTF(bsp(t1, t2, t3, b)) << std::endl;
	std::cout << "c on triangle : " << printTF(bsp(t1, t2, t3, c)) << std::endl;
	std::cout << "d on triangle : " << printTF(bsp(t1, t2, t3, d)) << std::endl;
	std::cout << "e on triangle : " << printTF(bsp(t1, t2, t3, e)) << std::endl;
	std::cout << "f on triangle : " << printTF(bsp(t1, t2, t3, f)) << std::endl;
	std::cout << "g on triangle : " << printTF(bsp(t1, t2, t3, g)) << std::endl;
	std::cout << "h on triangle : " << printTF(bsp(t1, t2, t3, h)) << std::endl;
	std::cout << "i on triangle : " << printTF(bsp(t1, t2, t3, i)) << std::endl;
	std::cout << "j on triangle : " << printTF(bsp(t1, t2, t3, j)) << std::endl;
	std::cout << "k on triangle : " << printTF(bsp(t1, t2, t3, k)) << std::endl;

	return (0);
}
