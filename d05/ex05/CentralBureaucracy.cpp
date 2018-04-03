/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 00:12:42 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/03 07:47:46 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "CentralBureaucracy.hpp"
#include "OfficeBlock.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

CentralBureaucracy::CentralBureaucracy(void)
{
	for (int i = 0; i < 20; i++)
		this->_blocks[i] = OfficeBlock();

	for (int i = 0; i < 50; i++)
		this->_queue[i] = "";
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy&)
{}

CentralBureaucracy::~CentralBureaucracy(void)
{}

void CentralBureaucracy::hire(Bureaucrat *b)
{
	for (int i = 0; i < 20; i++)
	{
		OfficeBlock &o = this->_blocks[i];

		if (o.getIntern() == NULL)
			o.setIntern(new Intern());

		if (o.getSigner() == NULL)
		{
			o.setSigner(b);
			return;
		}

		if (o.getExecutor() == NULL)
		{
			o.setExecutor(b);
			return;
		}
	}

	std::cout << "Sorry, you are rejected" << std::endl;
}

void CentralBureaucracy::queueUp(std::string target)
{
	for (int i = 0; i < 50; i++)
	{
		if (this->_queue[i].compare("") == 0)
		{
			this->_queue[i] = target;
			return;
		}
	}

	std::cout << "Sorry, the queue is full" << std::endl;
}

void CentralBureaucracy::doBureaucracy(void)
{
	std::string types[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	int office = 0;

	for (int i = 0; i < 50; i++)
	{
		if (this->_queue[i].compare("") == 0)
			return;

		try {
			this->_blocks[office].doBureaucracy(types[std::rand() % 3], this->_queue[i]);
		}
		catch (std::exception &e)
		{
			std::cout << "Failed to do bureaucracy: " << e.what() << std::endl;
		}

		this->_queue[i] = "";

		office++;

		if (office >= 20 ||
				this->_blocks[office].getIntern() == NULL ||
				this->_blocks[office].getSigner() == NULL ||
				this->_blocks[office].getExecutor() == NULL)
			office = 0;
	}
}
