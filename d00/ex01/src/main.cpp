/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:29:03 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/26 19:32:46 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>

#include "Database.hpp"

int		main(void)
{
	Database db;

	std::cout << "Welcome to Phonebook shell." << std::endl;

	std::string command = "";
	while (command.compare("EXIT") != 0)
	{
		// prompt for a command
		std::cout << "phonebook> ";
		std::getline(std::cin, command);

		if (!std::cin.good())
			exit(0);

		// is this a valid command?
		if (command.compare("ADD") == 0)
		{
			// if there are too many contacts, unable to add
			if (db.Count() >= 8)
			{
				std::cout << "Error: cannot add more than 8 contacts."
					<< std::endl;
				continue;
			}

			// otherwise, prompt for a new contact
			Contact c;

			c.Prompt();
			db.AddContact(c);
		}
		else if (command.compare("SEARCH") == 0)
		{
			std::cout << "Contacts: " << db.Count() << std::endl;
			db.List();

			if (db.Count() == 0)
				continue;

			// prompt for an index
			std::string input;
			int index = -1;
			while (true) {
				std::cout << "Enter an index to view: ";
				std::getline(std::cin, input);

				if (!std::cin.good())
					exit(0);

				std::stringstream convert(input);
				if (convert >> index && index >= 0 && index < db.Count())
					break;

				std::cout << "Error: invalid index. Must be between 0 and "
					<< (db.Count() - 1) << "." << std::endl;
			}

			std::cout << std::endl;
			db.GetContact(index).Display();
		}
	}

	return (0);
}
