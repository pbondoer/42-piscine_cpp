/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 03:52:15 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/03 04:24:24 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	Form("robotomy request", 72, 45, target)
{}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &)
{}
RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
		RobotomyRequestForm const &
	)
{ return *this; }

void RobotomyRequestForm::_execute(Bureaucrat const &) const
{
	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized";
	else
		std::cout << this->getTarget() << " could not be robotomized";
}
