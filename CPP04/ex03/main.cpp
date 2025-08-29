/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:25:32 by yitani            #+#    #+#             */
/*   Updated: 2025/08/29 13:29:01 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/AMateria.hpp"
#include "inc/Ice.hpp"
#include "inc/Cure.hpp"
#include "inc/Character.hpp"
#include "inc/MateriaSource.hpp"

int main(void)
{
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter *me = new Character("me");
		AMateria *tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter *bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << std::endl;

	{
		Character hero("Hero");
		MateriaSource lib;

		lib.learnMateria(new Ice());
		hero.equip(lib.createMateria("ice"));
		hero.equip(lib.createMateria("fire"));

		hero.use(5, hero);
		hero.unequip(-1);

		Character copy(hero);
		copy.use(0, hero);
	}

	return 0;
}
