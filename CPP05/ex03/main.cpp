/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 00:00:00 by yitani            #+#    #+#             */
/*   Updated: 2025/09/08 18:45:04 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <sstream>

int main(void)
{
	std::cout << "=== INTERN TEST CASES - EDGE SCENARIOS ===" << std::endl;

	Intern intern;
	Bureaucrat boss("Boss", 5);

	std::cout << "\n--- Test 1: Partial string matching ---" << std::endl;
	AForm *form1 = intern.makeForm("robotomy", "C3PO");
	if (form1)
	{
		delete form1;
	}

	std::cout << "\n--- Test 2: Form names with spaces ---" << std::endl;
	AForm *form2 = intern.makeForm("  shrubbery creation  ", "garden");
	if (form2)
	{
		delete form2;
	}

	std::cout << "\n--- Test 3: Special target names ---" << std::endl;
	AForm *form3 = intern.makeForm("presidential pardon", "Arthur-Dent@Earth.com");
	if (form3)
	{
		std::cout << *form3 << std::endl;
		boss.signForm(*form3);
		boss.executeForm(*form3);
		delete form3;
	}

	std::cout << "\n--- Test 4: Extremely long target ---" << std::endl;
	AForm *form4 = intern.makeForm("robotomy request",
								   "VeryLongRobotNameThatGoesOnAndOnAndOnForeverAndEverUntilItBecomesRidiculous");
	if (form4)
	{
		boss.signForm(*form4);
		boss.executeForm(*form4);
		delete form4;
	}

	std::cout << "\n--- Test 5: Numbers in form names ---" << std::endl;
	AForm *form5 = intern.makeForm("form27b", "office");
	if (form5)
	{
		delete form5;
	}

	std::cout << "\n--- Test 6: Empty target ---" << std::endl;
	AForm *form7 = intern.makeForm("robotomy request", "");
	if (form7)
	{
		std::cout << *form7 << std::endl;
		delete form7;
	}

	std::cout << "\n=== EDGE TESTS COMPLETE ===" << std::endl;
	return 0;
}
