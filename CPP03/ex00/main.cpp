/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:21:29 by yitani            #+#    #+#             */
/*   Updated: 2025/08/26 16:33:51 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap luke("Luke Skywalker");
	ClapTrap r2d2("R2-D2");
	ClapTrap vader(r2d2);
	std::cout << std::endl;

	r2d2.attack("Stormtrooper");
	r2d2.takeDamage(5);
	r2d2.beRepaired(3);

	std::cout << std::endl;

	for (int i = 0; i < 11; i++)
		r2d2.attack("Battle Droid");

	std::cout << std::endl;

	luke.takeDamage(15);
	luke.attack("Darth Vader");
	luke.beRepaired(5);

	return (0);
}
