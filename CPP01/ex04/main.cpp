/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 17:15:30 by yitani            #+#    #+#             */
/*   Updated: 2025/08/23 20:48:43 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <search> <replace>" << std::endl;
    	return (1);
	}

	std::string	filename = argv[1];
	std::string	search = argv[2];
	std::string	replace = argv[3];
	std::string	outfileName = filename + ".replace";
	std::string	line;

	std::ifstream	infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: Cannot open input file!" << std::endl;
		return (1);
	}

	std::ofstream	outfile(outfileName.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: Cannot create output file!" << std::endl;
		return (1);
	}

	while (std::getline(infile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(search, pos)) != std::string::npos)
		{
			line = line.substr(0, pos) + replace + line.substr(pos + search.length());
			pos += replace.length();
		}
		outfile << line << std::endl;
	}
	
	return (0);
}
