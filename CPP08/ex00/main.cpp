/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 07:45:11 by yitani            #+#    #+#             */
/*   Updated: 2025/10/09 10:34:35 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main(void)
{
	{
		std::vector<int> V;
		V.push_back(8);
		V.push_back(7);
		V.push_back(5);
		V.push_back(12);
		V.push_back(99);
		V.push_back(56);
		std::cout << easyfind(V, 12) << std::endl;
	}

	{
		std::vector<int> V;
		V.push_back(8);
		V.push_back(7);
		V.push_back(5);
		V.push_back(12);
		V.push_back(99);
		V.push_back(56);
		std::cout << easyfind(V, -82) << std::endl;
	}

	{
		std::vector<int> V;
		V.push_back(8);
		V.push_back(7);
		V.push_back(5);
		V.push_back(12);
		V.push_back(-82);
		V.push_back(56);
		std::cout << easyfind(V, 0) << std::endl;
	}
}