/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft::vector.hpp                                         :+:      :+:    :+:   */
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
#include <cstddef>
# include <memory>
# include "iterators.hpp"
// #include "header.hpp"
namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector;
	template <typename T, class Container = vector<T> >
    class stack;
}

template < class T, class Alloc >
class ft::vector
{
	public:
		// using namespace ft;
		// typedef ft::vector ft::ft::vector<T>;
		~vector()
		{
			// std::cout << is_integral<bool>::value << std::endl;
			ft_destroy_arr(); // DRY : replace with clear
			if (_max_capacity)
				myAllocator.deallocate(_arr, _max_capacity);
		};


		typedef		T											value_type;
		typedef		Alloc										allocator_type;
		typedef		typename allocator_type::reference			reference;
		typedef		typename allocator_type::const_reference	const_reference;
		typedef		typename allocator_type::pointer			pointer;
		typedef		typename allocator_type::const_pointer		const_pointer;
		typedef		size_t										size_type;
		typedef		typename iterator_traits<iterator>::difference_type	difference_type;
		typedef		rand_acc_iterator<value_type> iterator;
		typedef		rand_acc_iterator<const value_type> const_iterator;
		typedef		reverse_iterator<const_iterator> const_reverse_iterator;
		typedef		reverse_iterator<iterator> reverse_iterator;
		template<typename>
		struct is_integral
		{static const bool value = false;};
		template<> struct is_integral<bool>{static const bool value = true;};
		template<> struct is_integral<int>{static const bool value = true;};
		// template<> struct is_integral<char16_t>{static const bool value = true;};
		// template<> struct is_integral<char32_t>{static const bool value = true;};
		template<> struct is_integral<signed char>{static const bool value = true;};
		template<> struct is_integral<short int>{static const bool value = true;};
		template<> struct is_integral<long long int>{static const bool value = true;};
		template<> struct is_integral<long int>{static const bool value = true;};
		template<> struct is_integral<unsigned char>{static const bool value = true;};
		template<> struct is_integral<unsigned short int>{static const bool value = true;};
		template<> struct is_integral<unsigned int>{static const bool value = true;};
		template<> struct is_integral<unsigned long int>{static const bool value = true;};
		template<> struct is_integral<unsigned long long int>{static const bool value = true;};

		template<bool B, class D = void>
		struct enable_if {};
		template<class D>
		struct enable_if<true, D> { typedef T type; };
		// -------> constructors
		vector& operator= (const ft::vector<T>& src)
		{
			ft_destroy_arr();
			reserve(src.size());
			ft_init_with_iters(src.begin(), src.end());
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
		    class = typename enable_if<!is_integral<InputIterator>::value>::type>
        vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type())
		{
			_index = 0;
			_max_capacity = 0;
			myAllocator = alloc; // useles??
			reserve(ft::distance(first, last));
			ft_init_with_iters(first, last);
		}

		explicit vector (size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type())
		{
			// std::cout << n << std::endl;
			_index = 0;
			myAllocator = alloc;
			_max_capacity = n;
			_arr = myAllocator.allocate(n);
			ft_init_with_val(n, val);
		}
		// copy constructor
		vector( ft::vector<T> const & src)
		{
			_index = 0;
			_max_capacity = src.capacity(); // ???
			_arr = myAllocator.allocate(_max_capacity);
			ft_init_with_iters(src.begin(), src.end());
		}

		// member functions
		
		//----> Capacity :
		size_type max_size() const {return myAllocator.max_size();}
		size_type size() const{return _index;}
		size_type capacity() const {return _max_capacity;}
		bool empty() const {return (size() == 0);}

		void resize (size_type n, value_type val = value_type())
		{
			//////////////////// ////////// ////////// ////////// ////////// 
            // if n is greater than the current container capacity
			////////////////////////////// ////////// ////////// ////////// 
			if (n > _max_capacity)
			{
				size_type i = _index - 1;
				if (n > (_max_capacity * 2))
					reserve(n);
				else
					reserve(_max_capacity * 2); // todo : right?
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
				new_arr = myAllocator.allocate(n); // todo protect uwu :3
			// }
			// catch (std::bad_alloc& ba)
			// {
			// 	std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
			// 	exit(0);
			// }
			// copy
						// std::cout << _index << "|b|" << _max_capacity << std::endl;

			size_type i = -1;
			while (++i < _index)
				// new_arr[i] = _arr[i];
				myAllocator.construct(new_arr + i, _arr[i]);
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
			if (n >= _index)
				throw std::out_of_range("out of range");
			return (_arr[n]);
		}
		const_reference at(size_type n) const
		{
			if (n >= _index)
				throw std::out_of_range("out of range");
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
			if (_index >= _max_capacity)
				this->reserve(!(_max_capacity * 2) ? 1 : _max_capacity * 2);
			myAllocator.construct(_arr + _index++, val);
		}

		void pop_back()
		{// todo check
			myAllocator.destroy(_arr + --_index);
		}

		void swap (ft::vector<T>& src)
		{
			ft::vector<T> tmp; // todo : fix | double free
			tmp.copy_inner_arr(*this);
			// std::cout << "before: " << tmp.data() << std::endl;
			this->copy_inner_arr(src);
			// std::cout << tmp.data()  << std::endl;
			src.copy_inner_arr(tmp);
			tmp.reset_arr();
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

		iterator insert(iterator position, const value_type& val)
		{
			difference_type pos = position - begin();
            int elem_to_move = end() - position;
			ft::vector<T> tmp;
			tmp.assign(position, end());
			if ((1 + _index) > _max_capacity) // DRY BRIH
				reserve((_index) * 2);
			// printf("\nI : %d\n", elem_to_move);
			_index = pos;
			ft_init_with_val(1, val);
			for (int i = 0; i < elem_to_move; i++)
				push_back(tmp[i]);
			return (begin() + pos);
		}
		
		void insert (iterator position, size_type n, const value_type& val)
		{
			difference_type start = position - begin();
            int elem_to_move = end() - position;
			ft::vector<T> tmp;
			tmp.assign(position, end());
			reserve(_index + n);
			// printf("\nI : %lu\n", _index + n);
			// printf("%d|%d|%d\n", start, elem_to_move, val);
			_index = start;
			ft_init_with_val(n, val);
			for (int i = 0; i < elem_to_move; i++)
				push_back(tmp[i]);
		}

		template <class InputIterator,
		    class = typename enable_if<!is_integral<InputIterator>::value>::type>
    	void insert (iterator position, InputIterator first, InputIterator last)
		{
			difference_type start = position - begin();
            int elem_to_move = end() - position;
			ft::vector<T> tmp;
			tmp.assign(position, end());
			// if (!_index) // todo
			difference_type n  = ft::distance(first, last);
			if ((n + _index) > _max_capacity && (n + _index) > (_index * 2)) // DRY BRIH
				reserve(_index + n);
			else if (!_index)
				reserve(n);
			else if ((size_t)n > _max_capacity) // wtf
				reserve(n * 2);
			// n = 2;
			_index = start;
			ft_init_with_iters(first, last);
			for (int i = 0; i < elem_to_move; i++)
				push_back(tmp[i]);
		}

		template <class InputIterator,
           class = typename enable_if<!is_integral<InputIterator>::value>::type>
		void assign (InputIterator first, InputIterator last)
		{
			// std::cout <<  "d" << last - first << std::endl;
			ft_destroy_arr();
			// reserve(last - first);
			reserve(ft::distance(first, last));
			ft_init_with_iters(first, last);
		} // todo fix

		void assign (size_type n, const value_type& val)
		{
			ft_destroy_arr();
			reserve(n);
			ft_init_with_val(n, val);
		}
		iterator erase (iterator position)
		{
			difference_type pos = position - begin();
			myAllocator.destroy(_arr + pos);
			int elem_to_move = end() - position - 1;
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
			_index = start_pos;
			for (int i = 0; i < elem_to_move; i++)
				push_back(_arr[i + last_pos]);
			return first;
		}
		// --> Allocater
		allocator_type get_allocator() const
		{
			return (myAllocator);
		}

		iterator begin(){return iterator(_arr);}
		const_iterator begin() const{return const_iterator(_arr);}
		iterator end(){return iterator(_arr + _index);}
		const_iterator end() const{return const_iterator(_arr + _index);}
		reverse_iterator rbegin(){return reverse_iterator(_arr + _index);}
		const_reverse_iterator rbegin() const{return const_reverse_iterator(_arr + _index);}
		reverse_iterator rend(){return reverse_iterator(_arr);}
		const_reverse_iterator rend() const{return const_reverse_iterator(_arr);};

	private:
		
		size_type	_max_capacity;
		size_type	_index;
		T			*_arr;
		Alloc	myAllocator;

		void	ft_destroy_arr()
		{
			for (size_type i = 0; i< _index;i++)
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
			// std::cout << n << "|"<< val << "|"<< std::endl;
			for (size_type i = 0; i < n;i++)
				push_back(val);
		}
	
	protected:
		
		void	copy_inner_arr(const ft::vector<T>& other)
		{
			_arr = other.data();
			myAllocator = other.get_allocator();
			_index = other.size();
			_max_capacity = other.capacity();
		}

		void	reset_arr()
		{
			_arr = NULL;
			// myAllocator = NULL;
			_index = 0;
			_max_capacity =0;
		}

		pointer		data() const {return _arr;}
};

template <class InputIterator1, class InputIterator2>
bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
	// std::cout << *first1 << "|" << *first2 << std::endl;
  while (first1!=last1)
    if (*first1++ != *first2++) 
      return false;
  return true;
}

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                            InputIterator2 first2, InputIterator2 last2)
{
while (first1!=last1)
  {
    if (first2==last2 || *first1>*first2) return false;
    else if (*first1<*first2) return true;
    ++first1; ++first2;
	// printf("f1 : %d, f2 : %d\n", *first1, *first2);
  }
  return (first2!=last2);
}

template <class T, class Alloc>
bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	return (equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
  bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return (!operator==(lhs, rhs));
}

template <class T, class Alloc>
  bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (operator==(lhs, rhs))
		return false;
	return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class T, class Alloc>
  bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return (operator==(lhs, rhs) || operator<(lhs, rhs));
}

template <class T, class Alloc>
  bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (operator==(lhs, rhs))
		return false;
	return (!operator<(lhs, rhs));
}

template <class T, class Alloc>
  bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return (operator==(lhs, rhs) || operator>(lhs, rhs));
}

// todo
// copy/= preserve allocater??
// prevent casting from CI TO I ;) (RI AS WELL BRUH) nvm

template <class T, class Alloc>
  void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y)
{
	x.swap(y);
}
