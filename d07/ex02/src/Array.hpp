/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 07:08:43 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/04 21:12:32 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
class Array {
	public:
		Array(void) : _array(NULL), _n(0) {}
		Array(unsigned int n) : _array(new T[n]()), _n(n) {}

		~Array(void)
		{
			if (this->_array != NULL)
				delete [] this->_array;
		}

		Array(Array const &obj) : _array(NULL), _n(0)
		{
			*this = obj;
		}

		Array const &operator=(Array const &rhs)
		{
			if (&rhs == this)
				return *this;

			if (this->size() != rhs.size())
			{
				if (this->_array != NULL)
					delete [] this->_array;
				this->_array = new T[rhs.size()];
			}

			this->_n = rhs.size();
			for (size_t i = 0; i < rhs.size(); i++)
				this->_array[i] = rhs._array[i];

			return *this;
		}

		T &operator[](size_t i) const
		{
			if (!this->_array || i < 0 || i >= this->_n)
				throw std::exception();

			return this->_array[i];
		}

		unsigned int size(void) const
		{
			return this->_n;
		}

	private:
		T *_array;
		unsigned int _n;
};
