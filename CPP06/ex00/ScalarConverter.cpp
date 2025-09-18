/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:37:20 by yitani            #+#    #+#             */
/*   Updated: 2025/09/10 22:50:56 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	ScalarConverter::isChar(const std::string &str)
{
	if (str.length() != 3)
		return (false);
	if (str[0] != '\'' || str[2] != '\'')
		return (false);
	
	return (true);
}

bool	ScalarConverter::isValidNumber(const std::string &str)
{
	int	f_count = 0;
	int	sign_count = 0;
	int	c_count = 0;
	int	one_numb = 0;

	if (str.length() == 0)
		return (false);
	
	if (str[0] == '.' || str[str.length() - 1] == '.')
			return (false);

	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			one_numb++;

		if ((str[i] < '0' || str[i] > '9') && (str[i] != '.' && str[i] != 'f' && str[i] != '+' && str[i] != '-'))
			return (false);

		if ((str[i] == '+' || str[i] == '-') && (i != 0 || str.length() == 1))
			return (false);

		if (str[i] == 'f' && (i != str.length() - 1 || str.length() == 1))
			return (false);
			
		if (str[i] == 'f')
		{
			f_count++;
			if (f_count > 1)
				return (false);
		}

		if (str[i] == '+' || str[i] == '-')
		{
			sign_count++;
			if (sign_count > 1)
				return (false);
		}

		if (str[i] == '.')
		{
			c_count++;
			if (c_count > 1)
				return (false);
		}
	}

	if (one_numb == 0)
		return (false);

	return (true);
}

bool	ScalarConverter::isInt(const std::string &str)
{
	if (!isValidNumber(str))
		return (false);
	
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '.' || str[i] == 'f')
			return (false);
	}
	
	return (true);
}

bool	ScalarConverter::isFloat(const std::string &str)
{
	int	f = 0;
	int	point = 0;

	if (!isValidNumber(str))
		return (false);
	
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
			point++;
		
		if (str[i] == 'f')
			f++;
	}
	
	if (f == 0 || point == 0)
		return (false);
	
	return (true);
}

bool	ScalarConverter::isDouble(const std::string &str)
{
	int	f = 0;
	int	point = 0;

	if (!isValidNumber(str))
		return (false);
	
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
			point++;
		
		if (str[i] == 'f')
			f++;
	}
	
	if (f != 0 || point == 0)
		return (false);
	
	return (true);
}

int	ScalarConverter::isSpecialValue(const std::string &str)
{
	if (str == "nanf" || str == "-inff" || str == "+inff")
		return (1);

	if (str == "nan" || str == "-inf" || str == "+inf")
		return (2);

	return (0);
}

void ScalarConverter::convertFromChar(const std::string &str)
{
	char	c = str[1];

	if (isprint(c))
	{
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;

		return ;
	}

	std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	ScalarConverter::convertFromInt(const std::string &str)
{
	int numb = std::atoi(str.c_str());

	if (numb >= 0 && numb <= 127 && isprint(static_cast<char>(numb)))
		std::cout << "char: '" << static_cast<char>(numb) << "'" << std::endl;

	else if (numb >= 0 && numb <= 127)
		std::cout << "char: Non displayable" << std::endl;

	else
		std::cout << "char: impossible" << std::endl;

	std::cout << "int: " << numb << std::endl;
	std::cout << "float: " << static_cast<float>(numb) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(numb) << ".0" << std::endl;
}

void ScalarConverter::convertFromFloat(const std::string &str)
{
	float numb = static_cast<float>(std::atof(str.c_str()));
	int intValue = static_cast<int>(numb);

	if (intValue >= 0 && intValue <= 127 && isprint(static_cast<char>(intValue)))
		std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;

	else if (intValue >= 0 && intValue <= 127)
		std::cout << "char: Non displayable" << std::endl;

	else
		std::cout << "char: impossible" << std::endl;

	std::cout << "int: " << intValue << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << numb << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(numb) << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string &str)
{
	double numb = std::atof(str.c_str());
	int intValue = static_cast<int>(numb);

	if (intValue >= 0 && intValue <= 127 && isprint(static_cast<char>(intValue)))
		std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;

	else if (intValue >= 0 && intValue <= 127)
		std::cout << "char: Non displayable" << std::endl;

	else
		std::cout << "char: impossible" << std::endl;

	std::cout << "int: " << intValue << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(numb) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << numb << std::endl;
}

void ScalarConverter::convertSpecial(const std::string &str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (str == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "-inf")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (str == "+inf")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (str == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
}

void	ScalarConverter::convert(const std::string &str)
{
	if (isChar(str))
		convertFromChar(str);

	else if (isInt(str))
		convertFromInt(str);
	
	else if (isFloat(str))
		convertFromFloat(str);

	else if (isDouble(str))
		convertFromDouble(str);

	else if (isSpecialValue(str))
		convertSpecial(str);
	
	else
		std::cerr << "invalid input" << std::endl;
}
