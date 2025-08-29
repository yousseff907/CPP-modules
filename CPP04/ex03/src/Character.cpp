/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:09:59 by yitani            #+#    #+#             */
/*   Updated: 2025/08/28 21:35:48 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

Character::Character()	:	name("default")
{
	std::cout << "Character: Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(std::string const & name)	:	name(name)
{
	std::cout << "Character: " << name << " constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character &other)	:	name(other.name)
{
	std::cout << "Character: " << name << " constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i] != NULL)
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i] != NULL)
			{
				delete inventory[i];
				inventory[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++)
        {
            if (other.inventory[i] != NULL)
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
	}
	
	std::cout << "Character copy operator called" << std::endl;

	return (*this);
}

Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
    {
        if (inventory[i] != NULL)
            delete inventory[i];
    }
}

const std::string&	Character::getName(void) const
{
	return (this->name);
}

void	Character::equip(AMateria *m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			std::cout << name << " equipped " << m->getType() << " in slot " << i << std::endl;
			return ;
		}
	}
	std::cout << name << "'s inventory is full! Cannot equip - materia deleted" << m->getType() << std::endl;
	delete m;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid slot " << idx << std::endl;
		return;
	}
	if (inventory[idx] == NULL)
	{
		std::cout << "Slot " << idx << " is already empty" << std::endl;
		return;
	}
	std::cout << name << " unequipped " << inventory[idx]->getType() << " from slot " << idx << std::endl;
	inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid slot " << idx << std::endl;
		return;
	}
	if (inventory[idx] == NULL)
	{
		std::cout << "No materia in slot " << idx << std::endl;
		return;
	}
	inventory[idx]->use(target);
}
