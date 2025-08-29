/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:00:47 by yitani            #+#    #+#             */
/*   Updated: 2025/08/27 15:27:33 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)	:	type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)	: type(other.type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

std::string	WrongAnimal::getType(void)	const
{
	return (this->type);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	return (*this);
}

void WrongAnimal::makeSound(void)	const
{
	std::cout << "Some generic wrong animal sound" << std::endl;
}
