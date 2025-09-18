/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:14:11 by yitani            #+#    #+#             */
/*   Updated: 2025/09/18 21:19:34 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template<typename T, typename F>
void	iter(T *arr, size_t n, F function)
{
	for (size_t i = 0; i < n; i++)
	{
		function(arr[i]);
	}
}

template<typename T, typename F>
void	iter(const T *arr, size_t n, F function)
{
	for (size_t i = 0; i < n; i++)
	{
		function(arr[i]);
	}
}

#endif