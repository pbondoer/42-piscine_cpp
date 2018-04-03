/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 00:49:14 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/03 06:55:25 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main(void)
{
	Intern idiotOne;
	Bureaucrat high = Bureaucrat("Hermes Conrad", 1);
	Bureaucrat low = Bureaucrat("Bobby Bobson", 150);

	OfficeBlock ob;

	// no intern
	try {
		ob.doBureaucracy("robotomy request", "something");
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// no signer
	ob.setIntern(&idiotOne);
	try {
		ob.doBureaucracy("robotomy request", "something");
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// no exec
	ob.setSigner(&low);
	try {
		ob.doBureaucracy("robotomy request", "something");
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// low rank
	ob.setExecutor(&low);
	try {
		ob.doBureaucracy("robotomy request", "something");
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// low rank exec
	ob.setSigner(&high);
	try {
		ob.doBureaucracy("robotomy request", "something");
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// try to do invalid stuff
	try {
		ob.doBureaucracy("lolol", "something");
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
	try {
		ob.setExecutor(NULL);
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
	try {
		ob.setSigner(NULL);
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
	try {
		ob.setIntern(NULL);
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

	// should be ok
	ob.setExecutor(&high);
	try {
		ob.doBureaucracy("robotomy request", "something");
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
	
}
