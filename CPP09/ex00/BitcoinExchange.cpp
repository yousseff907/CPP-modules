/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:51:21 by yitani            #+#    #+#             */
/*   Updated: 2026/01/22 23:51:16 by yitani           ###   ########.fr       */
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

double	BitcoinExchange::getExchangeRate(const std::string &date)
{
	std::map<std::string, double>::iterator it = Content.find(date);

	if (it != Content.end())
		return (it->second);

	std::map<std::string, double>::iterator lower = Content.lower_bound(date);

	if (lower == Content.begin())
		return (-1);

	--lower;
	return (lower->second);
}

bool	BitcoinExchange::parseAndStore(const std::string &fileName)
{
	std::ifstream	data(fileName.c_str());
	std::string		line;

	if (!data.is_open())
		return (false);

	std::getline(data, line);
	while (std::getline(data, line))
	{
		size_t		pos = line.find(',');
		std::string	date = line.substr(0, pos);
		double		value = std::atof(line.substr(pos + 1).c_str());
		this->Content[date] = value;
	}
	data.close();
	return (true);
}

void	 BitcoinExchange::processInputFile(const std::string& fileName)
{
	std::ifstream input(fileName.c_str());
	std::string line;

	if (!input.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}

	std::getline(input, line);
	if (line != "date | value")
	{
		std::cerr << "Error: invalid file format." << std::endl;
		return ;
	}

	while (std::getline(input, line))
	{
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		if (pos == 0 || pos + 2 >= line.length())
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string	date = line.substr(0, pos - 1);
		std::string	stringValue = line.substr(pos + 2);

		if ((stringValue.find_first_of('.') != stringValue.find_last_of('.'))
		|| stringValue[stringValue.length() - 1] == '.'
		|| (stringValue.find_first_not_of("0123456789.-") != std::string::npos)
		|| ((stringValue.find('-') != std::string::npos) && stringValue[0] != '-'))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		double		value = std::atof(stringValue.c_str());

		if (value <= 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		if (date.length() != 10)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (date[4] != '-' || date[7] != '-')
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string	year = date.substr(0, 4);
		std::string	month = date.substr(5, 2);
		std::string	day = date.substr(8, 2);

		if (year.find_first_not_of("0123456789") != std::string::npos
		|| month.find_first_not_of("0123456789") != std::string::npos
		|| day.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		int y = std::atoi(year.c_str());
		int m = std::atoi(month.c_str());
		int d = std::atoi(day.c_str());
		
		if (y <= 0 || (m <= 0 || m > 12) || (d <= 0 || d > 31))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		int maxDays = 31;

		if (m == 2)
		{
			if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
				maxDays = 29; 
			else
				maxDays = 28;
		}
		else if (m == 4 || m == 6 || m == 9 || m == 11)
		{
			maxDays = 30;
		}

		if (d > maxDays)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		double	rate = getExchangeRate(date);

		if (rate == -1)
		{
			std::cerr << "Error: date too early." << std::endl;
			continue;
		}

		else
		{
			std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
		}
	}
}