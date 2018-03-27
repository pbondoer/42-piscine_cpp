/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 23:11:46 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/27 23:12:26 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_CLASS_H
# define HUMAN_CLASS_H

# include <string>

class Human
{
	private:
		void meleeAttack(std::string const &target);
		void rangedAttack(std::string const &target);
		void intimidatingShout(std::string const &target);
	public:
		void action(std::string const &action_name, std::string const &target);
};

#endif // HUMAN_CLASS_H
