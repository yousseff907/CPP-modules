/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 07:41:24 by yitani            #+#    #+#             */
/*   Updated: 2025/10/11 21:13:42 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include <string>

template <typename	T>
std::string	easyfind(T container, int toFind)
{
	if (std::find(container.begin(), container.end(), toFind) == container.end())
		return ("element not found");
	return ("element found");
}

#endif