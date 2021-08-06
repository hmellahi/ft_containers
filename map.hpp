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
        typedef     pair< key_type,mapped_type>                  value_type;
        typedef		Alloc										allocator_type;
		typedef		typename allocator_type::reference			reference;
		typedef		typename allocator_type::const_reference	const_reference;
		typedef		typename allocator_type::pointer			pointer;
		typedef		typename allocator_type::const_pointer		const_pointer;
        typedef		bidir_iterator<value_type>                  iterator;
		typedef		bidir_iterator<const value_type>            const_iterator;
		typedef		reverse_iterator<const_iterator>            const_reverse_iterator;
		typedef		reverse_iterator<iterator>                  reverse_iterator;
		typedef		int                                         difference_type;
		typedef		size_t                                      size_type;

        // Cosntructors
        // empty (1)	
        explicit map (const key_compare& comp = key_compare(),
                    const allocator_type& alloc = allocator_type())
        {
            _size = 0;
            _myAllocator = alloc;
            keyCampare = comp;
        }
        // // range (2)	
        template <class InputIterator>
        map (InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type())
        {
            _size = 0;
            insertIters(first, last);
            keyCampare = comp;
            _myAllocator = alloc;
            // todo key_comapre???
        }
        // copy (3)	
        map (const map& x)
        {
            _size = 0;
            *this = x;
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
            (void)position;// todo wtf is position for??
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
            erase(*position);
        }
        size_type erase (const key_type& k)
        {
            _size--;
            return _rbt.erase(make_pair(k, mapped_type()));
        }
        void erase (iterator first, iterator last)
        {
            while (first != last)
                erase(*first++);
        }

        iterator find (const key_type& k)
        {
            return iterator(&_rbt.search(make_pair(k, mapped_type()))->value);
        }
        const_iterator find (const key_type& k) const
        {
            return const_iterator(&_rbt.search(make_pair(k, mapped_type()))->value);
        }

        size_type count (const key_type& k) const
        {
            if (_rbt.search(make_pair(k, mapped_type())) != NULL)
                return (1);
            return (0);
        }

        iterator lower_bound (const key_type& k)
        {
            iterator start = begin(); 
            iterator last = end(); 
            while (start != last)
            {
                if (!key_compare{}(start->first, k))
                    return start;
                start++;
            }
            return last;
        }

        iterator upper_bound(const key_type& k)
        {
            iterator start = begin(); 
            iterator last = end(); 
            while (start != last)
            {
                if (key_compare{}(k, start->first))
                    return start;
                start++;
            }
            return last;
        }
        const_iterator lower_bound (const key_type& k) const
        {
            const_iterator start = begin(); 
            const_iterator last = end(); 
            while (start != last)
            {
                if (!key_compare{}(start->first, k))
                    return start;
                start++;
            }
            return last;
        }

        const_iterator upper_bound (const key_type& k) const
        {
            const_iterator start = begin(); 
            const_iterator last = end(); 
            while (start != last)
            {
                if (key_compare{}(k, start->first))
                    return start;
                start++;
            }
            return last;
        }

        pair<const_iterator,const_iterator> equal_range (const key_type& k) const
        {
            return (make_pair(lower_bound(k), upper_bound(k)));
        }
        pair<iterator,iterator>             equal_range (const key_type& k)
        {
            return (make_pair(lower_bound(k), upper_bound(k)));
        }

        void swap (map& src)
        {
            map tmp;
			tmp.copy_inner_data(*this);
			this->copy_inner_data(src);
			src.copy_inner_data(tmp);
			tmp.reset_data();
        }
        
        void    clear()
        {
            _rbt.traverse();
        }

        map &operator=(const map &rhs)
        {
            clear();
            const_iterator start = rhs.begin(); 
            const_iterator last = rhs.end();
            while (start != last)
            {
                std::cout << start->first <<"|" <<start->second << std::endl;
                start++;
                // insert(*start++);
            }
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
        allocator_type get_allocator() const { return _myAllocator;}
        //
        key_compare key_comp() const { return keyCampare; }

        // // --> Iterators
        iterator begin() {
            RBT<value_type>* node = _rbt.findMin(_rbt.root);
            if (!node) return iterator(NULL, &_rbt);
            return (iterator(node->value, &_rbt));
        } // todo : protect | memory leaks bo
        const_iterator begin() const {
            RBT<value_type>* node = _rbt.findMin(_rbt.root);
            if (!node) return iterator(NULL, &_rbt);
            return (iterator(node->value, &_rbt));
        }
		iterator end() {return iterator(NULL, &_rbt);}
        const_iterator end() const {return iterator(NULL, &_rbt);}
		reverse_iterator rbegin(){return reverse_iterator(end());}
		// const_reverse_iterator rbegin() const{return const_reverse_iterator(end());}
		// reverse_iterator rend(){return reverse_iterator(begin));}
		// const_reverse_iterator rend() const{ return reverse_iterator(begin));}
        
        // todo:::
        // iterator begin();
        // const_iterator begin() const;
        // iterator end();
        // const_iterator end() const;
        // reverse_iterator rbegin();
        // const_iterator rbegin() const;
        // reverse_iterator rend();
        // const_iterator rend() const;
    
        RBT<value_type>    _rbt; // todo : private bruh
     private:
        size_t  _size;
        size_t  _capacity;
        Alloc   _myAllocator;
        key_compare keyCampare;
    
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

        void	copy_inner_data(const map& other)
		{
			// _arr = other.data();
            _rbt = other._rbt;
			_myAllocator = other.get_allocator();
			_size = other.size();
			_capacity = other.max_size();
		}

        void	reset_data()
		{
			// _arr = other.data();
            _rbt.root = NULL;
			// _myAllocator = NULL;
			_size = 0;
		}
};