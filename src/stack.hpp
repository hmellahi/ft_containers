/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmellahi <hmellahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 21:12:58 by hmellahi          #+#    #+#             */
/*   Updated: 2021/07/27 13:42:50 by hmellahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "vector.hpp"

template <typename T, class Container>
class ft::stack
{
public:
	typedef Container container_type;
	typedef T value_type;
	typedef size_t size_type;

	explicit stack (const Container& ctnr = container_type())
	{
		this->c = ctnr;
	}
	// stack(stack const &src) { *this = src; }
	// ~stack(){};
	// stack &operator=(stack const &rhs)
	// {
	// 	this->c = rhs.c;
	// 	return (*this);
	// }

	bool empty() const { return c.empty(); };
	size_t size() const { return c.size(); };
	value_type &top() { return c.back(); };
	const value_type &top() const { return c.back(); };
	void pop() { c.pop_back(); };
	void push(T element) { c.push_back(element); };
	friend bool operator==(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs.c == rhs.c);
	}

	friend bool operator>=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs.c >= rhs.c);
	}

	friend bool operator<=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs.c <= rhs.c);
	}

	friend bool operator<(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs.c < rhs.c);
	}

	friend bool operator>(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs.c > rhs.c);
	}

	friend bool operator!=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
		return (lhs.c != rhs.c);
	}

protected:
	Container c;
};