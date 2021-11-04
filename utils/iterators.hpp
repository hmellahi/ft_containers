#pragma once
#include <iostream>
#include <cstddef>
#include "RBT.hpp"


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
        }
        return (first2!=last2);
    }
    template <typename Iterator>
    class reverse_iterator;
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
    reference operator[](difference_type i) const { return this->base()[- i - 1];} // todo...
    self_type operator+=(difference_type i) { it -= i; return *this;} // check
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
    // std::cout << "yy";
    return  ft::reverse_iterator<Iterator>(rev_it.base() - n);
}

template <typename T>
class rand_acc_iterator : public ft::iterator<std::random_access_iterator_tag, T>
{
    public:
        typedef T                           value_type; // DRY
        typedef int                         difference_type;
        typedef T*                          pointer;
        typedef T&                          reference;
        typedef std::random_access_iterator_tag  iterator_category;
        // typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type            value_type;
        // typedef typename iterator::difference_type       difference_type;
        // typedef typename iterator::pointer               pointer;
        // typedef typename iterator::reference             reference;
        // typedef typename iterator::iterator_category     iterator_category;
        typedef rand_acc_iterator self_type;
        rand_acc_iterator(pointer ptr) : _ptr(ptr) { };
        rand_acc_iterator(){}
        rand_acc_iterator&   operator=(const value_type& it)
        {
            // todo
             _ptr = &it;
            //  puts("tt");
            return (*this);
        }
        rand_acc_iterator(const value_type& it)
        {
        // {terator
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
        // difference_type operator-(difference_type i)const { return ( _ptr - i);}
        // difference_type operator+(difference_type i)const { return ( _ptr + i);}
        // difference_type operator-(self_type src)const { return ( _ptr - src._ptr);}
        reference operator*()const { return *_ptr; }
        pointer operator->() const{ return _ptr; }
        reference operator[](size_t i) { return _ptr[i]; } // todo...

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
        // friend bool operator- (const rand_acc_iterator& lhs,
                        // const rand_acc_iterator& rhs) { return lhs._ptr - rhs._ptr;}
    private:
        pointer _ptr;
};


template <typename T, typename Compare>
class bidir_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
{
    public:
        typedef T                           value_type; // DRY
        typedef int                         difference_type;
        typedef T*                          pointer;
        typedef T&                          reference;
        // typedef std::less<T>                   Compare; // TODO REMOVE
        typedef ft::bidirectional_iterator_tag  iterator_category;
        // std::allocator;
        typedef bidir_iterator self_type;
        bidir_iterator(pointer ptr, const RBT<value_type, Compare>* bst = NULL)
        : _ptr(ptr)
        {
            _bst = bst;
        };
        bidir_iterator(){
            _ptr = NULL;
        }
        ~bidir_iterator()
        {
            // if (_ptr)    
                // delete _ptr;
        }
        bidir_iterator&   operator=(const bidir_iterator& bid_it)
        {
            _ptr = bid_it._ptr;
            _bst = bid_it._bst; // todo wtf is wrong? take a copy broo
            return (*this);
        }
        // binder2nd
        bidir_iterator(const value_type& it, const RBT<value_type, Compare>* bst)
        :_ptr(new T(it)) // todo use allocater
        {
            _bst = bst; // todo wtf is wrong? take a copy broo
        }
        // bidir_iterator(pointer ptr, const RBT<value_type, Compare>* bst)
        // {
        //     _ptr = ptr;
        //     _bst = bst; // todo wtf is wrong? take a copy broo
        // }
        operator bidir_iterator<const T, Compare> () const { return bidir_iterator<const T, Compare>(_ptr, new RBT<const T, Compare>(_bst));}//, Compare>(_ptr, _bst); } // add _bst
        
        self_type& operator++()
        {
            RBT<value_type, Compare>* curr = _bst->search(*_ptr);
            if (!curr) { return *this;}
            RBT<value_type, Compare>* nextNode = curr->next();
            if (nextNode)
                _ptr = nextNode->value; // leaks bro ig
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
            // if (!_ptr && parent) return parent;
            // puts("hey1");
            // if the ptr is NULL then its must be the last element
            if (!_ptr)
            {
                _ptr = _bst->findMax(_bst->root)->value; // protect : seg
                return *this;
            }
            RBT<value_type, Compare>* curr = _bst->search(*_ptr);
            if (!curr) { return *this;}
            RBT<value_type, Compare>* prevNode = curr->prev();
            if (prevNode)
                _ptr = prevNode->value; // todo rm leaks
            else
                _ptr = NULL;
            return *this;
        }
        self_type operator--(int) { self_type i = *this; --(*this); return i;}
        friend self_type operator-(self_type it, difference_type i)
        {
            i = 1;
            return (--bidir_iterator(it._ptr, it._bst)); // todo change / rm
        }
        difference_type operator-(self_type src)const { return ( _ptr - src._ptr);}
        reference operator*()const { return *_ptr;  } // todo optimize
        // reference operator*()const { return *(_bst->search(*_ptr)->value);  } // todo optimize
        pointer operator->() const{ return _bst->search(*_ptr)->value; } // todo optimize

        friend bool operator== (const bidir_iterator& lhs,
            const bidir_iterator& rhs) {
                return (lhs._ptr == rhs._ptr) || (lhs._ptr && rhs._ptr && lhs._ptr->first == rhs._ptr->first);
            }
        friend bool operator!= (const bidir_iterator& lhs,
            const bidir_iterator& rhs) { return !(lhs == rhs);}
    public:
        pointer _ptr;
        const RBT<value_type, Compare>* _bst;
};