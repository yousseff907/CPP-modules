/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:20:00 by yitani            #+#    #+#             */
/*   Updated: 2025/09/18 21:26:49 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

void printInt(const int &n)
{
	std::cout << n << " ";
}

void printString(const std::string &s)
{
	std::cout << s << " ";
}

void doubleInt(int &n)
{
	n *= 2;
}

int main(void)
{
	int numbers[] = {1, 2, 3, 4, 5};
	std::cout << "Numbers: ";
	iter(numbers, 5, printInt);
	std::cout << std::endl;

	const int constNumbers[] = {10, 20, 30};
	std::cout << "Const numbers: ";
	iter(constNumbers, 3, printInt);
	std::cout << std::endl;

	std::string words[] = {"hello", "world", "test"};
	std::cout << "Words: ";
	iter(words, 3, printString);
	std::cout << std::endl;

	std::cout << "Doubling numbers..." << std::endl;
	iter(numbers, 5, doubleInt);
	std::cout << "After doubling: ";
	iter(numbers, 5, printInt);
	std::cout << std::endl;

	return (0);
}