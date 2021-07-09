#include "Stack.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Stack::Stack()
{
}

Stack::Stack( const Stack & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Stack::~Stack()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Stack &				Stack::operator=( Stack const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Stack const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */