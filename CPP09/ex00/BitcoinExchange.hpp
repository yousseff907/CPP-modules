/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:51:19 by yitani            #+#    #+#             */
/*   Updated: 2025/12/30 21:04:06 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <string>
# include <fstream>
# include <cstdio>
# include <algorithm>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	Content;
		double							getExchangeRate(const std::string	&date);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange&	operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		bool	parseAndStore(const std::string &fileName);
		void	processInputFile(const std::string &fileName);
};

#endif