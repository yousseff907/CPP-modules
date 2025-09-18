/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:00:02 by yitani            #+#    #+#             */
/*   Updated: 2025/09/18 21:10:12 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T &a, T &b)
{
	T	temp = a;
	a = b;
	b = temp;
}

template<typename T>
const T	&max(const T &a, const T &b)
{
	if (b >= a)
		return (b);
	
	return (a);	
}

template<typename T>
const T	&min(const T &a, const T &b)
{
	if (b <= a)
		return(b);

	return (a);
}

#endif