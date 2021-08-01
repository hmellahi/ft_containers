#pragma once
#include <memory>
#include <iostream>
#include "RBT.hpp"
#include "pair.hpp"
// class pair;
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
        //    class Compare = less<Key>,                     // map::key_compare // todo :3
           class Alloc    // map::allocator_type
            >
class ft::map
{
    public:
        typedef     map 										self_type;
        typedef     Key 										key_type;
        typedef     T											mapped_type;
        typedef     pair< key_type,mapped_type>                 value_type;
        typedef		Alloc										allocator_type;
		typedef		typename allocator_type::reference			reference;
		typedef		typename allocator_type::const_reference	const_reference;
		typedef		typename allocator_type::pointer			pointer;
		typedef		typename allocator_type::const_pointer		const_pointer;
		typedef		int                                         difference_type;
		typedef		size_t                                      size_type;
        map()
        {
            // _myAllocator.allocate(_rbt, 1);
        }
        
        ~map(){}

        map(const map& src);

        map &operator=(map const &rhs)
        {
            return (*this);
        }

        mapped_type   &operator[](const key_type& key)
        {
            value_type to_find = make_pair(key, mapped_type());
            // key_type def_value = allocate();
			RBT<value_type>* node = _rbt.search(to_find);
            if (!node)
            {
                _size++;
                _rbt.insert(to_find);
                node = _rbt.search(to_find);
            }
            return node->value.second;
        }

        //----> Capacity :
		size_type max_size() const {return _myAllocator.max_size();}
		size_type size() const{return _size;}
		bool empty() const {return (size() == 0);} 
        
        // --> allocator getter
        allocator_type get_allocator() const;
        // friend std::ostream& operator<<(std::ostream& is, pair<A, B>& obj);
        
        // todo:::
        // iterator begin();
        // const_iterator begin() const;
        // iterator end();
        // const_iterator end() const;
        // reverse_iterator rbegin();
        // const_iterator rbegin() const;
        // reverse_iterator rend();
        // const_iterator rend() const;
    
     private:
        RBT<value_type>    _rbt;
        size_t  _size;
        size_t  _capacity;
        Alloc   _myAllocator;

};