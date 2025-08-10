/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:30:22 by yitani            #+#    #+#             */
/*   Updated: 2025/08/10 23:48:09 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact 	contacts[8];
		int			index;
		int			contact_count;
		std::string	truncateField(std::string field) const;
	public:
		// Initialize index and contact_count to 0;
		PhoneBook() : index(0), contact_count(0) {}

		// Add and Search functions
		void		add(void);
		void		search(void) const;
};

#endif