/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:31:38 by yitani            #+#    #+#             */
/*   Updated: 2025/08/27 15:31:39 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "Creating objects directly" << std::endl;
	Animal animal;
	Dog dog;
	Cat cat;

	std::cout << std::endl;

	std::cout << "Direct method calls" << std::endl;
	std::cout << animal.getType() << " makes: ";
	animal.makeSound();
	std::cout << dog.getType() << " makes: ";
	dog.makeSound();
	std::cout << cat.getType() << " makes: ";
	cat.makeSound();

	std::cout << std::endl;

	std::cout << "Creating objects through base pointers" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	std::cout << "Testing getType through base pointers" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl;

	std::cout << "Testing makeSound - virtual dispatch" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	std::cout << "Creating WrongAnimal objects" << std::endl;
	WrongAnimal wrongAnimal;
	WrongCat wrongCat;

	std::cout << std::endl;

	std::cout << "Direct calls on Wrong classes" << std::endl;
	std::cout << wrongAnimal.getType() << " makes: ";
	wrongAnimal.makeSound();
	std::cout << wrongCat.getType() << " makes: ";
	wrongCat.makeSound();

	std::cout << std::endl;

	std::cout << "Creating WrongCat through base pointer" << std::endl;
	const WrongAnimal* wrongPtr = new WrongCat();

	std::cout << std::endl;

	std::cout << "Testing broken polymorphism" << std::endl;
	std::cout << wrongPtr->getType() << " " << std::endl;
	wrongPtr->makeSound();

	std::cout << std::endl;

	std::cout << "Array demonstration - correct polymorphism" << std::endl;
	Animal* animals[3] = {
		new Animal(),
		new Dog(),
		new Cat()
	};

	for (int k = 0; k < 3; k++) {
		std::cout << animals[k]->getType() << ": ";
		animals[k]->makeSound();
	}

	std::cout << std::endl;

	std::cout << "Array demonstration - broken polymorphism" << std::endl;
	WrongAnimal* wrongAnimals[2] = {
		new WrongAnimal(),
		new WrongCat()
	};

	for (int k = 0; k < 2; k++) {
		std::cout << wrongAnimals[k]->getType() << ": ";
		wrongAnimals[k]->makeSound();
	}

	std::cout << std::endl;

	std::cout << "Copy constructor test" << std::endl;
	Dog originalDog;
	Dog copiedDog(originalDog);
	std::cout << "Original: ";
	originalDog.makeSound();
	std::cout << "Copy: ";
	copiedDog.makeSound();

	std::cout << std::endl;

	std::cout << "Cleanup - deleting objects" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wrongPtr;

	for (int k = 0; k < 3; k++) {
		delete animals[k];
	}
	for (int k = 0; k < 2; k++) {
		delete wrongAnimals[k];
	}

	return (0);
}
