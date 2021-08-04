#include <iostream>
#include <cstddef>
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

namespace ft
{
    template<class It>
typename std::iterator_traits<It>::difference_type
    distance(It first, It last)
{
    typename std::iterator_traits<It>::difference_type result = 0;
    while (first != last)
    {
        ++first;
        ++result;
    }
    return result;
}

}

template <typename T>
class rand_acc_iterator;
template <class Iterator>
class reverse_iterator
{
// private:

public:
    Iterator it;
    typedef typename iterator_traits<Iterator>::value_type          value_type;
    typedef typename iterator_traits<Iterator>::difference_type     difference_type;
    typedef typename iterator_traits<Iterator>::pointer             pointer;
    typedef typename iterator_traits<Iterator>::reference           reference;
    typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
    typedef Iterator            iterator_type;
    typedef reverse_iterator    self_type;

    reverse_iterator(){}
    explicit reverse_iterator (iterator_type iter){ it = iter;}
    template <class Iter>
    reverse_iterator (const reverse_iterator<Iter>& rev_it) {it = rev_it.base();}
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
    reference operator*() const { return *(it - 1); }
    pointer operator->() const { return &(operator*()); }
    // operator reverse_iterator<const Iterator> () const { return reverse_iterator<const Iterator>(it); }
    // friend bool operator>= (const reverse_iterator& lhs,
    //     const reverse_iterator& rhs) { return lhs.it <= rhs.it;}
    // friend bool operator<= (const reverse_iterator& lhs,
    //     const reverse_iterator& rhs) { return lhs.it >= rhs.it;}
    // friend bool operator> (const reverse_iterator& lhs,
    //     const reverse_iterator& rhs) { return lhs.it < rhs.it;}
    // friend bool operator< (const reverse_iterator& lhs,
    //     const reverse_iterator& rhs) { return lhs.it > rhs.it;}
    // template <typename Iter>
    // friend bool operator== (const reverse_iterator<Iter>& lhs,
        // const reverse_iterator<const Iter>& rhs) { return lhs.it == rhs.it;}
    // friend difference_type operator- (const reverse_iterator& lhs,
        // const reverse_iterator& rhs) { return (lhs.it - rhs.it);}
    // difference_type operator+(self_type src)const { return (1);}
    // friend self_type operator+(self_type it, difference_type i)
    // {
    //     return self_type(it._ptr - i + 1);
    // }
    // friend self_type operator+(difference_type i, self_type it)
    // {
    //     return self_type(it - n);
    // }
    // friend self_type operator-(self_type it, difference_type i)
    // {
    //     return self_type(it + i + 1);
    // }
    
};

template <class Iter, class Iter2>
    bool operator== (const reverse_iterator<Iter>& lhs,
        const reverse_iterator<Iter2>& rhs) { return (lhs.base()) == rhs.base();}
template <class Iter, class Iter2>
    bool operator!= (const reverse_iterator<Iter>& lhs,
        const reverse_iterator<Iter2>& rhs) { return (lhs.it) != (rhs.it);}
template <class Iter, class Iter2>
    bool operator>= (const reverse_iterator<Iter>& lhs,
        const reverse_iterator<Iter2>& rhs) { return lhs.base() <= rhs.base();}
template <class Iter, class Iter2>
    bool operator> (const reverse_iterator<Iter>& lhs,
        const reverse_iterator<Iter2>& rhs) { return lhs.base() < rhs.base();}
template <class Iter, class Iter2>
    bool operator<= (const reverse_iterator<Iter>& lhs,
        const reverse_iterator<Iter2>& rhs) { return lhs.base() >= rhs.base();}
template <class Iter, class Iter2>
    bool operator< (const reverse_iterator<Iter>& lhs,
        const reverse_iterator<Iter2>& rhs) { return lhs.base() > rhs.base();}
// template <class Iterator, class Iter>
//   reverse_iterator<Iterator> operator- (
//              typename reverse_iterator<Iterator>::difference_type n,
//              const reverse_iterator<Iter>& rev_it)
// {
//     return (rev_it + n);
// }
template <class Iterator, class Iter>
  typename reverse_iterator<Iterator>::difference_type operator- (
    const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iter>& rhs)
{
    // std::cout << "yy";
    return (-1 * (lhs.base() - rhs.base()));
}

template <class Iterator>
  reverse_iterator<Iterator> operator+ (
             typename reverse_iterator<Iterator>::difference_type n,
             const reverse_iterator<Iterator>& rev_it)
{
    // std::cout << "yy";
    return  reverse_iterator<Iterator>(rev_it.base() - n);
}

// template <class Iterator>
//   reverse_iterator<Iterator> operator-(
//              typename reverse_iterator<Iterator>::difference_type n,
//              const reverse_iterator<Iterator>& rev_it)
// {
//     return (rev_it - n);
// }

template <typename T>
class rand_acc_iterator : public iterator<input_iterator_tag, T>
{
    public:
        typedef T                           value_type; // DRY
        typedef int                         difference_type;
        typedef T*                          pointer;
        typedef T&                          reference;
        typedef random_access_iterator_tag  iterator_category;
        // typedef typename iterator::value_type            value_type;
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


template <typename T>
class bidir_iterator : public iterator<input_iterator_tag, T>
{
    public:
        typedef T                           value_type; // DRY
        typedef int                         difference_type;
        typedef T*                          pointer;
        typedef T&                          reference;
        typedef bidirectional_iterator_tag  iterator_category;
        typedef bidir_iterator self_type;
        bidir_iterator(pointer ptr, RBT<value_type>* bst = NULL) : _ptr(ptr) {
            _bst = bst;
        };
        bidir_iterator(){}
        bidir_iterator&   operator=(const value_type& it)
        {
            // todo
            //  _ptr = &it;
            //  puts("tt");
            // ();
            _ptr = new T();
            *_ptr = it;
            return (*this);
        }
        bidir_iterator(const value_type& it, RBT<value_type>* bst)
        {
        // {terator
            _ptr = new T();
            *_ptr = it;
            _bst = bst;
        }
        operator bidir_iterator<const T> () const { return bidir_iterator<const T>(_ptr); }
        
        self_type& operator++() {// DRY
            RBT<value_type>* nextNode=_bst->search(*_ptr)->next();
            if (nextNode)
                *_ptr = nextNode->value;
            else
                _ptr = NULL;
            return *this; 
        }
        self_type operator++(int) {
            self_type i = *this;
            RBT<value_type>* nextNode=_bst->search(*_ptr)->next();
            if (nextNode)
                *_ptr = nextNode->value;
            else
                _ptr = NULL;
            return i;
        }
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
        reference operator*()const { return *_ptr;  }
        pointer operator->() const{ return _ptr; }

        friend bool operator== (const bidir_iterator& lhs,
            const bidir_iterator& rhs) {
                return (lhs._ptr == rhs._ptr) || (lhs._ptr && rhs._ptr && *(lhs._ptr) ==*(rhs._ptr));
            }
        friend bool operator!= (const bidir_iterator& lhs,
            const bidir_iterator& rhs) { return !(lhs == rhs);}
    public:
        pointer _ptr;
        RBT<value_type>* _bst;
};