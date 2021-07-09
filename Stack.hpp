#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <string>

template <typename T, class Container = std::vector<T>>

class Stack
{
	public:

		typedef Container container_type;
		
		Stack();
		Stack( Stack const & src );
		~Stack();
		Stack &		operator=( Stack const & rhs );

		bool	empty();
		size_t	size();


	protected:
		Container c;

};

std::ostream &			operator<<( std::ostream & o, Stack const & i );

#endif /* *********************************************************** STACK_H */

bool Stack::empty(){return c.empty();}

bool Stack::size(){return c.size();}


top
