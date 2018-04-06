/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Container.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 04:10:09 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 04:39:18 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINER_H
# define CONTAINER_H

class Container
{
	public:
		Container(void);
		Container(Container const &obj);
		~Container(void);


		Container const &operator=(Container const &obj);

		// gets a pointer to the current cell
		char *get(void);

		// brainfuck instructions:
		// + - > < [ ] . ,

		// [ ] are loops, and implemented recursively with Instructions

		void add(void); // +
		void sub(void); // -

		void addPos(void); // >
		void subPos(void); // <

		void display(void); // .
		void input(void); // ,
	private:
		static const int _size;
		char *_memory;
		int _position;
};

#endif // CONTAINER_H
