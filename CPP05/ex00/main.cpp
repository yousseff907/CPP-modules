/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:44:57 by yitani            #+#    #+#             */
/*   Updated: 2025/09/02 11:22:08 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat alice("Alice", 50);
	std::cout << alice << std::endl;

	alice.incrementGrade();
	std::cout << alice << std::endl;

	alice.decrementGrade();
	std::cout << alice << std::endl;

	try
	{
		Bureaucrat invalid("Invalid", 0);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat invalid("Invalid decrement", 150);
		invalid.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
