/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:41:06 by yitani            #+#    #+#             */
/*   Updated: 2025/08/23 20:55:08 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl harl;

	std::cout << "=== Testing DEBUG level ===" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "=== Testing INFO level ===" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;

	std::cout << "=== Testing WARNING level ===" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;

	std::cout << "=== Testing ERROR level ===" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;

	std::cout << "=== Testing invalid level ===" << std::endl;
	harl.complain("INVALID");
	std::cout << std::endl;

	std::cout << "=== Testing all levels in sequence ===" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;

	return (0);
}
