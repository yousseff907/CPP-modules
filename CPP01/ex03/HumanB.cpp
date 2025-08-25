/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 01:46:14 by yitani            #+#    #+#             */
/*   Updated: 2025/08/25 14:04:43 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

HumanB::HumanB(std::string name)	:	name(name), weapon(NULL)
{
	std::cout << "HumanB " << name << " has been created unarmed" << std::endl;
}

HumanB::~HumanB(void)
{
	if (weapon)
		std::cout << "HumanB " << name << " has been destroyed (had weapon " << weapon->getType() << ")" << std::endl;
	else
		std::cout << "HumanB " << name << " has been destroyed (no weapon)" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon_b)
{
	this->weapon = &weapon_b;
	std::cout << name << " has been equipped with " << weapon_b.getType() << std::endl;
}

void	HumanB::attack(void)
{
	if (weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon to attack with!" << std::endl;
}
