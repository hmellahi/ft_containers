#pragma once
#include <memory>
#include <iostream>
#include "RBT.hpp"
// class pair;
namespace ft
{
    template<typename A, typename B>
    class pair;
    template < class Key,                                     // map::key_type
        class T,                                       // map::mapped_type
        class Compare = std::less<Key>,                     // map::key_compare
        class Alloc = std::allocator<pair<const Key,T> >    // map::allocator_type
    > 
    class map;
}
#include "pair.hpp"
#include "iterators.hpp"

template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare,                   // map::key_compare
           class Alloc    // map::allocator_type
           > 
class ft::map
{
    public:
        typedef     map 										self_type;
        typedef     Key 										key_type;
        typedef     T											mapped_type;
        typedef     Compare                                     key_compare;
        typedef     pair<key_type,mapped_type>                  value_type;
        typedef		Alloc										allocator_type;
		typedef		typename allocator_type::reference			reference;
		typedef		typename allocator_type::const_reference	const_reference;
		typedef		typename allocator_type::pointer			pointer;
		typedef		typename allocator_type::const_pointer		const_pointer;
        typedef		bidir_iterator<value_type>                  iterator;
		typedef		bidir_iterator<const value_type>            const_iterator;
		// typedef		reverse_iterator<const_iterator>            const_reverse_iterator;
		// typedef		reverse_iterator<iterator>                  reverse_iterator;
		typedef		int                                         difference_type;
		typedef		size_t                                      size_type;

        // Cosntructors
        // empty (1)	
        explicit map (const key_compare& comp = key_compare(),
                    const allocator_type& alloc = allocator_type())
        {
            _size = 0;
        }
        // // range (2)	
        template <class InputIterator>
        map (InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type())
        {
            _size = 0;
            insertIters(first, last);
            // todo key_comapre???
        }
        // copy (3)	
        map (const map& x)
        {
            // x.begin();
            // iterator first = x.begin();
            // map::iterator last = x.end();
            // while (first != last) // DRY
                // _rbt.insert(*first++);
        }

        ~map()
        {
            // traverseInOrder(destroy);
            // traverseInOrder();
            // traverseInOrder(free);
        }

        // --------> Modifiers
        // single element (1)	
        pair<iterator,bool> insert (const value_type& val)
        {
            pair<iterator,bool> res;
            RBT<value_type>* node = _rbt.search(val);
            if (!node)
            {
                node = _rbt.insert(val);
                res.second = true;
            }
            res.first = iterator(&node->value);
            _size++;
            return res;
        }
        // with hint (2)	
        iterator insert (iterator position, const value_type& val)
        {
            return insert(val).first;
        }
        // range (3)	
        template <class InputIterator>
        void insert (InputIterator first, InputIterator last)
        {
            insertIters(first, last);
        }

        void erase (iterator position)
        {
            
        }
        size_type erase (const key_type& k)
        {
            // RBT<value_type>* node = _rbt.search(make_pair(k, mapped_type()));
            // if (!node)
            //     return 0;
            // // delete node;
            // _rbt.erase(node);
            return _rbt.erase(make_pair(k, mapped_type()));
        }
        void erase (iterator first, iterator last)
        {

        }
        // map(const map& src)
        // {

        // }

        // explicit map (const key_compare& comp = key_compare(),
        //       const allocator_type& alloc = allocator_type())
        // {
        //     _myAllocator = alloc;
        // }

        // template <class InputIterator>
        //     map (InputIterator first, InputIterator last,
        //         const key_compare& comp = key_compare(),
        //         const allocator_type& alloc = allocator_type())
        // {

        // }

        map &operator=(map const &rhs)
        {
            (void)rhs; // todo
            return (*this);
        }

        mapped_type   &operator[](const key_type& key)
        {
            value_type to_find = ft::make_pair(key, mapped_type());
			RBT<value_type>* node = _rbt.search(to_find);
            if (!node)
            {
                _size++;
                node = _rbt.insert(to_find);
            }
            return node->value.second;
        }


        //----> Capacity :
		size_type max_size() const {return _myAllocator.max_size();}
		size_type size() const{return _size;}
		bool empty() const {return (size() == 0);} 
        
        // --> allocator getter
        allocator_type get_allocator() const;

        // // --> Iterators
        iterator begin() { return (iterator(_rbt.findMin(_rbt.root)->value, &_rbt));}
        const_iterator begin() const { return (const_iterator(_rbt.findMin(_rbt.root)->value, &_rbt));}
		iterator end() {return iterator(NULL, &_rbt);}
        const_iterator end() const {return const_iterator(NULL, &_rbt);}
		// const_iterator end() const {return const_iterator(NULL);}
		// reverse_iterator rbegin(){return reverse_iterator(NULL);}
		// const_reverse_iterator rbegin() const{return const_reverse_iterator(NULL);}
		// reverse_iterator rend(){return reverse_iterator(_arr);}
		// const_reverse_iterator rend() const{rse_iterator(_arr);}
		// const_reverse_iterator rend() const{return const_reverse_iterator(_arr);};
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
    
        // void   destroy(RBT<value_type> *node)
        // {
        //     _myAllocator.destroy(node);
        // }

        // void    traverseInOrder()//(void (*func)(RBT<value_type> *))
        // {
        //     // for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        //         // func(it);
        //     RBT<value_type> *curr =  _rbt.search(_rbt.findMin(&_rbt));
        //     while (curr != NULL)
        //     {
        //         // (*func)(curr);
        //         _myAllocator.deallocate(curr);
        //         curr = curr->next();
        //     }
        // }
        template <class InputIterator>
        void    insertIters(InputIterator first, InputIterator last)
        {
            while (first != last) // DRY
                insert(*first++);
        }
};