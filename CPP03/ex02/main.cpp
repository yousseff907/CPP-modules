/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:21:29 by yitani            #+#    #+#             */
/*   Updated: 2025/08/26 18:19:07 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "--- TESTING CONSTRUCTOR CHAINING ---" << std::endl;

	std::cout << "\n--- Creating ScavTrap with default constructor (Walter White) ---" << std::endl;
	ScavTrap heisenberg;

	std::cout << "\n--- Creating ScavTrap with name (Jesse Pinkman) ---" << std::endl;
	ScavTrap jesse("Jesse Pinkman");

	std::cout << "\n--- Creating ScavTrap with copy constructor (Clone of Jesse) ---" << std::endl;
	ScavTrap jesseClone(jesse);

	std::cout << "\n--- TESTING BASIC FUNCTIONALITY ---" << std::endl;

	std::cout << "\n--- Testing inherited functions ---" << std::endl;
	jesse.attack("Tuco Salamanca");
	jesse.takeDamage(30);
	jesse.beRepaired(15);

	std::cout << "\n--- Testing ScavTrap special ability ---" << std::endl;
	jesse.guardGate();

	std::cout << "\n--- TESTING SCAVTRAP VS CLAPTRAP ---" << std::endl;

	std::cout << "\n--- Creating ClapTrap for comparison (Hank Schrader) ---" << std::endl;
	ClapTrap hank("Hank Schrader");

	std::cout << "\n--- Hank vs Jesse (Attack Comparison) ---" << std::endl;
	hank.attack("Drug Lord");
	jesse.attack("Drug Lord");

	std::cout << "\n--- TESTING ENERGY DEPLETION ---" << std::endl;

	std::cout << "\n--- Heisenberg tries to outlast the DEA ---" << std::endl;
	for (int i = 1; i <= 52; i++)
	{
		if (i <= 3 || i > 50)
			std::cout << "Operation " << i << ": ";
		heisenberg.attack("DEA Agent");
	}

	std::cout << "\n--- TESTING DAMAGE RESISTANCE ---" << std::endl;

	std::cout << "\n--- Jesse Clone under fire ---" << std::endl;
	jesseClone.takeDamage(50);
	jesseClone.attack("Rival Cartel");
	jesseClone.takeDamage(60);
	jesseClone.attack("Ghost Target");

	std::cout << "\n--- DESTRUCTORS WILL BE CALLED (End of the Empire) ---" << std::endl;
	return (0);
}
