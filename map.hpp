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
    private:
        RBT<T>*    _rbt;
        size_t  _size;
        size_t  _capacity;
        Alloc   _myAllocator;

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
        map()
        {
        }
        ~map(){}
        map(const map& src);
        map &operator=(map const &rhs)
        {
            return (*this);
        }
        int   &operator[](const key_type& key)
        {
            pair<const Key,T> to_find = *make_pair(key, 0);
            // key_type def_value = allocate();
			// RBT<T>* node = _rbt->search(to_find);
            // if (!node)
            // {
            //     _size++;
            //      _rbt->insert(to_find);
            //     mapped_type value = to_find->second;
            // }
            // else
            //     mapped_type value = node->value->second;
            // // return (value);
            // // if (!to_find)
            // // {
            // //     _size++;
            // //     _rbt->insert(make_pair(key, def_value));
            // //     return (def_value);
            // // }
            key_type *a= new int();
            return *a;
        }

        //----> Capacity :
		size_type max_size() const {return _myAllocator.max_size();}
		size_type size() const{return _size;}
		size_type capacity() const {return _capacity;}
		bool empty() const {return (size() == 0);}

        // friend std::ostream& operator<<(std::ostream& is, pair<A, B>& obj);
};