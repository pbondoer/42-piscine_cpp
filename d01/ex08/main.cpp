/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 23:12:53 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 23:35:55 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main(void)
{
	Human h;

	std::string target = "David the Cave Spider";

	h.action("melee", target);
	h.action("ranged", target);
	h.action("shout", target);
}
