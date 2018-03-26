/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:29:24 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/26 19:05:01 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Database.hpp"

Database::Database(void) : _count(0) {}
Database::~Database(void) {}

int		Database::Count(void) const
{
	return this->_count;
}

Contact	Database::GetContact(int i) const
{
	return this->_contacts[i];
}

void	Database::AddContact(Contact c)
{
	if (this->_count >= 8)
		return ;

	this->_contacts[this->_count++] = c;
}

void	displayField(std::string field)
{
	if (field.size() > 10)
		std::cout << std::setw(9) << std::setfill('.') << field;
	else
		std::cout << std::setw(10) << std::right << std::setfill(' ') << field;

	std::cout << '|';
}

void	Database::List(void) const
{
	displayField("Index");
	displayField("First name");
	displayField("Last name");
	displayField("Nickname");
	std::cout << std::endl;

	// separator line
	std::cout << std::setw(44) << std::setfill('-') << '-';
	std::cout << std::endl;

	for (int i = 0; i < this->_count; i++)
	{
		Contact c = this->_contacts[i];

		displayField(std::to_string(i));
		displayField(c.GetField(0));
		displayField(c.GetField(1));
		displayField(c.GetField(2));
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
