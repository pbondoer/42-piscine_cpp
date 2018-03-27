/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 19:22:28 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 19:27:16 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int		main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *brainPtr = &brain;
	std::string &brainRef = brain;

	std::cout << *brainPtr << std::endl;
	std::cout << brainRef << std::endl;
}
