/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:53:02 by yitani            #+#    #+#             */
/*   Updated: 2025/08/28 00:14:27 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)	:	type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other)	: type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

std::string	Animal::getType(void)	const
{
	return (this->type);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal	&Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Animal copy assignment operator called" << std::endl;
	return (*this);
}
