/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:44:20 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 23:02:07 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv)
{
	// Do we have enough arguments?
	if (argc < 4)
	{
		std::cout << "Usage: ./replace [filename] [s1] [s2]" << std::endl;
		return (1);
	}

	// Get our parameters
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	// Is the filename valid?
	std::ifstream fs(filename);

	if (!fs.good())
	{
		std::cout << "Error: could not open file " << filename << std::endl;
		return (1);
	}

	// Are the first string non-empty?
	if (s1.empty())
	{
		std::cout << "Error: s1 must be non-empty" << std::endl;
		return (1);
	}

	// Read our file in the buffer
	std::stringstream buffer;
	std::string contents;
	buffer << fs.rdbuf();
	contents = buffer.str();

	// Replace everything
	size_t match;
	while ((match = contents.find(s1)) != std::string::npos)
	{
		contents.replace(match, s1.length(), s2);
	}

	// Write it to a file
	std::ofstream of(filename + ".replace");

	if (!of.good())
	{
		std::cout << "Error: could not open file " << filename
			<< ".replace" <<  std::endl;
		return (1);
	}

	of << contents;

	// Close the stream, and exit
	of.close();
	return (0);
}
