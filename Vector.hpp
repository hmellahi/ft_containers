/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmellahi <hmellahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:59:29 by hmellahi          #+#    #+#             */
/*   Updated: 2021/07/06 14:59:30 by hmellahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <memory>
#include "header.hpp"

template < class T, class Alloc = std::allocator<T> >
class vector
{
	public:
		~vector()
		{
			ft_destroy_arr();
			if (_max_capacity)
				myAllocator.deallocate(_arr, _max_capacity);
		};


		typedef		T											value_type;
		typedef		Alloc										allocator_type;
		typedef		typename allocator_type::reference			reference;
		typedef		typename allocator_type::const_reference	const_reference;
		typedef		typename allocator_type::pointer			pointer;
		typedef		typename allocator_type::const_pointer		const_pointer;
		typedef		int		difference_type;
		typedef		size_t	size_type;
		class iterator;
		class const_iterator;
		// -------> constructors
		// copy construct
		vector& operator= (const vector& src)
		{
			this->assign(src.begin(), src.end());
			return *this;
		}
		// empty container constructor (default constructor
		explicit vector (const allocator_type& alloc = allocator_type())
		{
			_index = 0;
			myAllocator = alloc;
			_max_capacity = 0;
			// _arr = NULL; useles??
		}
		// fill constructor with n elements.
		// range constructor
		template <class InputIterator,
		    class = typename std::enable_if<!std::is_integral<InputIterator>::value>::type>
        vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type())
		{
			myAllocator = alloc;
			_index = 0;
			_max_capacity = 0; // DRY
			ft_init_with_iters(first, last);
		}

		explicit vector (size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type())
		{
			_index = 0;
			myAllocator = alloc;
			_max_capacity = 0;
			ft_init_with_val(n, val);
		}
		// copy constructor
		vector( vector const & src)
		{
			_index = 0;
			_max_capacity = 0; 
			*this = src;
		}

		// member functions
		
		//----> Capacity :
		size_type max_size() const {return myAllocator.max_size();}
		size_type size() const{return _index;}
		size_type capacity() const {return _max_capacity;}
		bool empty(){return (size() == 0);}

		void resize (size_type n, value_type val = value_type())
		{
			//////////////////// ////////// ////////// ////////// ////////// 
            // if n is greater than the current container capacity
			////////////////////////////// ////////// ////////// ////////// 
			if (n > _max_capacity)
			{
				reserve(n);
				size_type i = _index - 1;
				while (++i < n)
					push_back(val);
			}
			//////////////////// ////////// ////////// ////////// ////////// 
            // if n is smaller than the current container size
			////////////////////////////// ////////// ////////// ////////// 
			else if (n < size())
			{
				size_type i = n;
				while (i < _index)
					myAllocator.destroy(_arr + i++);
				_index = n;
			}
			// //////////////////// ////////// ////////// ////////// ////////// 
            // // if n is greater than the current container size
			// ////////////////////////////// ////////// ////////// ////////// 
			else if ( n > size())
			{
				size_type i = _index - 1;
				while (++i < n)
					push_back(val);
			}
		}

		void reserve (size_type n)
		{
			if (n <= _max_capacity) return ;
			// allocate new array
			T	*new_arr;
			// try
			// {
				new_arr = myAllocator.allocate(n);
			// }
			// catch (std::bad_alloc& ba)
			// {
			// 	std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
			// 	exit(0);
			// }
			// copy
			size_type i = -1;
			while (++i < _index)
				new_arr[i] = _arr[i];
			// free old one
			if (_max_capacity)
				myAllocator.deallocate(_arr, _max_capacity);
			_arr = new_arr;
			_max_capacity = n;
		}

		reference operator[] (size_type n)
		{
			return (_arr[n]);
		}
		const_reference operator[] (size_type n) const
		{
			return (_arr[n]);
		}
		reference at(size_type n)
		{
			if (n >= _index) // todo throw exeption
				throw outOfBoundsIndex();
				// return (value_type());
			return (_arr[n]);
		}
		const_reference at(size_type n) const
		{
			if (n >= _index) // todo throw exeption
				throw outOfBoundsIndex();
			return (_arr[n]);
		}
		reference front()
		{
			return (_arr[0]);
		}
		const_reference front() const
		{
			return (_arr[0]);
		}

		reference back()
		{
			return (_arr[_index - 1]);
		}
		const_reference back() const
		{
			return (_arr[_index - 1]);
		}

		// --> MOdifiers
		void push_back(const value_type& val)
		{
			if (_max_capacity == 0)
				this->reserve(1);
			else if (_index >= _max_capacity)
				this->reserve(_max_capacity * 2);
			_arr[_index++] = val;
		}

		void pop_back()
		{// todo check
			myAllocator.destroy(_arr + --_index);
		}
 
		void swap (vector& src)
		{
			// vector *tmp = this;
			// this = &src;
			// src = tmp;
			// tmp.assign(this->begin(), this->end());

			// this->assign(src.begin(), src.end());
			
			// src = tmp; // check
			// src.assign(tmp.begin(), tmp.end());
			// delete tmp; wtf
		}

		void	clear()
		{
			ft_destroy_arr();
		}

		// iterator insert (iterator position, const value_type& val)
		// {

		// }
		
		// void insert (iterator position, size_type n, const value_type& val);
		// {

		// }

		// template <class InputIterator>
    	// void insert (iterator position, InputIterator first, InputIterator last)
		// {
			
		// }

		template <class InputIterator,
           class = typename std::enable_if<!std::is_integral<InputIterator>::value>::type>
		void assign (InputIterator first, InputIterator last)
		{
			ft_destroy_arr();
			ft_init_with_iters(first, last);
		}

		void assign (size_type n, const value_type& val)
		{
			ft_destroy_arr();
			ft_init_with_val(n, val);
		}
		iterator erase (iterator position)
		{
			difference_type pos = position - begin();
			myAllocator.destroy(_arr + pos);
			int elem_to_move = end() - position - 1;
			// std::cout << elem_to_move << std::endl;
			_index = pos;
			for (int i = 0; i < elem_to_move; i++)
				push_back(_arr[i + pos + 1]);
			return position;
		}
		iterator erase (iterator first, iterator last)
		{
			difference_type start_pos = first - begin();
			difference_type last_pos = last - begin();
			for (int i = start_pos; i < last_pos; i++)
				myAllocator.destroy(_arr + i);
			int elem_to_move = end() - last;
			std::cout << elem_to_move << std::endl;
			_index = start_pos;
			std::cout << last_pos << std::endl;
			for (int i = 0; i < elem_to_move; i++)
				push_back(_arr[i + last_pos]);
			return first;
		}
		// --> Allocater
		allocator_type get_allocator() const
		{
			return (myAllocator);
		}

		// --> Iterators
	   	class iterator
        {
            public:
                typedef iterator self_type;
                typedef T value_type;
                typedef T& reference;
                typedef T* pointer;
                typedef std::forward_iterator_tag iterator_category;
                typedef int difference_type;
                iterator(pointer ptr) : _ptr(ptr) { }
				iterator(){}
				void operator =(const iterator &src){ _ptr = src._ptr;}
                self_type operator++() { self_type i = *this; _ptr++; return i; }
                self_type operator++(int) { return ++*this; }
				self_type operator--() { self_type i = *this; _ptr--; return i; }
                self_type operator--(int) { return --*this; }
				self_type operator+(int i) { _ptr += i; return *this;}
				self_type operator-(int i) { _ptr -= i; return *this;}
				difference_type operator-(self_type src) { return ( _ptr - src._ptr);}
                reference operator*() { return *_ptr; }
                pointer operator->() { return _ptr; }
                bool operator==(const self_type& rhs) { return _ptr == rhs._ptr; }
                bool operator!=(const self_type& rhs) { return _ptr != rhs._ptr; }
            private:
                pointer _ptr;
        };
		class const_iterator
        {
            public:	
                typedef const_iterator self_type;
                typedef T value_type;
                typedef T& reference;
                typedef T* pointer;
                typedef int difference_type;
                typedef std::forward_iterator_tag iterator_category;
                const_iterator(pointer ptr) : _ptr(ptr) { }
                self_type operator++() { self_type i = *this; _ptr++; return i; }
                self_type operator++(int) { return ++*this; }
				self_type operator--() { self_type i = *this; _ptr--; return i; }
                self_type operator--(int) { return --*this; }
                reference operator*() { return *_ptr; }
                const pointer operator->() { return _ptr; }
                bool operator==(const self_type& rhs) { return _ptr == rhs._ptr; }
                bool operator!=(const self_type& rhs) { return _ptr != rhs._ptr; }
            private:
                pointer _ptr;
        };
		class reverse_iterator
        {
            public:
                typedef reverse_iterator self_type;
                typedef T value_type;
                typedef T& reference;
                typedef T* pointer;
                typedef std::forward_iterator_tag iterator_category;
                typedef int difference_type;
                reverse_iterator(pointer ptr) : _ptr(ptr) { }
                self_type operator++() { self_type i = *this; _ptr--; return i; }
                self_type operator++(int) { return --*this; }
				self_type operator--() { self_type i = *this; _ptr++; return i; }
                self_type operator--(int) { return ++*this; }
                reference operator*() { return *_ptr; }
                pointer operator->() { return _ptr; }
                bool operator==(const self_type& rhs) { return _ptr == rhs._ptr; }
                bool operator!=(const self_type& rhs) { return _ptr != rhs._ptr; }
            private:
                pointer _ptr;
        };
		class const_reverse_iterator
        {
            public:
                typedef const_reverse_iterator self_type;
                typedef T value_type;
                typedef T& reference;
                typedef T* pointer;
                typedef int difference_type;
                typedef std::forward_iterator_tag iterator_category;
                const_reverse_iterator(pointer ptr) : _ptr(ptr) { }
                self_type operator++() { self_type i = *this; _ptr++; return i; }
                self_type operator++(int) { return ++*this; }
				self_type operator--() { self_type i = *this; _ptr--; return i; }
                self_type operator--(int) { return --*this; }
                // const reference operator*() { return *_ptr; }
                const pointer operator->() { return _ptr; }
                bool operator==(const self_type& rhs) { return _ptr == rhs._ptr; }
                bool operator!=(const self_type& rhs) { return _ptr != rhs._ptr; }
            private:
                pointer _ptr;
        };

		iterator begin(){return iterator(_arr);}
		const_iterator begin() const{return const_iterator(_arr);}
		iterator end(){return iterator(_arr + _index);}
		const_iterator end() const{return const_iterator(_arr + _index);}
		reverse_iterator rbegin(){return reverse_iterator(_arr + _index);}
		const_reverse_iterator rbegin() const{return const_reverse_iterator(_arr + _index);}
		reverse_iterator rend(){return reverse_iterator(_arr - 1);}
		const_reverse_iterator rend() const{return const_reverse_iterator(_arr - 1);};

		// Exceptions
		class outOfBoundsIndex: public std::exception
        {
            public:
                outOfBoundsIndex() {};
                virtual ~outOfBoundsIndex()throw() {};
                outOfBoundsIndex(const outOfBoundsIndex &ast)
                {
                    *this = ast;
                };
                outOfBoundsIndex &operator = (const outOfBoundsIndex &ic)
                {
                    (void)ic;
                    return *this;
                };
                virtual const char* what() const throw()
                {
                    return "out of bounds Index...";
                }
        };

	private:
		
		size_type	_max_capacity;
		size_type	_index;
		T			*_arr;
		Alloc	myAllocator;

		void	ft_destroy_arr()
		{
			for (int i = 0; i< _index;i++)
				myAllocator.destroy(_arr + i);
			_index = 0;
		}

		template <class InputIterator>
		void	ft_init_with_iters(InputIterator first, InputIterator last)
		{
			// Check whether it's an integral type.
			// If so, it's not an iterator.
			// Otherwise ...... // todo : remove
			while (first != last)
				push_back(*first++);
		}

		void	ft_init_with_val(size_type n, const value_type& val = value_type())
		{
			for (int i = 0; i < n;i++)
				push_back(val);
		}
};

template <class InputIterator1, class InputIterator2>
bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
	// std::cout << *first1 << "|" << *first2 << std::endl;
  while (first1!=last1)
  {
    if (*first1 != *first2) 
      return false;
    ++first1; ++first2;
  }
  return true;
}

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                            InputIterator2 first2, InputIterator2 last2)
{
  while (first1!=last1)
  {
    if (first2==last2 || *first2<*first1) return false;
    else if (*first1<*first2) return true;
    ++first1; ++first2;
  }
  return (first2!=last2);
}

template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	return (equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!operator==(lhs, rhs));
}

template <class T, class Alloc>
  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (lexicographical_compare(lhs.begin(), lhs.begin(), rhs.begin(), rhs.end()));
}

template <class T, class Alloc>
  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (operator==(lhs, rhs) || operator<(lhs, rhs));
}

template <class T, class Alloc>
  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!operator<(lhs, rhs));
}

template <class T, class Alloc>
  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (operator==(lhs, rhs) || operator>(lhs, rhs));
}

// todo
// is_integral
// enable_if
// swap
// copy/= preserve allocater??

template <class T, class Alloc>
  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	x.swap(y);
}