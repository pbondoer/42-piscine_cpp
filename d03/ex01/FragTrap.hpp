/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:52:16 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/29 23:18:35 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_CLASS_H
# define FRAGTRAP_CLASS_H

# include <string>

class FragTrap
{
	public:
		FragTrap(const std::string name);
		FragTrap(const FragTrap &obj);
		~FragTrap(void);

		FragTrap &	operator=(const FragTrap &rhs);

		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		void			vaulthunter_dot_exe(std::string const & target);

	private:
		std::string		_name;
		unsigned int	_health;
		unsigned int	_maxHealth;
		unsigned int	_energy;
		unsigned int	_maxEnergy;
		unsigned int	_level;
		unsigned int	_meleeDmg;
		unsigned int	_rangedDmg;
		unsigned int	_armor;

		static std::string _vaulthunterQuotes[25];
};

#endif // FRAGTRAP_CLASS_H
