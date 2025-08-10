/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:43:44 by yitani            #+#    #+#             */
/*   Updated: 2025/08/10 23:06:20 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

bool	Contact::isNameChar(char c) const
{
	if (isalpha(c))
		return (true);
	if (c == ' ' || c == '-' || c == '\'')
		return (true);
	else
		return (false);
}

bool	Contact::isValidName(std::string str) const
{
	if (str.empty())
		return (false);
	if (str.find_first_not_of(" \n\t") == std::string::npos)
		return (false);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isNameChar(str[i]))
			return (false);
	}
	return (true);
}

std::string	Contact::getFirstName(void) const
{
	return (this->firstName);
}

bool	Contact::setFirstName(std::string firstName)
{
	if (!isValidName(firstName))
	{
		std::cout << "Error: First name can only contain letters, spaces, hyphens, and apostrophes!" << std::endl;
		return (false);
	}
	this->firstName = firstName;
	return (true);
}

std::string	Contact::getLastName(void) const
{
	return (this->lastName);
}

bool	Contact::setLastName(std::string lastName)
{
	if (!isValidName(lastName))
	{
		std::cout << "Error: Last name can only contain letters, spaces, hyphens, and apostrophes!" << std::endl;
		return (false);
	}
	this->lastName = lastName;
	return (true);
}

std::string	Contact::getNickname(void) const
{
	return (this->nickname);
}

bool Contact::setNickname(std::string nickname)
{
    if (nickname.empty())
	{
        std::cout << "Error: Nickname cannot be empty!" << std::endl;
        return (false);
	}
    if (nickname.find_first_not_of(" \t\n") == std::string::npos)
	{
        std::cout << "Error: Nickname cannot be only spaces!" << std::endl;
        return (false);
    }
    this->nickname = nickname;
	return (true);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->phoneNumber);
}

bool Contact::setPhoneNumber(std::string phoneNumber)
{
    if (phoneNumber.empty()) {
        std::cout << "Error: Phone number cannot be empty!" << std::endl;
        return (false);
    }
    if (phoneNumber.find_first_not_of(" \t\n") == std::string::npos) {
        std::cout << "Error: Phone number cannot be only spaces!" << std::endl;
        return (false);
    }
    for (size_t i = 0; i < phoneNumber.length(); i++)
    {
        char c = phoneNumber[i];
        if (!isdigit(c) && c != ' ' && c != '+' && c != '-' && c != '(' && c != ')')
        {
            std::cout << "Error: Phone number contains invalid characters!" << std::endl;
            return (false);
        }
    }
    this->phoneNumber = phoneNumber;
	return (true);
}

std::string Contact::getDarkestSecret(void) const
{
    return (this->darkestSecret);
}

bool Contact::setDarkestSecret(std::string darkestSecret)
{
    if (darkestSecret.empty())
	{
        std::cout << "Error: Darkest secret cannot be empty!" << std::endl;
        return (false);
    }
    if (darkestSecret.find_first_not_of(" \t\n") == std::string::npos)
	{
        std::cout << "Error: Darkest secret cannot be only spaces!" << std::endl;
        return (false);
    }
    this->darkestSecret = darkestSecret;
	return (true);
}
