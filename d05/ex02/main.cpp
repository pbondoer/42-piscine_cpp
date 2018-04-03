/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 00:49:14 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/03 04:28:42 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	{
		std::cout << "========== BUREAUCRAT ==========" << std::endl;
		std::cout << " * Creation" << std::endl;
		Bureaucrat b("Bob", 42);
		std::cout << b << std::endl;

		std::cout << " * Set grade" << std::endl;
		b.setGrade(100);
		std::cout << b << std::endl;

		std::cout << " * Too low grade" << std::endl;
		try {
			Bureaucrat bLow("Alice", 420);
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << e.what() << ": " << e.getGrade() << std::endl;
		}

		std::cout << " * Too high" << std::endl;
		try { Bureaucrat bHigh("Peter", 0);
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << e.what() << ": " << e.getGrade() << std::endl;
		}

		std::cout << " * Increment" << std::endl;
		try {
			while (true)
			{
				b.incrementGrade();
				std::cout << b.getGrade() << ", ";
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << b << std::endl;

		std::cout << " * Decrement" << std::endl;
		try {
			while (true)
			{
				b.decrementGrade();
				std::cout << b.getGrade() << ", ";
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << b << std::endl;
	}

	Bureaucrat high("high", 1);
	Bureaucrat low("low", 150);

	std::cout << "=============== SHRUBBERY ===============" << std::endl;
	{
		ShrubberyCreationForm f("lolol");

		// not signed
		low.executeForm(f);

		// sign it
		low.signForm(f);
		high.signForm(f);

		// not signed
		low.executeForm(f);
		high.executeForm(f);
	}

	std::cout << "=============== ROBOTOMY ===============" << std::endl;
	{
		RobotomyRequestForm f("lolol");

		// not signed
		low.executeForm(f);

		// sign it
		low.signForm(f);
		high.signForm(f);

		// not signed
		low.executeForm(f);
		high.executeForm(f);
	}

	std::cout << "=============== PARDON ===============" << std::endl;
	{
		PresidentialPardonForm f("lolol");

		// not signed
		low.executeForm(f);

		// sign it
		low.signForm(f);
		high.signForm(f);

		// not signed
		low.executeForm(f);
		high.executeForm(f);
	}
}
