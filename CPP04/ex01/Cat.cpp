/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:53:45 by yitani            #+#    #+#             */
/*   Updated: 2025/08/27 19:39:06 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)	: Animal(), _Brain(new Brain)
{
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other)	:	Animal(other), _Brain(new Brain(*other._Brain))
{
	type = other.type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _Brain;
		_Brain = new Brain(*other._Brain);
		this->type = other.type;
	}

	std::cout << "Cat copy assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	delete _Brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void)	const
{
	std::cout << "Meow Meow !" << std::endl;
}
