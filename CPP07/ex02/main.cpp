/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 22:17:03 by yitani            #+#    #+#             */
/*   Updated: 2025/09/18 22:19:56 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main(void)
{
	std::cout << "=== Array Template Tests ===" << std::endl;

	try
	{
		// Test 1: Default constructor (empty array)
		std::cout << "\n--- Test 1: Default Constructor ---" << std::endl;
		Array<int> emptyArray;
		std::cout << "Empty array size: " << emptyArray.size() << std::endl;

		// Test 2: Constructor with size
		std::cout << "\n--- Test 2: Constructor with Size ---" << std::endl;
		Array<int> intArray(5);
		std::cout << "Int array size: " << intArray.size() << std::endl;

		// Fill array with values
		for (unsigned int i = 0; i < intArray.size(); i++)
			intArray[i] = i * 10;

		// Display array
		std::cout << "Int array contents: ";
		for (unsigned int i = 0; i < intArray.size(); i++)
			std::cout << intArray[i] << " ";
		std::cout << std::endl;

		// Test 3: Copy constructor
		std::cout << "\n--- Test 3: Copy Constructor ---" << std::endl;
		Array<int> copyArray(intArray);
		std::cout << "Copy array size: " << copyArray.size() << std::endl;
		std::cout << "Copy array contents: ";
		for (unsigned int i = 0; i < copyArray.size(); i++)
			std::cout << copyArray[i] << " ";
		std::cout << std::endl;

		// Modify original to test deep copy
		intArray[0] = 999;
		std::cout << "After modifying original[0] = 999:" << std::endl;
		std::cout << "Original[0]: " << intArray[0] << std::endl;
		std::cout << "Copy[0]: " << copyArray[0] << " (should be unchanged)" << std::endl;

		// Test 4: Assignment operator
		std::cout << "\n--- Test 4: Assignment Operator ---" << std::endl;
		Array<int> assignArray(3);
		assignArray[0] = 100;
		assignArray[1] = 200;
		assignArray[2] = 300;

		std::cout << "Before assignment - assignArray size: " << assignArray.size() << std::endl;
		assignArray = intArray; // Assignment
		std::cout << "After assignment - assignArray size: " << assignArray.size() << std::endl;
		std::cout << "assignArray[0]: " << assignArray[0] << std::endl;

		// Test 5: Different types
		std::cout << "\n--- Test 5: String Array ---" << std::endl;
		Array<std::string> stringArray(3);
		stringArray[0] = "Hello";
		stringArray[1] = "World";
		stringArray[2] = "Templates";

		std::cout << "String array: ";
		for (unsigned int i = 0; i < stringArray.size(); i++)
			std::cout << stringArray[i] << " ";
		std::cout << std::endl;

		// Test 6: Const array (tests const operator[])
		std::cout << "\n--- Test 6: Const Array ---" << std::endl;
		const Array<int> constArray(copyArray);
		std::cout << "Const array[1]: " << constArray[1] << std::endl;
		// constArray[1] = 999;  // This would cause compiler error

		// Test 7: Exception handling
		std::cout << "\n--- Test 7: Exception Handling ---" << std::endl;
		try
		{
			std::cout << "Trying to access index 10 in array of size 5..." << std::endl;
			std::cout << intArray[10] << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

		// Test 8: Empty array access
		std::cout << "\n--- Test 8: Empty Array Access ---" << std::endl;
		try
		{
			std::cout << "Trying to access index 0 in empty array..." << std::endl;
			std::cout << emptyArray[0] << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== All tests completed ===" << std::endl;
	return (0);
}