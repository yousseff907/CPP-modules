/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 10:56:23 by yitani            #+#    #+#             */
/*   Updated: 2025/09/23 14:33:04 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "=== CPP05 EX02: CONCRETE FORMS TEST ===" << std::endl;

	Bureaucrat intern("Intern", 150);
	Bureaucrat manager("Manager", 50);  
	Bureaucrat president("President", 1);

	std::cout << "\n--- BUREAUCRATS ---" << std::endl;
	std::cout << intern << std::endl;
	std::cout << manager << std::endl;
	std::cout << president << std::endl;

	std::cout << "\n=== SHRUBBERY CREATION FORM TESTS ===" << std::endl;
	try 
	{
		ShrubberyCreationForm garden("garden");
		std::cout << "Form: " << garden << std::endl;

		std::cout << "\n--- Test: Intern tries to sign (should fail) ---" << std::endl;
		intern.signForm(garden);

		std::cout << "\n--- Test: Manager signs (should succeed) ---" << std::endl;
		manager.signForm(garden);

		std::cout << "\n--- Test: Manager executes (should succeed) ---" << std::endl;
		manager.executeForm(garden);

		std::cout << "\n--- Test: Execute unsigned form ---" << std::endl;
		ShrubberyCreationForm unsigned_form("unsigned");
		manager.executeForm(unsigned_form);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== ROBOTOMY REQUEST FORM TESTS ===" << std::endl;
	try
	{
		RobotomyRequestForm robot("Bender");
		std::cout << "Form: " << robot << std::endl;

		std::cout << "\n--- Test: Manager signs and executes (should succeed) ---" << std::endl;
		manager.signForm(robot);
		manager.executeForm(robot);

		std::cout << "\n--- Test: Multiple executions (alternating results) ---" << std::endl;
		for (int i = 0; i < 4; i++)
		{
			std::cout << "Execution " << (i + 1) << ": ";
			manager.executeForm(robot);
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== PRESIDENTIAL PARDON FORM TESTS ===" << std::endl;
	try
	{
		PresidentialPardonForm pardon("Arthur Dent");
		std::cout << "Form: " << pardon << std::endl;

		std::cout << "\n--- Test: Manager tries to execute (should fail - grade too low) ---" << std::endl;
		manager.signForm(pardon);
		manager.executeForm(pardon);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		PresidentialPardonForm pardon2("Ford Prefect");
		std::cout << "\n--- Test: President signs and executes (should succeed) ---" << std::endl;
		president.signForm(pardon2);
		president.executeForm(pardon2);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== BOUNDARY TESTS ===" << std::endl;
	try
	{
		Bureaucrat exact_signer("ExactSigner", 25);
		Bureaucrat exact_executor("ExactExecutor", 5);

		PresidentialPardonForm boundary_test("Boundary Test");
		
		exact_signer.signForm(boundary_test);
		exact_executor.executeForm(boundary_test);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
	return 0;
}
