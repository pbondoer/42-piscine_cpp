/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:52:16 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/29 23:49:20 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_CLASS_H
# define SCAVTRAP_CLASS_H

# include <string>

class ScavTrap
{
	public:
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &obj);
		~ScavTrap(void);

		ScavTrap &	operator=(const ScavTrap &rhs);

		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		void			challengeNewcomer(std::string const & target);

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

		static std::string _challenges[5];
};

#endif // SCAVTRAP_CLASS_H
