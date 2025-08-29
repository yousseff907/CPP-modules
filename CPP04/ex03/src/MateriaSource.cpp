/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:44:53 by yitani            #+#    #+#             */
/*   Updated: 2025/08/28 21:53:34 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default Constructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
		templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource Copy Constructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.templates[i] != NULL)
			templates[i] = other.templates[i]->clone();
		else
			templates[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource Assignment Operator Called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (templates[i] != NULL)
			{
				delete templates[i];
				templates[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (other.templates[i] != NULL)
				templates[i] = other.templates[i]->clone();
			else
				templates[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (templates[i] != NULL)
			delete templates[i];
	}
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (m == NULL)
	{
		std::cout << "Cannot learn null materia" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (templates[i] == NULL)
		{
			templates[i] = m->clone();
			std::cout << "MateriaSource learned " << m->getType() << " in slot " << i << std::endl;
			delete m;
			return;
		}
	}
	std::cout << "MateriaSource memory full! Cannot learn - materia deleted " << m->getType() << std::endl;
	delete m;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (templates[i] != NULL && templates[i]->getType() == type)
		{
			AMateria *result = templates[i]->clone();
			return (result);
		}
	}
	return (NULL);
}
