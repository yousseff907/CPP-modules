/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:52:38 by yitani            #+#    #+#             */
/*   Updated: 2025/09/04 17:52:44 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

const char	*ShrubberyCreationForm::FileCreationException::what() const throw()
{
	return ("File creation failed");
}

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation Form", 145, 137), target("default_target")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation Form", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constructor called for target: " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
		throw(AForm::FormNotSignedException());

	if (executor.getGrade() > getGradeToExecute())
		throw(AForm::GradeTooLowException());

	std::ofstream file((target + "_shrubbery").c_str());
	if (!file.is_open())
		throw(FileCreationException());

	file << "                 .              .              ;%     ;;   " << std::endl;
	file << "                   ,           ,                :;%  %;   " << std::endl;
	file << "                    :         ;                   :;%;'     .,   " << std::endl;
	file << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
	file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
	file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
	file << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
	file << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
	file << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
	file << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
	file << "                      `@%:.  :;%.         ;@@%;'   " << std::endl;
	file << "                        `@%.  `;@%.      ;@@%;         " << std::endl;
	file << "                          `@%%. `@%%    ;@@%;        " << std::endl;
	file << "                            ;@%. :@%%  %@@%;       " << std::endl;
	file << "                              %@bd%%%bd%%:;     " << std::endl;
	file << "                                #@%%%%%:;;" << std::endl;
	file << "                                %@@%%%::;" << std::endl;
	file << "                                %@@@%(o);  . '         " << std::endl;
	file << "                                %@@@o%;:(.,'         " << std::endl;
	file << "                            `.. %@@@o%::;         " << std::endl;
	file << "                               `)@@@o%::;         " << std::endl;
	file << "                                %@@(o)::;        " << std::endl;
	file << "                               .%@@@@%::;         " << std::endl;
	file << "                               ;%@@@@%::;.          " << std::endl;
	file << "                              ;%@@@@%%:;;;. " << std::endl;
	file << "                          ...;%@@@@@%%:;;;;,..    Gilo97" << std::endl;

	file.close();
}
