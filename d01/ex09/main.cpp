/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 23:46:41 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/28 00:04:02 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int main(void)
{
	Logger logger("log.txt");

	logger.log("console", "Program starting");
	logger.log("file", "Program starting (file)");
	logger.log("console", "nice");
}
