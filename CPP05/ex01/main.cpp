/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 00:00:00 by yitani            #+#    #+#             */
/*   Updated: 2025/09/23 14:31:11 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "=== EXERCISE 01: FORMS AND BUREAUCRATS ===" << std::endl;

	std::cout << "\n--- Test 1: Creating valid forms ---" << std::endl;
	try
	{
		Form taxForm("Tax Form", 50, 25);
		std::cout << taxForm << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Invalid form (grade too high) ---" << std::endl;
	try
	{
		Form invalidForm("Invalid", 0, 50);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3: Invalid form (grade too low) ---" << std::endl;
	try
	{
		Form invalidForm("Invalid", 200, 50);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 4: Successful signing ---" << std::endl;
	try
	{
		Form easyForm("Easy Form", 100, 50);
		Bureaucrat alice("Alice", 50);

		std::cout << "Before: " << easyForm << std::endl;
		alice.signForm(easyForm);
		std::cout << "After:  " << easyForm << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 5: Failed signing (grade too low) ---" << std::endl;
	try
	{
		Form hardForm("Hard Form", 10, 5);
		Bureaucrat bob("Bob", 50);

		std::cout << "Before: " << hardForm << std::endl;
		bob.signForm(hardForm);
		std::cout << "After:  " << hardForm << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 6: Boundary test (exact grade match) ---" << std::endl;
	try
	{
		Form boundaryForm("Boundary", 50, 25);
		Bureaucrat exact("Exact", 50);

		exact.signForm(boundaryForm);
		std::cout << boundaryForm << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 7: Multiple people, same form ---" << std::endl;
	try
	{
		Form sharedForm("Shared", 75, 50);
		Bureaucrat intern("Intern", 100);
		Bureaucrat boss("Boss", 25);

		std::cout << "Form: " << sharedForm << std::endl;
		intern.signForm(sharedForm);
		boss.signForm(sharedForm);
		std::cout << "Final: " << sharedForm << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Tests completed! ===" << std::endl;
	return 0;
}