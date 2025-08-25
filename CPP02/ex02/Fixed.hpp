/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 00:52:29 by yitani            #+#    #+#             */
/*   Updated: 2025/08/25 20:51:34 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_rawValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int number);
		Fixed(const float number);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		static Fixed				&min(Fixed &a, Fixed &b);
		static const Fixed			&min(const Fixed &a, const Fixed &b);
		static Fixed				&max(Fixed &a, Fixed &b);
		static const Fixed			&max(const Fixed &a, const Fixed &b);
};

std::ostream						&operator<<(std::ostream &os, const Fixed &fixed);

#endif