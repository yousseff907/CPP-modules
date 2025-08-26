/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:36:47 by yitani            #+#    #+#             */
/*   Updated: 2025/08/26 21:38:57 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "🚔 WELCOME TO BROOKLYN NINE-NINE PRECINCT 🚔" << std::endl;
	std::cout << "=== TESTING DIAMONDTRAP CONSTRUCTOR CHAINING ===" << std::endl;

	std::cout << "\n--- Captain Holt creates the ultimate detective robot ---" << std::endl;
	DiamondTrap jake("Jake-Peralta");

	std::cout << "\n--- Default DiamondTrap (The Pontiac Bandit's creation) ---" << std::endl;
	DiamondTrap defaultBot;

	std::cout << "\n--- Amy creates a copy of Jake's robot ---" << std::endl;
	DiamondTrap amysBot(jake);

	std::cout << "\n=== TESTING DIAMONDTRAP IDENTITY CRISIS ===" << std::endl;

	std::cout << "\n--- Jake's robot having an existential crisis ---" << std::endl;
	jake.whoAmI();

	std::cout << "\n--- Default bot doesn't know who it is either ---" << std::endl;
	defaultBot.whoAmI();

	std::cout << "\n--- Amy's copy bot knows its origins ---" << std::endl;
	amysBot.whoAmI();

	std::cout << "\n=== TESTING DIAMONDTRAP COMBAT ABILITIES ===" << std::endl;

	std::cout << "\n--- Jake's robot attacks using ScavTrap powers ---" << std::endl;
	jake.attack("The Vulture");
	jake.attack("Wuntch");
	
	std::cout << "\n--- Taking damage like a true detective ---" << std::endl;
	jake.takeDamage(25);
	
	std::cout << "\n--- Self-repair with Brooklyn resilience ---" << std::endl;
	jake.beRepaired(15);

	std::cout << "\n=== TESTING INHERITED SPECIAL ABILITIES ===" << std::endl;

	std::cout << "\n--- ScavTrap ability: Gate keeping the precinct ---" << std::endl;
	jake.guardGate();

	std::cout << "\n--- FragTrap ability: High-fiving everyone (very Jake) ---" << std::endl;
	jake.highFivesGuys();

	std::cout << "\n=== COMPARING ROBOT TYPES (Stats Comparison) ===" << std::endl;

	std::cout << "\n--- Creating comparison bots ---" << std::endl;
	ClapTrap scully("Scully");
	ScavTrap charles("Charles-Boyle");
	FragTrap rosa("Rosa-Diaz");

	std::cout << "\n--- Attack power demonstration ---" << std::endl;
	scully.attack("Perp");
	charles.attack("Perp");
	rosa.attack("Perp");
	jake.attack("Perp");

	std::cout << "\n=== TESTING ASSIGNMENT OPERATOR ===" << std::endl;

	std::cout << "\n--- Gina creates her own fabulous robot ---" << std::endl;
	DiamondTrap gina("Gina-Linetti");
	gina.whoAmI();

	std::cout << "\n--- Gina's robot becomes exactly like Jake's (assignment) ---" << std::endl;
	gina = jake;
	gina.whoAmI();
	gina.attack("Hater");

	std::cout << "\n=== TESTING ENERGY DEPLETION (NIGHT SHIFT) ===" << std::endl;

	std::cout << "\n--- Terry's robot works overtime ---" << std::endl;
	DiamondTrap terry("Terry-Jeffords");
	terry.whoAmI();
	
	std::cout << "\n--- Terry's robot attacking all night (50 energy points) ---" << std::endl;
	for (int i = 1; i <= 52; i++)
	{
		if (i <= 3 || i > 50)
			std::cout << "Hour " << i << ": ";
		terry.attack("Criminal");
	}

	std::cout << "\n=== TESTING DAMAGE RESISTANCE (ROSA MODE) ===" << std::endl;

	std::cout << "\n--- Rosa's robot is basically indestructible ---" << std::endl;
	DiamondTrap rosaBot("Rosa-Robot");
	rosaBot.whoAmI();
	rosaBot.takeDamage(60);
	rosaBot.attack("Still Fighting");
	rosaBot.takeDamage(50);
	rosaBot.attack("Barely a scratch");
	rosaBot.highFivesGuys(); // Still friendly somehow

	std::cout << "\n=== TESTING COPY CONSTRUCTOR INDEPENDENCE ===" << std::endl;

	std::cout << "\n--- Proving Amy's copy is independent ---" << std::endl;
	amysBot.whoAmI();
	amysBot.takeDamage(30);
	amysBot.beRepaired(10);
	
	std::cout << "\n--- Original Jake robot is unaffected ---" << std::endl;
	jake.whoAmI();
	jake.attack("Proof of Independence");

	std::cout << "\n=== CAPTAIN HOLT'S FINAL ANALYSIS ===" << std::endl;

	std::cout << "\n--- All special abilities working ---" << std::endl;
	DiamondTrap holt("Captain-Holt");
	holt.whoAmI();
	holt.attack("Efficiency Review");
	holt.guardGate();
	holt.highFivesGuys();
	
	std::cout << "\n=== END OF SHIFT - DESTRUCTORS INCOMING ===" << std::endl;
	std::cout << "Title of your sex tape... I mean, end of test!" << std::endl;
	
	return (0);
}
