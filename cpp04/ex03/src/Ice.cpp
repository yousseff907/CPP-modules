/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:52:18 by yitani            #+#    #+#             */
/*   Updated: 2025/08/28 19:54:55 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice: Default constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "Ice: Copy constructor called" << std::endl;
}

Ice	&Ice::operator=(const Ice &other)
{
	if (this != &other)
		AMateria::operator=(other);
	std::cout << "Ice: Copy assignment operator called" << std::endl;

	return *this;
}

Ice::~Ice(void)
{
	std::cout << "Ice: Destructor called" << std::endl;
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
