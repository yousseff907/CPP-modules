/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:25:46 by yitani            #+#    #+#             */
/*   Updated: 2025/09/02 23:56:39 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high (minimum grade is 1)");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low (maximum grade is 150)");
}

Form::Form(void)
	: name("EmptyForm"),
	  isSigned(false),
	  gradeToSign(150),
	  gradeToExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name),
	  isSigned(false),
	  gradeToSign(gradeToSign),
	  gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();

	std::cout << "Form: " << name << " constructor called" << std::endl;
}

Form::Form(const Form &other)
	: name(other.name),
	  isSigned(other.isSigned),
	  gradeToSign(other.gradeToSign),
	  gradeToExecute(other.gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		isSigned = other.isSigned;
	std::cout << "Form copy assignment operator called" << std::endl;

	return (*this);
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

const std::string	&Form::getName(void) const
{
	return (name);
}

bool	Form::getSigned() const
{
	return (isSigned);
}

int	Form::getGradeToSign() const
{
	return (gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (gradeToExecute);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream	&operator<<(std::ostream &os, const Form &form)
{
	os << "Form " << form.getName()
	   << ", signed: " << (form.getSigned() ? "yes" : "no")
	   << ", sign grade: " << form.getGradeToSign()
	   << ", execute grade: " << form.getGradeToExecute();

	return (os);
}
