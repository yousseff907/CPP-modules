/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:52:54 by yitani            #+#    #+#             */
/*   Updated: 2025/10/09 11:19:09 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>

Span::Span()	:	_maxSize(0)	{}

Span::Span(unsigned int N)	:	_maxSize(N)	{}

Span::Span(const Span &other)	:	_maxSize(other._maxSize),	_numbers(other._numbers)	{}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_maxSize = other._maxSize;
		this->_numbers = other._numbers;
	}
	return (*this);

}

Span::~Span()	{}

void	Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw (SpanFullException());
	
	_numbers.push_back(number);
}

int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw (NoSpanException());
	int maximum = *std::max_element(_numbers.begin(), _numbers.end());
	int minimum = *std::min_element(_numbers.begin(), _numbers.end());

	return (maximum - minimum);
}

int	Span::shortestSpan() const
{
	std::vector <int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	int	min = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); i++)
	{
		if (sorted[i] - sorted[i - 1] < min)
			min = sorted[i] - sorted[i - 1];
	}
	return (min);
}