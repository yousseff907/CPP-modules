/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:43:32 by yitani            #+#    #+#             */
/*   Updated: 2025/08/10 23:44:41 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
		bool		isNameChar(char c) const;
		bool		isValidName(std::string str) const;
	public:
		std::string	getFirstName(void) const;
		bool		setFirstName(std::string firstName);

		std::string	getLastName(void) const;
		bool		setLastName(std::string lastName);

		std::string	getNickname(void) const;
		bool 		setNickname(std::string nickname);

		std::string	getPhoneNumber(void) const;
		bool 		setPhoneNumber(std::string phoneNumber);

		std::string getDarkestSecret(void) const;
		bool 		setDarkestSecret(std::string darkestSecret);
};

#endif