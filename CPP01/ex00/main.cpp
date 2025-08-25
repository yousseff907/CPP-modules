/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:48:06 by yitani            #+#    #+#             */
/*   Updated: 2025/08/24 18:19:34 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "=== newZombie() ===" << std::endl << std::endl;
	Zombie *heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;
	std::cout << std::endl;
	std::cout << "=== randomChump() ===" << std::endl << std::endl;
	randomChump("StackZombie");
	return (0);
}
