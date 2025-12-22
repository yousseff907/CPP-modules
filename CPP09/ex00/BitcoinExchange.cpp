/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:51:21 by yitani            #+#    #+#             */
/*   Updated: 2025/12/22 19:47:50 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)	:	Content(other.Content)	{}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		Content = other.Content;
	return (*this);
}

bool	BitcoinExchange::parseAndStore(std::string fileName)
{
	std::ifstream	data(fileName);
	std::string	line;

	if (!data.is_open())
		return (false);

	std::getline(data, line);
	while (std::getline(data, line))
	{

	}
}