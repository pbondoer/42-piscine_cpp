/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:52:16 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/30 15:40:23 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_CLASS_H
# define FRAGTRAP_CLASS_H

# include <string>

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(const std::string name);
		FragTrap(const FragTrap &obj);
		~FragTrap(void);

		FragTrap &	operator=(const FragTrap &rhs);

		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);

		void			vaulthunter_dot_exe(std::string const & target);

	private:
		static std::string _vaulthunterQuotes[25];
};

#endif // FRAGTRAP_CLASS_H
