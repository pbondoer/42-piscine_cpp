/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 20:52:16 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/30 17:29:32 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_CLASS_H
# define SUPERTRAP_CLASS_H

# include <string>

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public virtual FragTrap, public virtual NinjaTrap
{
	public:
		SuperTrap(const std::string name);
		SuperTrap(const SuperTrap &obj);
		~SuperTrap(void);

		SuperTrap &	operator=(const SuperTrap &rhs);
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
};

#endif // SUPERTRAP_CLASS_H
