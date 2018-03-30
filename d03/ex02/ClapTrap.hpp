/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:52:16 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/30 15:34:26 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CLASS_H
# define CLAPTRAP_CLASS_H

# include <string>

class ClapTrap
{
	public:
		ClapTrap(const std::string name, unsigned int health,
		unsigned int maxHealth, unsigned int energy, unsigned int maxEnergy,
		unsigned int level, unsigned int meleeDmg, unsigned int rangedDmg,
		unsigned int armor);
		ClapTrap(const ClapTrap &obj);
		~ClapTrap(void);

		ClapTrap &	operator=(const ClapTrap &rhs);

		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

	protected:
		std::string		_name;
		unsigned int	_health;
		unsigned int	_maxHealth;
		unsigned int	_energy;
		unsigned int	_maxEnergy;
		unsigned int	_level;
		unsigned int	_meleeDmg;
		unsigned int	_rangedDmg;
		unsigned int	_armor;
};

#endif // CLAPTRAP_CLASS_H
