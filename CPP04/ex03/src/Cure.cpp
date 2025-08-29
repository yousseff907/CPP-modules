/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:59:05 by yitani            #+#    #+#             */
/*   Updated: 2025/08/28 20:03:08 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure: Default constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << "Cure: Copy constructor called" << std::endl;
}

Cure	&Cure::operator=(const Cure &other)
{
	if (this != &other)
		AMateria::operator=(other);
	std::cout << "Cure: Copy assignment operator called" << std::endl;

	return *this;
}

Cure::~Cure(void)
{
	std::cout << "Cure: Destructor called" << std::endl;
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
