/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmellahi <hmellahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 21:12:58 by hmellahi          #+#    #+#             */
/*   Updated: 2021/07/09 21:54:36 by hmellahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "header.hpp"
#include <vector>

template <typename T, class Container >
class ft::stack
{
	public:

		typedef Container container_type;
		// typedef typename ft::stack<T>::container_type::iterator iterator;
		
		stack(){};
		// stack( stack const & src );
		// ~stack();
		// stack &		operator=( stack const & rhs );

		bool	empty(){return c.empty();};
		size_t	size(){return c.size();};
		T		top(){return c.back();};
		void	pop(){c.pop_back();};
		void		push(T element){c.push_back(element);};

	protected:
		Container c;

};

// std::ostream &			operator<<( std::ostream & o, stack const & i );

// bool	ft::stack::empty(){return c.empty();}

// size_t	ft::stack::size(){return c.size();}

// T		ft::stack::top(){return c.back();}

// T		ft::stack::push(T element){return c.push_back(element);}

// void	ft::stack::pop(T element){c.pop_back(element);}
