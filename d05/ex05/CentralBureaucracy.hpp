/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 07:11:33 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/03 07:43:11 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRALBUREAUCRACY_CLASS_H
# define CENTRALBUREAUCRACY_CLASS_H

# include "Bureaucrat.hpp"
# include "OfficeBlock.hpp"

class CentralBureaucracy
{
	public:
		CentralBureaucracy(void);
		CentralBureaucracy(CentralBureaucracy& rhs);
		~CentralBureaucracy(void);

		CentralBureaucracy& operator=(CentralBureaucracy& rhs);

		void hire(Bureaucrat *b);
		void queueUp(std::string target);
		void doBureaucracy(void);
	private:
		OfficeBlock _blocks[20];
		std::string _queue[50];
};

#endif // CENTRALBUREAUCRACY_CLASS_H
