/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:40:53 by yitani            #+#    #+#             */
/*   Updated: 2025/09/10 22:49:41 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <cstdlib>
# include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

		static bool	isChar(const std::string &str);
		static bool	isInt(const std::string &str);
		static bool	isFloat(const std::string &str);
		static bool	isDouble(const std::string &str);
		static bool	isValidNumber(const std::string& str);
		static int	isSpecialValue(const std::string &str);

		static void	convertFromChar(const std::string &str);
		static void	convertFromInt(const std::string &str);
		static void	convertFromFloat(const std::string &str);
		static void	convertFromDouble(const std::string &str);
		static void	convertSpecial(const std::string &str);

	public:
		static void	convert(const std::string &str);
};

#endif