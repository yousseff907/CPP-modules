/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:18:11 by yitani            #+#    #+#             */
/*   Updated: 2025/08/28 18:42:07 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria(void)	:	type("")
{
	std::cout << "AMateria: Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &AMateriaType)	:	type(AMateriaType)
{
	std::cout << "AMateria: " << type << " constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other)	:	type(other.type)
{
	std::cout << "AMateria: " << type << " copy constructor called" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "AMateria: " << type << " copy assignment operator called" << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria: Default destructor called" << std::endl;
}
