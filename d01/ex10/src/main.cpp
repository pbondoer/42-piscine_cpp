/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:44:20 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/28 00:56:40 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <istream>

void	pipe_stream(std::istream &input)
{
	std::cout << input.rdbuf();
}

int		main(int argc, char **argv)
{
	// Handle special cases
	// cat
	// cat --
	if (argc == 1 || (argc == 2 && std::string(argv[1]).compare("--") == 0))
	{
		pipe_stream(std::cin);
		return (0);
	}

	for (int i = 1; i < argc; i++)
	{
		std::string argument = argv[i];

		// We can hack around the -- by doing this
		// Normally we would have proper options handling
		if (i == 1 && argument.compare("--") == 0)
			continue;

		if (argument.compare("-") == 0)
		{
			pipe_stream(std::cin);
		}
		else
		{
			std::ifstream fs(argument);

			if (fs.good())
				pipe_stream(fs);
			else
				std::cerr << argv[0] << ": " << argument << ": "
					<< strerror(errno) << std::endl;
		}
	}

	return (0);
}
