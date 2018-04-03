/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 03:52:15 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/03 04:24:08 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
	Form("presidential pardon", 25, 5, target)
{}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &)
{}
PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
		PresidentialPardonForm const &
	)
{ return *this; }

void PresidentialPardonForm::_execute(Bureaucrat const &) const
{
	std::cout << this->getTarget() << " has been pardonned by Zaphod Beeblebrox";
}
