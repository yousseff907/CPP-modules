/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:25:46 by yitani            #+#    #+#             */
/*   Updated: 2025/09/04 16:04:43 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high (minimum grade is 1)");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low (maximum grade is 150)");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

AForm::AForm(void)
	: name("EmptyForm"),
	  isSigned(false),
	  gradeToSign(150),
	  gradeToExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
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

AForm::AForm(const AForm &other)
	: name(other.name),
	  isSigned(other.isSigned),
	  gradeToSign(other.gradeToSign),
	  gradeToExecute(other.gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		isSigned = other.isSigned;
	std::cout << "Form copy assignment operator called" << std::endl;

	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "Form destructor called" << std::endl;
}

const std::string	&AForm::getName(void) const
{
	return (name);
}

bool	AForm::getSigned() const
{
	return (isSigned);
}

int	AForm::getGradeToSign() const
{
	return (gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (gradeToExecute);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream	&operator<<(std::ostream &os, const AForm &form)
{
	os << "Form " << form.getName()
	   << ", signed: " << (form.getSigned() ? "yes" : "no")
	   << ", sign grade: " << form.getGradeToSign()
	   << ", execute grade: " << form.getGradeToExecute();

	return (os);
}
