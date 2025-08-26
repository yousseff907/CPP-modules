/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:21:29 by yitani            #+#    #+#             */
/*   Updated: 2025/08/26 19:44:23 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "--- TESTING ONE PIECE CONSTRUCTOR CHAINING ---" << std::endl;

	std::cout << "\n--- Creating Zoro (FragTrap default constructor) ---" << std::endl;
	FragTrap Zoro;

	std::cout << "\n--- Creating Luffy (FragTrap with name) ---" << std::endl;
	FragTrap Luffy("Monkey D. Luffy");

	std::cout << "\n--- Creating Sanji (FragTrap copy constructor from Luffy) ---" << std::endl;
	FragTrap Sanji(Luffy);

	std::cout << "\n--- TESTING STRAW HAT FUNCTIONALITY ---" << std::endl;

	std::cout << "\n--- Testing inherited Straw Hat abilities ---" << std::endl;
	Luffy.attack("Marine Soldier");
	Luffy.takeDamage(30);
	Luffy.beRepaired(15);

	std::cout << "\n--- Testing Luffy’s special ability (High Five -> Meat Party) ---" << std::endl;
	Luffy.highFivesGuys();

	std::cout << "\n--- TESTING FRAGTRAP (Straw Hat) VS CLAPTRAP (Generic Pirate) ---" << std::endl;

	std::cout << "\n--- Creating ClapTrap ‘Buggy the Clown’ for comparison ---" << std::endl;
	ClapTrap Buggy("Buggy the Clown");

	std::cout << "\n--- Buggy attack vs Luffy attack ---" << std::endl;
	Buggy.attack("Target");
	Luffy.attack("Target");

	std::cout << "\n--- TESTING ENERGY DEPLETION (Straw Hat Stamina) ---" << std::endl;

	std::cout << "\n--- Testing Zoro stamina limits ---" << std::endl;
	for (int i = 1; i <= 32; i++)
	{
		if (i <= 3 || i > 30)
			std::cout << "Action " << i << ": ";
		Zoro.attack("Enemy Pirate");
	}

	std::cout << "\n--- TESTING DAMAGE RESISTANCE ---" << std::endl;

	std::cout << "\n--- Testing Sanji’s endurance ---" << std::endl;
	Sanji.takeDamage(50);
	Sanji.attack("Still Fighting Enemy");
	Sanji.takeDamage(60);
	Sanji.attack("Defeated Enemy");

	std::cout << "\n--- STRAW HATS RETREAT, DESTRUCTORS WILL BE CALLED ---" << std::endl;
	return (0);
}
