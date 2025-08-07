/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:43:44 by yitani            #+#    #+#             */
/*   Updated: 2025/08/07 23:53:05 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::getFirstName(void) const
{
	return (this->firstName);
}

void	Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}
