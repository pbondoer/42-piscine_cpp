/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:52:16 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/30 17:31:53 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_CLASS_H
# define NINJATRAP_CLASS_H

# include <string>

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
	public:
		NinjaTrap(const std::string name);
		NinjaTrap(const NinjaTrap &obj);
		~NinjaTrap(void);

		NinjaTrap &	operator=(const NinjaTrap &rhs);

		void			rangedAttack(std::string const & target);
		void			meleeAttack(std::string const & target);

		void			ninjaShoebox(NinjaTrap & target);
		void			ninjaShoebox(ClapTrap & target);
		void			ninjaShoebox(FragTrap & target);
		void			ninjaShoebox(ScavTrap & target);

	private:
		static std::string _vaulthunterQuotes[25];
};

#endif // NINJATRAP_CLASS_H
