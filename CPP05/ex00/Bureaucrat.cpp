/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:45:17 by yitani            #+#    #+#             */
/*   Updated: 2025/09/01 22:43:30 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(void)	:	name("default"), grade(75)
{
	std::cout << "Bureacrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)	:	name(name), grade(grade)
{
	std::cout << "Bureacrat :" << name << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat& other)
{
}

Bureaucrat::~Bureaucrat(void)
{
}
