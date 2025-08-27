/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:31:38 by yitani            #+#    #+#             */
/*   Updated: 2025/08/27 23:13:29 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const int ARRAY_SIZE = 4;
	Animal *animals[ARRAY_SIZE];

	std::cout << "Creating array of animals..." << std::endl;

	for (int i = 0; i < ARRAY_SIZE / 2; i++)
		animals[i] = new Dog();

	for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++)
		animals[i] = new Cat();

	std::cout << "\nTesting sounds..." << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}

	std::cout << "\nDeleting animals..." << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
		delete animals[i];

	std::cout << "\n=== Testing Deep Copy ===" << std::endl;

	std::cout << "\nTesting Dog deep copy:" << std::endl;
	Dog originalDog;
	Dog copiedDog(originalDog);
	Dog assignedDog;
	assignedDog = originalDog;

	std::cout << "Original Dog: ";
	originalDog.makeSound();
	std::cout << "Copied Dog: ";
	copiedDog.makeSound();
	std::cout << "Assigned Dog: ";
	assignedDog.makeSound();

	std::cout << "\nTesting Cat deep copy:" << std::endl;
	Cat originalCat;
	Cat copiedCat(originalCat);
	Cat assignedCat;
	assignedCat = originalCat;

	std::cout << "Original Cat: ";
	originalCat.makeSound();
	std::cout << "Copied Cat: ";
	copiedCat.makeSound();
	std::cout << "Assigned Cat: ";
	assignedCat.makeSound();

	std::cout << "\n=== Testing polymorphic deletion ===" << std::endl;
	const Animal *testDog = new Dog();
	const Animal *testCat = new Cat();

	delete testDog;
	delete testCat;

	return (0);
}
