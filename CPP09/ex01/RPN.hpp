/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 23:56:16 by yitani            #+#    #+#             */
/*   Updated: 2026/01/22 22:23:19 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <cstdlib>

class RPN
{
	private:
		std::stack<int>	stack;

		bool	isNumber(const std::string &token);
		bool	isOperator(const std::string &token);
		int		performOperation(int a, int b, std::string op);

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		int		calculate(const std::string &expression);
};

#endif