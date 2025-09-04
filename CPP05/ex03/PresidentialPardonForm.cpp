/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:53:37 by yitani            #+#    #+#             */
/*   Updated: 2025/09/04 16:13:42 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Pardon Form", 25, 5), target("default_target")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Presidential Pardon Form", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm constructor called for target: " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), target(other.target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

const std::string	&PresidentialPardonForm::getTarget() const
{
	return (target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
