/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 23:46:18 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/28 00:20:53 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_CLASS_H
# define LOGGER_CLASS_H

# include <string>

class Logger
{
	public:
		Logger(std::string filename);
		~Logger(void);

		void log(std::string const &dest, std::string const &message);
	private:
		void logToFile(std::string const &message);
		void logToConsole(std::string const &message);
		std::string makeLogEntry(std::string const &message) const;

		std::string _filename;
};

#endif // LOGGER_CLASS_H
