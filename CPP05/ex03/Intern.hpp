/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 00:00:00 by yitani            #+#    #+#             */
/*   Updated: 2025/09/07 01:12:12 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm* (Intern::*formCreators[3])(const std::string& target) const;
        
        std::string formNames[3];

		AForm*	createShrubberyCreationForm(const std::string& target) const;
		AForm*	createRobotomyRequestForm(const std::string& target) const;
		AForm*	createPresidentialPardonForm(const std::string& target) const;

	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm*	makeForm(const std::string& formName, const std::string& target);

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif