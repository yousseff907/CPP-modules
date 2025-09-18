/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:40:42 by yitani            #+#    #+#             */
/*   Updated: 2025/09/18 22:15:45 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array()	:	data(NULL),	arraySize(0)	{}

template<typename T>
Array<T>::Array(unsigned int n)	:	data(NULL), arraySize(n)
{
	if (n > 0)
	{
		data = new T[n];

		for (unsigned int i = 0; i < n; i++)
		{
			data[i] = T();
		}
	}
}

template<typename T>
Array<T>::Array(const Array &other)	:	data(NULL), arraySize(other.arraySize)
{
	if (arraySize > 0)
	{
		data = new T[arraySize];
	
		for (unsigned int i = 0; i < arraySize; i++)
		{
			data[i] = other.data[i];
		}
	}
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] data;

		arraySize = other.arraySize;
		
		if (arraySize > 0)
		{
			data = new T[arraySize];
		
			for (unsigned int i = 0; i < arraySize; i++)
			{
				data[i] = other.data[i];
			}
		}
		else
			data = NULL;
	}

	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	delete[] data;
}

template<typename T>
unsigned int	Array<T>::size(void) const
{
	return (arraySize);
}

template<typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= arraySize)
		throw OutOfBoundsException();
	
	return (data[index]);
}

template<typename T>
const T	&Array<T>::operator[](unsigned int index) const
{
	if (index >= arraySize)
		throw OutOfBoundsException();
	
	return (data[index]);
}
