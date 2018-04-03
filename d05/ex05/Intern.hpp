/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 23:51:12 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/03 04:56:34 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_H
# define INTERN_CLASS_H

# include <string>

# include "Form.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &obj);
		~Intern(void);

		Intern &operator=(Intern const &rhs);

		Form *makeForm(std::string type, std::string target);
};

struct FormType
{
	std::string type;
	Form *(*make)(std::string);
};

#endif
