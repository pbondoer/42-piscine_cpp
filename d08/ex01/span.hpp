/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 00:24:55 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/06 01:02:27 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_HPP
# define SPAN_CLASS_HPP

# include <vector>

class Span
{
	public:
		Span(unsigned int n);
		Span(Span const &obj);
		~Span(void);

		Span const &operator=(Span const &obj);

		void addNumber(int x);
		void addVector(std::vector<int> &v);

		long shortestSpan(void);
		long longestSpan(void);
	private:
		unsigned int _n;
		std::vector<int> _v;
};

#endif // SPAN_CLASS_HPP
