/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:32:22 by yitani            #+#    #+#             */
/*   Updated: 2025/08/10 23:52:54 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::add(void)
{
	Contact		newContact;
	std::string	input;

	std::cout << "Enter first name: ";
	if (!std::getline(std::cin, input) || std::cin.eof())
		return;
	if (!newContact.setFirstName(input))
		return;

	std::cout << "Enter last name: ";
	if (!std::getline(std::cin, input) || std::cin.eof())
		return;
	if (!newContact.setLastName(input))
		return;

	std::cout << "Enter nickname: ";
	if (!std::getline(std::cin, input) || std::cin.eof())
		return;
	if (!newContact.setNickname(input))
		return;

	std::cout << "Enter phone number: ";
	if (!std::getline(std::cin, input) || std::cin.eof())
		return;
	if (!newContact.setPhoneNumber(input))
		return;

	std::cout << "Enter darkest secret: ";
	if (!std::getline(std::cin, input) || std::cin.eof())
		return;
	if (!newContact.setDarkestSecret(input))
		return;

	contacts[index] = newContact;
	index = (index + 1) % 8;
	if (contact_count < 8)
		contact_count++;
}

std::string PhoneBook::truncateField(std::string field) const
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

void PhoneBook::search(void) const
{
	std::string input;

	if (contact_count == 0)
	{
		std::cout << "No contacts found!" << std::endl;
		return;
	}

	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname";
	std::cout << "|" << std::endl;

	for (int i = 0; i < contact_count; i++)
	{
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << truncateField(contacts[i].getFirstName());
		std::cout << "|" << std::setw(10) << truncateField(contacts[i].getLastName());
		std::cout << "|" << std::setw(10) << truncateField(contacts[i].getNickname());
		std::cout << "|" << std::endl;
	}

	std::cout << "Enter index to display: ";
	if (!std::getline(std::cin, input) || std::cin.eof())
		return;

	if (input.length() == 1 && isdigit(input[0]))
	{
		int idx = input[0] - '0';
		if (idx >= 0 && idx < contact_count)
		{
			std::cout << "First Name: " << contacts[idx].getFirstName() << std::endl;
			std::cout << "Last Name: " << contacts[idx].getLastName() << std::endl;
			std::cout << "Nickname: " << contacts[idx].getNickname() << std::endl;
			std::cout << "Phone Number: " << contacts[idx].getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << contacts[idx].getDarkestSecret() << std::endl;
		}
		else
			std::cout << "Invalid index!" << std::endl;
	}
	else
		std::cout << "Invalid input!" << std::endl;
}
