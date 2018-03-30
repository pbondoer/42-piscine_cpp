/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:52:16 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/30 15:38:36 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_CLASS_H
# define SCAVTRAP_CLASS_H

# include <string>

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &obj);
		~ScavTrap(void);

		ScavTrap &	operator=(const ScavTrap &rhs);

		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);

		void			challengeNewcomer(std::string const & target);

	private:
		static std::string _challenges[5];
};

#endif // SCAVTRAP_CLASS_H
