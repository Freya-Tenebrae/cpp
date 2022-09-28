/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:02:54 by cmaginot          #+#    #+#             */
/*   Updated: 2022/09/09 04:08:00 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

void materiaTests()
{
	std::cout << "\033[1;36mMateria tests :\033[0m" << std::endl;
	std::cout << "\033[0;36m    Create objects :\033[0m" << std::endl;
	// const AMateria* meta = new AMateria(); // should not compile
	AMateria* c = new Cure();
	AMateria* i = new Ice();
	AMateria* d = c->clone();
	ICharacter* freya = new Character("Freya");
	std::cout << std::endl;

	std::cout << "\033[0;36m    tests :\033[0m" << std::endl;
	std::cout << "use materia \"\033[0;33mc\033[0m\" (cure)" << std::endl;
	c->use(*freya);
	std::cout << "use materia \"\033[0;33mi\033[0m\" (ice)" << std::endl;
	i->use(*freya);
	std::cout << "use materia \"\033[0;33md\033[0m\" (cure)" << std::endl;
	d->use(*freya);
	std::cout << std::endl;

	std::cout << "change type of materia \"\033[0;33md\033[0m\"";
	std::cout << " (cure to upgraded_cure)" << std::endl;
	d->setType("upgraded_cure");
	std::cout << "use materia \"\033[0;33mc\033[0m\" (cure)" << std::endl;
	c->use(*freya);
	std::cout << "use materia \"\033[0;33md\033[0m\" (upgraded_cure)";
	std::cout << std::endl;
	d->use(*freya);
	std::cout << std::endl;

	std::cout << "\033[0;36m    Delete objects :\033[0m" << std::endl;
	// delete meta; // should not compile
	delete c;
	delete i;
	delete d;
	delete freya;
	std::cout << std::endl;
}

void materiaSourceTests()
{
	std::cout << "\033[1;36mMateriaSource tests :\033[0m" << std::endl;
	std::cout << "\033[0;36m    Create objects :\033[0m" << std::endl;
	AMateria* c = new Cure();
	AMateria* i = new Ice();
	AMateria* m1;
	AMateria* m2;
	AMateria* m3;
	AMateria* m4;
	IMateriaSource* src = new MateriaSource();
	IMateriaSource* srcempty = new MateriaSource();
	ICharacter* freya = new Character("Freya");
	std::cout << std::endl;

	std::cout << "\033[0;36m    tests :\033[0m" << std::endl;
	std::cout << "\"\033[0;34msrc\033[0m\" try to learn \"";
	std::cout << "\033[0;33mc\033[0m\" (cure)" << std::endl;
	src->learnMateria(c);
	std::cout << "\"\033[0;34msrc\033[0m\" try to learn \"";
	std::cout << "\033[0;33mi\033[0m\" (ice)" << std::endl;
	src->learnMateria(i);
	std::cout << "\"\033[0;34msrc\033[0m\" try to learn \"";
	std::cout << "\033[0;33mi\033[0m\" (ice)" << std::endl;
	src->learnMateria(i);
	std::cout << "\"\033[0;34msrc\033[0m\" try to learn \"";
	std::cout << "\033[0;33mc\033[0m\" (cure)" << std::endl;
	src->learnMateria(c);
	std::cout << "\"\033[0;34msrc\033[0m\" try to learn \"";
	std::cout << "\033[0;33mc\033[0m\" (cure)" << std::endl;
	src->learnMateria(c);
	std::cout << std::endl;

	std::cout << "ask creation of materia \"\033[0;33mm1\033[0m\" (ice) by ";
	std::cout << "\"\033[0;34msrc\033[0m\"" << std::endl;
	m1 = src->createMateria("ice");
	std::cout << "ask creation of materia \"\033[0;33mm2\033[0m\" (cure) by ";
	std::cout << "\"\033[0;34msrc\033[0m\"" << std::endl;
	m2 = src->createMateria("cure");
	std::cout << "ask creation of materia \"\033[0;33mm3\033[0m\" (fire) by ";
	std::cout << "\"\033[0;34msrc\033[0m\"" << std::endl;
	m3 = src->createMateria("fire");
	std::cout << "ask creation of materia \"\033[0;33mm4\033[0m\" (ice) by ";
	std::cout << "\"\033[0;34msrcempty\033[0m\"" << std::endl;
	m4 = srcempty->createMateria("ice");
	std::cout << std::endl;

	std::cout << "use materia \"\033[0;33mm1\033[0m\" (ice)" << std::endl;
	if (m1 == NULL)
		std::cout << "materia wasn't created" << std::endl;
	else
		m1->use(*freya);
	std::cout << "use materia \"\033[0;33mm2\033[0m\" (cure)" << std::endl;
	if (m2 == NULL)
		std::cout << "materia wasn't created" << std::endl;
	else
		m2->use(*freya);
	std::cout << "use materia \"\033[0;33mm3\033[0m\" (none)" << std::endl;
	if (m3 == NULL)
		std::cout << "materia wasn't created" << std::endl;
	else
		m3->use(*freya);
	std::cout << "use materia \"\033[0;33mm4\033[0m\" (none)" << std::endl;
	if (m4 == NULL)
		std::cout << "materia wasn't created" << std::endl;
	else
		m4->use(*freya);
	std::cout << std::endl;

	std::cout << "\033[0;36m    Delete objects :\033[0m" << std::endl;
	delete c;
	delete i;
	delete m1;
	delete m2;
	delete m3;
	delete src;
	delete srcempty;
	delete freya;
	std::cout << std::endl;
}

void playerTests()
{
	std::cout << "\033[1;36mPlayer tests :\033[0m" << std::endl;
	std::cout << "\033[0;36m    Create objects :\033[0m" << std::endl;
	IMateriaSource* src = new MateriaSource();
	Character* freya = new Character("Freya");
	ICharacter* arik = new Character("Arik");
	Character* arya = new Character("Arya");
	AMateria* c = new Cure();
	AMateria* i = new Ice();
	AMateria* tmp1;
	AMateria* tmp2;
	AMateria* tmp3;
	AMateria* tmp4;
	AMateria* tmp5;
	AMateria* tmp6;
	AMateria* tmp7;
	AMateria* tmp8;

	std::cout << std::endl;

	std::cout << "\033[0;36m    tests :\033[0m" << std::endl;
	src->learnMateria(i);
	src->learnMateria(c);
	tmp1 = src->createMateria("ice");
	freya->equip(tmp1);
	tmp2 = src->createMateria("cure");
	freya->equip(tmp2);
	tmp3 = src->createMateria("ice");
	arik->equip(tmp3);
	tmp4 = src->createMateria("cure");
	arya->equip(tmp4);
	std::cout << std::endl;

	freya->use(0, *arik);
	arik->use(0, *arya);
	freya->use(1, *arya);
	freya->unequip(1);
	freya->use(1, *arya);
	arik->equip(tmp2);
	arik->use(1, *arik);
	std::cout << std::endl;

	arya->use(0, *arik);
	*arya = *freya;
	arya->use(0, *arik);
	arik->unequip(3);
	arik->unequip(2);
	arik->unequip(1);
	arik->unequip(0);
	std::cout << std::endl;

	tmp5 = src->createMateria("ice");
	freya->equip(tmp5);
	tmp6 = src->createMateria("ice");
	freya->equip(tmp6);
	tmp7 = src->createMateria("ice");
	freya->equip(tmp7);
	tmp8 = src->createMateria("ice");
	freya->equip(tmp8);
	std::cout << std::endl;

	std::cout << "\033[0;36m    Delete objects :\033[0m" << std::endl;
	delete src;
	delete freya;
	delete arik;
	delete arya;
	delete i;
	delete c;
	delete tmp2;
	delete tmp3;
	delete tmp8;
	std::cout << std::endl;
}

int main()
{
	materiaTests();
	materiaSourceTests();
	playerTests();
	std::cout << "\033[1;36mEnd of tests\033[0m" << std::endl;
	return (0);
}
