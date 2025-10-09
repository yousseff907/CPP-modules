/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:38:43 by yitani            #+#    #+#             */
/*   Updated: 2025/10/09 11:22:19 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;

		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end);

		class SpanFullException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Span is full");
				}
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("There is no span");
				}
		};
};

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
	while (begin != end)
	{
		addNumber(*begin);
		++begin;
	}
}

#endif