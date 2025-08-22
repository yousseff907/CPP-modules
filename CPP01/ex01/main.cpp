/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 00:00:38 by yitani            #+#    #+#             */
/*   Updated: 2025/08/23 00:18:10 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	N;

	N = 10;
	Zombie *zombie_Horde = zombieHorde(N, "ZoMbIe");
	std::cout << std::endl;
	for (int i = 0; i < N; i++)
	{
		zombie_Horde[i].announce();
	}
	std::cout << std::endl;
	delete[] zombie_Horde;
}
