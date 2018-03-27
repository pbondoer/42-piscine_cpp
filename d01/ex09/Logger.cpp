/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 23:46:35 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/28 00:21:35 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>
#include <iomanip>

#include "Logger.hpp"

Logger::Logger(std::string filename) : _filename(filename) {}
Logger::~Logger(void) {}

void Logger::logToFile(std::string const &message)
{
	std::ofstream of(this->_filename);

	of << makeLogEntry(message);
}

void Logger::logToConsole(std::string const &message)
{
	std::cout << makeLogEntry(message);
}

std::string Logger::makeLogEntry(std::string const &message) const
{
	std::stringstream ss;
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);

	ss << "["
		<< std::setw(2) << std::right << std::setfill('0')
		<< timePtr->tm_mday << "/"
		<< std::setw(2) << std::right << std::setfill('0')
		<< timePtr->tm_mon + 1 << "/"
		<< std::setw(2) << std::right << std::setfill('0')
		<< timePtr->tm_year + 1900 << " "
		<< std::setw(2) << std::right << std::setfill('0')
		<< timePtr->tm_hour << ":"
		<< std::setw(2) << std::right << std::setfill('0')
		<< timePtr->tm_min
		<< "] " << message << std::endl;

	return ss.str();
}

typedef void(Logger::* logAction) (std::string const &);

void Logger::log(std::string const &dest, std::string const &message)
{
	std::string names[2] = {
		"file", "console"
	};

	logAction actions[2] = {
		&Logger::logToFile, &Logger::logToConsole
	};

	for (int i = 0; i < 2; i++)
	{
		if (names[i].compare(dest) == 0)
			(this->*actions[i])(message);
	}
}
