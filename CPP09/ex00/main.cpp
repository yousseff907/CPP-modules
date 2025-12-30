/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:51:24 by yitani            #+#    #+#             */
/*   Updated: 2025/12/30 21:09:35 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	std::string inputFile(argv[1]);

	BitcoinExchange btc;

	if (!btc.parseAndStore("data.csv"))
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return (1);
	}

	btc.processInputFile(inputFile);

	return (0);
}
