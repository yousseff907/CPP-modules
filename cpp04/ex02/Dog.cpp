/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:53:53 by yitani            #+#    #+#             */
/*   Updated: 2025/08/27 19:39:23 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)	: Animal(), _Brain(new Brain)
{
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other)	:	Animal(other), _Brain(new Brain(*other._Brain))
{
	type = other.type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _Brain;
		_Brain = new Brain(*other._Brain);
		this->type = other.type;
	}

	std::cout << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	delete _Brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void)	const
{
	std::cout << "Woof Woof !" << std::endl;
}
