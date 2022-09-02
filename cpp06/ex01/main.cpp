/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:02:54 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/02 18:11:30 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serialisation.hpp"

void	printAll(Data *data, Data *dataptr, uintptr_t ptr)
{
	std::cout << "\033[0;32mdata    : adresse (&data) = \033[0;33m" << data;
	std::cout << " \033[0;32mvalue 1 = \033[0;33m" << data->data_v1;
	std::cout << " \033[0;32mvalue 2 = \033[0;33m" << data->data_v2 << std::endl;
	std::cout << "\033[0;32mptr     : (unitptr_t) = \033[0;33m" << ptr << std::endl;
	std::cout << "\033[0;32mdataptr : adresse (dataptr) = \033[0;33m" << dataptr;
	if (dataptr != NULL)
	{
		std::cout << " \033[0;32mvalue 1 = \033[0;33m" << dataptr->data_v1;
		std::cout << " \033[0;32mvalue 2 = \033[0;33m" << dataptr->data_v2;
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << "\033[1;36mInit all\033[0m" << std::endl;
	Serialisation *s = new Serialisation();
	Data data;
	Data *dataptr;
	uintptr_t ptr;
	data.data_v1 = 42;
	data.data_v2 = "coucou :3";
	dataptr = NULL;
	ptr = 0;
	printAll(&data, dataptr, ptr);

	std::cout << "\033[1;36mSerialize\033[0m" << std::endl;
	ptr = s->serialize(&data);
	printAll(&data, dataptr, ptr);

	std::cout << "\033[1;36mDeserialize\033[0m" << std::endl;
	dataptr = s->deserialize(ptr);
	printAll(&data, dataptr, ptr);

	std::cout << "\033[1;36mDelete all\033[0m" << std::endl;
	delete s;

	std::cout << "\033[1;36mEnd of tests\033[0m" << std::endl;
	return (0);
}