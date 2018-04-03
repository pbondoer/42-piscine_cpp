/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 00:49:14 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/03 07:48:04 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"

int main(void)
{
	CentralBureaucracy c;

	for (int i = 0; i < 20; i++)
	{
		c.hire(new Bureaucrat("Bob", 1));
	}
	for (int i = 0; i < 20; i++)
	{
		c.queueUp("Peter");
	}
	c.doBureaucracy();
}
