/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:58:46 by yitani            #+#    #+#             */
/*   Updated: 2025/09/08 18:46:44 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm *Intern::createShrubberyCreationForm(const std::string &target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) const
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) const
{
	return (new PresidentialPardonForm(target));
}

Intern::Intern(void)
{
	formCreators[0] = &Intern::createShrubberyCreationForm;
	formCreators[1] = &Intern::createRobotomyRequestForm;
	formCreators[2] = &Intern::createPresidentialPardonForm;

	formNames[0] = "shrubbery creation";
	formNames[1] = "robotomy request";
	formNames[2] = "presidential pardon";

	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	for (int i = 0; i < 3; i++)
	{
		formCreators[i] = other.formCreators[i];
		formNames[i] = other.formNames[i];
	}

	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 3; i++)
		{
			formCreators[i] = other.formCreators[i];
			formNames[i] = other.formNames[i];
		}
	}

	std::cout << "Intern copy assignment operator called" << std::endl;

	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm*	Intern::makeForm(const std::string &formName, const std::string &target)
{
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*formCreators[i])(target));
		}
	}
	
	std::cerr << "Form not found" << std::endl;

	return (NULL);
}
