#pragma once
#include <iostream>
#include <cstddef>
#include "AVL.hpp"


namespace ft
{
    template <class Category, class T, class Distance = ptrdiff_t,
            class Pointer = T*, class Reference = T&>
    struct iterator {
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category  iterator_category;
    };

    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag {};
    struct bidirectional_iterator_tag {};
    struct random_access_iterator_tag {};
    template <class Iterator>
    class iterator_traits
    {
    public:
        typedef typename Iterator::value_type            value_type;
        typedef typename Iterator::difference_type       difference_type;
        typedef typename Iterator::pointer               pointer;
        typedef typename Iterator::reference             reference;
        typedef typename Iterator::iterator_category     iterator_category;
    };
    template <class T> 
    class iterator_traits<T*>
    {
    public:    
        typedef T                           value_type;
        typedef ptrdiff_t                   difference_type;
        typedef T*                          pointer;
        typedef T&                          reference;
        typedef random_access_iterator_tag  iterator_category;
    };

    template <class T> 
    class iterator_traits<const T*>
    {
    public:
        typedef T                           value_type;
        typedef ptrdiff_t                   difference_type;
        typedef const T*                    pointer;
        typedef const T&                    reference;
        typedef random_access_iterator_tag  iterator_category;
    };

    template<class It>
    typename ft::iterator_traits<It>::difference_type
        distance(It first, It last)
    {
        typename ft::iterator_traits<It>::difference_type result = 0;
        while (first != last)
        {
            ++first;
            ++result;
        }
        return result;
    }

    template <class InputIterator1, class InputIterator2>
    bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
    {
        while (first1!=last1)
            if (*first1++ != *first2++) 
            return false;
        return true;
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal (InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2, BinaryPredicate pred)
    {
        while (first1!=last1)
            if (!pred(*first1++, *first2++)) 
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
        }
        return (first2!=last2);
    }

    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2,
                                Compare comp)
    {
         while (first1!=last1)
        {
            if ((!comp(*first1,*first2) && !comp(*first2,*first1)) || *first1>*first2) return false;
            else if (*first1<*first2) return true;
            ++first1; ++first2;
        }
        return (first2!=last2);
        // return (!comp(a,b) && !comp(b,a));
    }
    
    template <typename Iterator>
    class reverse_iterator;

    template<typename>
    struct is_integral
    {static const bool value = false;};
    template<> struct is_integral<bool>{static const bool value = true;};
    template<> struct is_integral<int>{static const bool value = true;};
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
    struct enable_if<true, D> { typedef D type; };
}

template <typename T>
class rand_acc_iterator;
template <class Iterator>
class ft::reverse_iterator
{
// private:

public:
    Iterator it;
    typedef typename ft::iterator_traits<Iterator>::value_type          value_type;
    typedef typename ft::iterator_traits<Iterator>::difference_type     difference_type;
    typedef typename ft::iterator_traits<Iterator>::pointer             pointer;
    typedef typename ft::iterator_traits<Iterator>::reference           reference;
    typedef typename ft::iterator_traits<Iterator>::iterator_category   iterator_category;
    typedef Iterator            iterator_type;
    typedef ft::reverse_iterator<iterator_type>    self_type;

    reverse_iterator(){}
    explicit reverse_iterator (iterator_type iter){ it = iter;}
    template <class Iter>
    reverse_iterator (const ft::reverse_iterator<Iter>& rev_it) {it = rev_it.base();}
    self_type&	operator++() {  it--; return *this;}
    self_type	operator++(int) { self_type i = *this; it--; return i;}
    self_type&	operator--() { it++; return *this;}
    self_type	operator--(int) { self_type i = *this; it++; return i;}
    reference operator[](difference_type i) const { return this->base()[- i - 1];}
    self_type operator+=(difference_type i) { it -= i; return *this;}
    self_type operator-=(difference_type i) { it += i; return *this;}
    iterator_type base() const { return iterator_type(it);}
    reverse_iterator operator+ (difference_type n) const { return self_type(it - n); }
    reverse_iterator operator- (difference_type n) const { return self_type(it + n); }
    reference operator*() const { return *(--Iterator(it)); }
    pointer operator->() const { return &(operator*()); }
};

template <class Iter, class Iter2>
    bool operator== (const ft::reverse_iterator<Iter>& lhs,
        const ft::reverse_iterator<Iter2>& rhs) { return (lhs.base()) == rhs.base();}
template <class Iter, class Iter2>
    bool operator!= (const ft::reverse_iterator<Iter>& lhs,
        const ft::reverse_iterator<Iter2>& rhs) { return (lhs.it) != (rhs.it);}
template <class Iter, class Iter2>
    bool operator>= (const ft::reverse_iterator<Iter>& lhs,
        const ft::reverse_iterator<Iter2>& rhs) { return lhs.base() <= rhs.base();}
template <class Iter, class Iter2>
    bool operator> (const ft::reverse_iterator<Iter>& lhs,
        const ft::reverse_iterator<Iter2>& rhs) { return lhs.base() < rhs.base();}
template <class Iter, class Iter2>
    bool operator<= (const ft::reverse_iterator<Iter>& lhs,
        const ft::reverse_iterator<Iter2>& rhs) { return lhs.base() >= rhs.base();}
template <class Iter, class Iter2>
    bool operator< (const ft::reverse_iterator<Iter>& lhs,
        const ft::reverse_iterator<Iter2>& rhs) { return lhs.base() > rhs.base();}

template <class Iterator, class Iter>
  typename ft::reverse_iterator<Iterator>::difference_type operator- (
    const ft::reverse_iterator<Iterator>& lhs,
    const ft::reverse_iterator<Iter>& rhs)
{
    return (-1 * (lhs.base() - rhs.base()));
}

template <class Iterator>
  ft::reverse_iterator<Iterator> operator+ (
             typename ft::reverse_iterator<Iterator>::difference_type n,
             const ft::reverse_iterator<Iterator>& rev_it)
{
    return  ft::reverse_iterator<Iterator>(rev_it.base() - n);
}

template <typename T>
class rand_acc_iterator : public ft::iterator<std::random_access_iterator_tag, T>
{
    public:
        typedef T                           value_type;
        typedef int                         difference_type;
        typedef T*                          pointer;
        typedef T&                          reference;
        typedef std::random_access_iterator_tag  iterator_category;
        typedef rand_acc_iterator self_type;
        rand_acc_iterator(pointer ptr) : _ptr(ptr) { };
        rand_acc_iterator(){}
        self_type base() const { return self_type(_ptr);}
        rand_acc_iterator&   operator=(const value_type& it)
        {
             _ptr = &it;
            return (*this);
        }
        rand_acc_iterator(const value_type& it)
        {
            _ptr = *it;
        }
        operator rand_acc_iterator<const T> () const { return rand_acc_iterator<const T>(_ptr); }
        
        self_type& operator++() {_ptr++; return *this; }
        self_type operator++(int) {self_type i = *this; _ptr++; return i;}
        self_type& operator--() { _ptr--; return *this;}
        self_type operator--(int) { self_type i = *this; _ptr--; return i;}
        self_type operator+=(int i) { _ptr += i; return *this;}
        self_type operator-=(int i) { _ptr -= i; return *this;}
        friend self_type operator+(self_type it, difference_type i)
        {
            return (it._ptr + i);
        }
        friend self_type operator+(difference_type i, self_type it)
        {
            return (it._ptr + i);
        }
        friend self_type operator-(self_type it, difference_type i)
        {
            return (it._ptr - i);
        }
        difference_type operator-(self_type src)const { return ( _ptr - src._ptr);}
        reference operator*()const { return *_ptr; }
        pointer operator->() const{ return _ptr; }
        reference operator[](size_t i) { return _ptr[i]; }

        friend bool operator!= (const rand_acc_iterator& lhs,
                        const rand_acc_iterator& rhs) { return lhs._ptr != rhs._ptr;}
        friend bool operator>= (const rand_acc_iterator& lhs,
                        const rand_acc_iterator& rhs) { return lhs._ptr >= rhs._ptr;}
        friend bool operator<= (const rand_acc_iterator& lhs,
                        const rand_acc_iterator& rhs) { return lhs._ptr <= rhs._ptr;}
        friend bool operator> (const rand_acc_iterator& lhs,
                        const rand_acc_iterator& rhs) { return lhs._ptr > rhs._ptr;}
        friend bool operator< (const rand_acc_iterator& lhs,
                        const rand_acc_iterator& rhs) { return lhs._ptr < rhs._ptr;}
        friend bool operator== (const rand_acc_iterator& lhs,
                        const rand_acc_iterator& rhs) { return lhs._ptr == rhs._ptr;}
    private:
        pointer _ptr;
};


template <typename T, typename Compare, typename Alloc>
class bidir_iterator : public ft::iterator<std::bidirectional_iterator_tag, T>
{
    public:
        typedef T                               value_type; // DRY
        typedef int                             difference_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef bidir_iterator                  self_type;
        bidir_iterator(pointer ptr, const AVL<value_type, Compare, Alloc>* bst = NULL)
        : _ptr(ptr)
        {
            _bst = bst;
        };
        bidir_iterator(){
            _ptr = NULL;
        }
        ~bidir_iterator(){}
        bidir_iterator&   operator=(const bidir_iterator& bid_it)
        {
            _ptr = bid_it._ptr;
            _bst = bid_it._bst;
            return (*this);
        }

        operator bidir_iterator<const T, Compare, Alloc> () const { return bidir_iterator<const T, Compare, Alloc>(_ptr, reinterpret_cast<const AVL<const value_type, Compare, Alloc>*>(_bst)); }
        
        self_type& operator++()
        {
            AVL<value_type, Compare, Alloc>* curr = _bst->search(*_ptr);
            if (!curr) { return *this;}
            AVL<value_type, Compare, Alloc>* nextNode = curr->next();
            if (nextNode)
                _ptr = nextNode->value;
            else
                _ptr = NULL;
            return *this;
        }
        self_type operator++(int) {
            self_type i = *this;
            ++(*this);
            return i;
        }
        self_type& operator--() {
            // if the ptr is NULL then its must be the last element
            if (!_ptr)
            {
                AVL<value_type, Compare, Alloc>* max = _bst->findMax(_bst->root);
                if (max)
                    _ptr = max->value;
                return *this;
            }
            AVL<value_type, Compare, Alloc>* curr = _bst->search(*_ptr);
            if (!curr) { return *this;}
            AVL<value_type, Compare, Alloc>* prevNode = curr->prev();
            if (prevNode)
                _ptr = prevNode->value;
            else
                _ptr = NULL;
            return *this;
        }
        self_type operator--(int) { self_type i = *this; --(*this); return i;}
        difference_type operator-(self_type src)const { return ( _ptr - src._ptr);}
        reference operator*()const { return *_ptr;  }
        pointer operator->() const{ return _ptr; }

        friend bool operator== (const bidir_iterator& lhs,
            const bidir_iterator& rhs) {
                return (lhs._ptr == rhs._ptr) || (lhs._ptr && rhs._ptr && lhs._ptr->first == rhs._ptr->first);
            }
        friend bool operator!= (const bidir_iterator& lhs,
            const bidir_iterator& rhs) { return !(lhs == rhs);}
    public:
        pointer _ptr;
        const AVL<value_type, Compare, Alloc>* _bst;
};