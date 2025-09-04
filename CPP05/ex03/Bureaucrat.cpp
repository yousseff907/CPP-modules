/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:45:17 by yitani            #+#    #+#             */
/*   Updated: 2025/09/04 16:06:53 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high (minimum grade is 1)");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low (maximum grade is 150)");
}

Bureaucrat::Bureaucrat(void)	:	name("default"), grade(75)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)	:	name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
	{
		std::cout << "Bureaucrat :" << name << " constructor called" << std::endl;
		this->grade = grade;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)	:	name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->grade = other.grade;
	
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;

	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string&	Bureaucrat::getName(void) const
{
	return (name);
}

int	Bureaucrat::getGrade(void) const
{
	return (grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";

	return (os);
}

void	Bureaucrat::signForm(AForm &Aform)
{
	try
	{
		Aform.beSigned(*this);
		std::cout << name << " signed " << Aform.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << name << " couldn't sign " << Aform.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &Aform) const
{
	try
	{
		Aform.execute(*this);
		std::cout << name << " executed " << Aform.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << name << " couldn't execute " << Aform.getName() << " because " << e.what() << std::endl;
	}
}
