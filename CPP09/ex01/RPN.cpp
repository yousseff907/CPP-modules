/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 23:57:10 by yitani            #+#    #+#             */
/*   Updated: 2026/01/01 09:55:52 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) : stack(other.stack) {}

RPN	&RPN::operator=(const RPN &other)
{
	if (this != &other)
		stack = other.stack;
	return *this;
}

bool	RPN::isNumber(const std::string &token)
{
	return (token.length() == 1 && token[0] >= '0' && token[0] <= '9');
}

bool	RPN::isOperator(const std::string &token)
{
	return (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'));
}

int		RPN::performOperation(int a, int b, std::string op)
{
	if (op == "+")
		return (a + b);
	if (op == "-")
		return (a - b);
	if (op == "*")
		return (a * b);
	else
	{
		if (b == 0)
		{
			std::cerr << "Error" << std::endl;
			exit(1);
		}
		return (a / b);
	}
}

int		RPN::calculate(const std::string &expression)
{
	std::istringstream	iss(expression);
	std::string			token;

	while (iss >> token)
	{
		if (!isNumber(token) && !isOperator(token))
		{
			std::cerr << "Error" << std::endl;
			exit(1);
		}
		if (isNumber(token))
			stack.push(std::atoi(token.c_str()));
		if (isOperator(token))
		{
			if (stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				exit(1);
			}
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			int res = performOperation(a, b, token);
			stack.push(res);
		}
	}
	if (stack.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		exit(1);
	}
	return (stack.top());
}
