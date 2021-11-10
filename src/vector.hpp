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

#include "iterators.hpp"

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector;
}

template < class T, class Alloc >
class ft::vector
{
	public:
		typedef		T											value_type;
		typedef		Alloc										allocator_type;
		typedef		typename allocator_type::reference			reference;
		typedef		typename allocator_type::const_reference	const_reference;
		typedef		typename allocator_type::pointer			pointer;
		typedef		typename allocator_type::const_pointer		const_pointer;
		typedef		size_t										size_type;
		typedef		rand_acc_iterator<value_type> iterator;
		typedef		typename iterator_traits<iterator>::difference_type	difference_type;
		typedef		rand_acc_iterator<const value_type> const_iterator;
		typedef		reverse_iterator<const_iterator> const_reverse_iterator;
		typedef		reverse_iterator<iterator> reverse_iterator;
		
		
		~vector()
		{
			clear();
			if (_max_capacity)
				myAllocator.deallocate(_arr, _max_capacity);
		};

		
		// -------> constructors
		vector& operator= (const ft::vector<T>& src)
		{
			clear();
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
			_arr = NULL;
		}
		// fill constructor with n elements.
		// range constructor
		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
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
					reserve(_max_capacity * 2);
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
			new_arr = myAllocator.allocate(n);
			
			size_type i = -1;
			while (++i < _index)
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
		{
			myAllocator.destroy(_arr + --_index);
		}

		void swap (ft::vector<T>& src)
		{
			ft::vector<T> tmp;
			tmp.copy_inner_arr(*this);
			this->copy_inner_arr(src);
			src.copy_inner_arr(tmp);
			tmp.reset_arr();
		}

		void	clear()
		{
			for (size_type i = 0; i< _index;i++)
				myAllocator.destroy(_arr + i);
			_index = 0;
		}

		iterator insert(iterator position, const value_type& val)
		{
			difference_type pos = position - begin();
            int elem_to_move = end() - position;
			ft::vector<T> tmp;
			tmp.assign(position, end());
			if ((1 + _index) > _max_capacity)
				reserve((_index) * 2);
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

			if ((n + _max_capacity) > (_max_capacity * 2))
				reserve(_index + n);
			else if (!_index)
				reserve(n);
			else if ((size_t)n > _max_capacity)
				reserve(n * 2);

			_index = start;
			ft_init_with_val(n, val);
			for (int i = 0; i < elem_to_move; i++)
				push_back(tmp[i]);
		}

		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
		{
			difference_type start = position - begin();
            int elem_to_move = end() - position;
			ft::vector<T> tmp;
			tmp.assign(position, end());
			difference_type n  = ft::distance(first, last);

			if ((n + _max_capacity) > (_max_capacity * 2))
				reserve(_index + n);
			else if (!_index)
				reserve(n);
			else if ((size_t)n > _max_capacity)
				reserve(n * 2);
			
			_index = start;
			ft_init_with_iters(first, last);
			for (int i = 0; i < elem_to_move; i++)
				push_back(tmp[i]);
		}

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
		{
			clear();
			reserve(ft::distance(first, last));
			ft_init_with_iters(first, last);
		}

		void assign (size_type n, const value_type& val)
		{
			clear();
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

		template <class InputIterator>
		void	ft_init_with_iters(InputIterator first, InputIterator last)
		{
			while (first != last)
				push_back(*first++);
		}

		void	ft_init_with_val(size_type n, const value_type& val = value_type())
		{
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
			_index = 0;
			_max_capacity =0;
		}

		pointer		data() const {return _arr;}
};

template <class T, class Alloc>
bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
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
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
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

namespace ft
{
	template <class T, class Alloc>
	void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y)
	{
		x.swap(y);
	}
}

// todo wtf is explicit constructor