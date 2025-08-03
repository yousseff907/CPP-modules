/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 22:01:15 by yitani            #+#    #+#             */
/*   Updated: 2025/08/03 22:56:41 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>

int	main(int argc, char **argv)
{
	char	*upper;
	int		i;
	int		j;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (i = 1; i < argc; i++)
	{
		upper = new char[strlen(argv[i]) + 1];
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			upper[j] = toupper(argv[i][j]);
		}
		upper[j] = '\0';
		std::cout << upper;
		delete[] upper;
	}
	std::cout << "" << std::endl;
	return (0);
}
