/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:25:46 by yitani            #+#    #+#             */
/*   Updated: 2025/09/02 11:49:45 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char*	Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high (minimum grade is 1)");
}

const char*	Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low (maximum grade is 150)");
}

Form::Form(void)
:	name("EmptyForm"),
	isSigned(false),
	gradeToSign(150),
	gradeToExecute(150)
{std::cout << "Form default constructor called" << std::endl;}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
:	name(name),
	gradeToExecute(gradeToExecute),
	gradeToSign(gradeToSign),
	isSigned(false)
{
	if (gradeToExecute < 1 || gradeToSign < 1)
        throw GradeTooHighException();
    if (gradeToExecute > 150 || gradeToSign > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
:	gradeToExecute(other.gradeToExecute),
	gradeToSign(other.gradeToSign),
	name(other.name),
	isSigned(other.isSigned)
{
}