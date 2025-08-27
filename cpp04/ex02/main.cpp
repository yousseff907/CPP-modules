/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:31:38 by yitani            #+#    #+#             */
/*   Updated: 2025/08/28 00:16:48 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	// These should NOT compile since Animal is abstract:

	// Animal animal;             
	// Animal* ptr = new Animal();

	// These still work:

	std::cout << "Creating Dog and Cat..." << std::endl;
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << " says: ";
	j->makeSound();
	std::cout << i->getType() << " says: ";
	i->makeSound();

	std::cout << "Deleting animals..." << std::endl;
	delete j;
	delete i;

	return (0);
}