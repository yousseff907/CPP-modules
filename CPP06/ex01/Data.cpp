/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:23:55 by yitani            #+#    #+#             */
/*   Updated: 2025/09/11 12:35:08 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void)	:	id(0), name("")	{}

Data::Data(int id, const std::string &name)	:	id(id), name(name)	{}

void	Data::display(void)	const
{
	if (name == "")
	{
		std::cout << "This member is unnamed of id: " << id << std::endl;
	}
	else
	{
		std::cout << "Name: " << name << "\nid: " << id << std::endl;
	}
}
