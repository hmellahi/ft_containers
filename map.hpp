#pragma once
#include <memory>
#include <iostream>
#include "RBT.hpp"

namespace ft
{
    template < class Key,                                     // map::key_type
        class T,                                       // map::mapped_type
    //    class Compare = less<Key>,                     // map::key_compare
        class Alloc = std::allocator<pair<const Key,T> >    // map::allocator_type
        >
    class map;
}

template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
        //    class Compare = less<Key>,                     // map::key_compare
           class Alloc    // map::allocator_type
            > 
class ft::map
{
    private:
        RBT*    _rbt;
        size_t  _size;
        size_t  _capacity;

    public:
        typedef     map 										self_type;
        typedef     Key 										key_type;
        typedef     T											mapped_type;
        typedef     pair<const key_type,mapped_type>			value_type;
        typedef		Alloc										allocator_type;
		typedef		typename allocator_type::reference			reference;
		typedef		typename allocator_type::const_reference	const_reference;
		typedef		typename allocator_type::pointer			pointer;
		typedef		typename allocator_type::const_pointer		const_pointer;
		typedef		int                                         difference_type;
		typedef		size_t                                      size_type;
// key_type	The first template parameter (Key)	
// mapped_type	The second template parameter (T)	
// value_type	pair<const key_type,mapped_type>	
// key_compare	The third template parameter (Compare)	defaults to: less<key_type>
// value_compare	Nested function class to compare elements	see value_comp
// allocator_type	The fourth template parameter (Alloc)	defaults to: allocator<value_type>
// reference	allocator_type::reference	for the default allocator: value_type&
// const_reference	allocator_type::const_reference	for the default allocator: const value_type&
// pointer	allocator_type::pointer	for the default allocator: value_type*
// const_pointer	allocator_type::const_pointer	for the default allocator: const value_type*
// iterator	a bidirectional iterator to value_type	convertible to const_iterator
// const_iterator	a bidirectional iterator to const value_type	
// reverse_iterator	reverse_iterator<iterator>	
// const_reverse_iterator	reverse_iterator<const_iterator>	
// difference_type	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
// size_type
        map()
        {
        }
        ~map(){}
        map(const map& src);
        map &operator=(map const &rhs)
        {
            return (*this);
        }
        mapped_type   operator[](const key_type& key)
        {
            RBT* to_find = new RBT(pair<key, 0>);
			mapped_type value = _rbt.find(to_find);
            if (!value)
            ;

        }
        // friend std::ostream& operator<<(std::ostream& is, pair<A, B>& obj);
};