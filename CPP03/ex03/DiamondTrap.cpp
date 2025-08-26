/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:36:58 by yitani            #+#    #+#             */
/*   Updated: 2025/08/26 21:32:20 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)	:	name(name), ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
	std::cout << "DiamondTrap " << name << " has been created" << std::endl;
}

DiamondTrap::DiamondTrap(void)	:	name("default"), ClapTrap("default_clap_name"), ScavTrap(), FragTrap()
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)	:	name(other.name), ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "DiamondTrap: Called Copy Constructor" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		ClapTrap::operator=(other);
	}

	std::cout << "DiamondTrap copy assignment operator called" << std::endl;

	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: Called Destructor" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
