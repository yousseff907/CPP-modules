/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 19:21:06 by yitani            #+#    #+#             */
/*   Updated: 2025/08/26 19:25:41 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)	:	ClapTrap()
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string	name)	:	ClapTrap(name)
{
	this->name = name;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap :" << name << " has been created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)	:	ClapTrap(other)
{
	std::cout << "FragTrap: Called Copy Constructor" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);

	std::cout << "FragTrap copy assignment operator called" << std::endl;

	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " has requested a high five" << std::endl;
}
