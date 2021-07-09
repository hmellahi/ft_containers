/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmellahi <hmellahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 21:28:08 by hmellahi          #+#    #+#             */
/*   Updated: 2021/07/09 21:51:14 by hmellahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"

int main()
{
    ft::stack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	// for (ft::stack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	// 	std::cout << *it;
}