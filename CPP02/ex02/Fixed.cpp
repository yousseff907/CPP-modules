/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 00:52:25 by yitani            #+#    #+#             */
/*   Updated: 2025/08/25 21:32:01 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawValue = number * 256;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawValue = roundf(number * 256);
}

Fixed::Fixed(void)
{
	this->_rawValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_rawValue = other.getRawBits();
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (this->_rawValue / 256.0f);
}

int		Fixed::toInt(void) const
{
	return (int)(this->_rawValue / 256.0f);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		this->_rawValue = other.getRawBits();

	return *this;
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->_rawValue < other._rawValue);
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->_rawValue > other._rawValue);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->_rawValue >= other._rawValue);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->_rawValue <= other._rawValue);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->_rawValue == other._rawValue);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->_rawValue != other._rawValue);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(this->_rawValue + other._rawValue);

	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(this->_rawValue - other._rawValue);
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits((this->_rawValue * other._rawValue) / 256);

	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits((this->_rawValue *256) / other._rawValue);

	return (result);
}

Fixed	&Fixed::operator++(void)
{
	this->_rawValue += 1;
	
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;

	this->_rawValue += 1;

	return (temp);
}

Fixed	&Fixed::operator--(void)
{
	this->_rawValue -= 1;
	
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;

	this->_rawValue -= 1;

	return (temp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}
