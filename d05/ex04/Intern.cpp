/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 04:46:51 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/03 04:56:47 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {}
Intern::Intern(Intern const &) {}
Intern::~Intern(void) {}

Intern& Intern::operator=(Intern const &) { return *this; }

Form *makeShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}
Form *makeRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}
Form *makePardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

Form *Intern::makeForm(std::string type, std::string target)
{
	static struct FormType types[3] = {
		{ "shrubbery creation", makeShrubbery },
		{ "robotomy request", makeRobotomy },
		{ "presidential pardon", makePardon }
	};

	for (int i = 0; i < 3; i++)
	{
		if (types[i].type == type)
		{
			std::cout << "Intern creates " << type << std::endl;
			return types[i].make(target);
		}
	}

	std::cout << "Unknown form type: " << type << std::endl;
	return NULL;
}
