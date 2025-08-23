/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 01:45:17 by yitani            #+#    #+#             */
/*   Updated: 2025/08/23 15:57:41 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string	Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

Weapon::Weapon(std::string name)
{
	this->type = name;
	std::cout << name << " has been created." << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << this->type << " has been destroyed." << std::endl;
}
