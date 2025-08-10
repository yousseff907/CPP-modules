/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:15:13 by yitani            #+#    #+#             */
/*   Updated: 2025/08/10 23:48:21 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	std::string	input;
	PhoneBook phonebook;

	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, input) || std::cin.eof())
			break ;
		std::cout << "You entered: " << input << std::endl;
		if (input == "EXIT")
			break ;
		if (input == "SEARCH")
			phonebook.search();
		if (input == "ADD")
			phonebook.add();
	}
	std::cout << "Program exited" << std::endl;
}
