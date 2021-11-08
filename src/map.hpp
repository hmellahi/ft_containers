#pragma once
#include <memory>
#include <iostream>
#include "RBT.hpp"
#include "pair.hpp"
#include "iterators.hpp"

namespace ft
{
    template < class Key,                                     // map::key_type
        class T,                                       // map::mapped_type
        class Compare = std::less<Key>,                     // map::key_compare
        class Alloc = std::allocator<pair<const Key,T> >    // map::allocator_type
    > 
    class map;
}


template < class Key,  // f map::key_type
           class T,    // map::mapped_type
           class Compare, // map::key_compare
           class Alloc    // map::allocator_type
           > 
class ft::map
{
    public:
        typedef     Key 										key_type;
        typedef     T											mapped_type;
        typedef     Compare                                     key_compare;
        typedef     pair<const key_type,mapped_type>            value_type;
        typedef		Alloc										allocator_type;
		typedef		typename allocator_type::reference			reference;
		typedef		typename allocator_type::const_reference	const_reference;
		typedef		typename allocator_type::pointer			pointer;
		typedef		typename allocator_type::const_pointer		const_pointer;
        typedef		bidir_iterator<value_type, Compare>         iterator;
		typedef		bidir_iterator<const value_type, Compare>   const_iterator;
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
        }
        // copy (3)	
        map (const map& x)
        {
            _size = 0;
            *this = x;
        }

        ~map()
        {
            clear();
        }

        // --------> Modifiers
        // single element (1)	
        pair<iterator,bool> insert (const value_type& val)
        {
            pair<iterator,bool> res;
            RBT<value_type, Compare>* node = _rbt.search(val);
            if (!node)
            {
                node = _rbt.insert(val);
                res.second = true;
                _size++;
            }
            res.first = iterator(node->value);
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

        size_type erase (const key_type& k)
        {
            return _rbt.erase(ft::make_pair(k, mapped_type())) && _size--;
        }

        void erase (iterator position)
        {
            _rbt.erase(*position) && _size--;
        }

        void erase (iterator first, iterator last)
        {
            if (first == last)
                return ;
            value_type min = *first;
            int n = 0;
            if (last != end())
                _rbt.root = _rbt.iter(_rbt.root, min, *last, false, n);
            else
                _rbt.root = _rbt.iter(_rbt.root, min, value_type(), true, n);
            _size -= n;
        }

        iterator find (const key_type& k)
        {
            RBT<value_type, Compare> *res = _rbt.search(ft::make_pair(k, mapped_type()));
            return iterator(res ? res->value : NULL , &_rbt);
        }

        const_iterator find (const key_type& k) const
        {
            RBT<value_type, Compare> *res = _rbt.search(ft::make_pair(k, mapped_type()));
            return const_iterator(res ? res->value : NULL , &_rbt);
        }

        size_type count (const key_type& k) const
        {
            if (_rbt.search(ft::make_pair(k, mapped_type())) != NULL)
                return (1);
            return (0);
        }

        iterator lower_bound (const key_type& k)
        {
            RBT<value_type, Compare> *bound = NULL;
            bound = findBound2(_rbt.root, k, bound);
            return iterator(bound ? bound->value : NULL, &_rbt);
        }

        // RBT<value_type, Compare>    *findBound(RBT<value_type, Compare> *root, const key_type&k, RBT<value_type, Compare> *bound) const
        // {
        //     if (!root) return bound;

        //     if (keyCampare(k, root->value->first) && (!bound ||  !keyCampare(bound->value->first, root->value->first)))
        //         bound = root;

        //     if (!keyCampare(k, root->value->first))
        //         return (findBound(root->right, k, bound));
        //     else
        //         return (findBound(root->left, k, bound));
        //     return bound;
        // }

        // RBT<value_type, Compare>    *findBound2(RBT<value_type, Compare> *root, const key_type&k, RBT<value_type, Compare> *bound) const
        // {
        //     if (!root) return bound;
        //     if (!keyCampare(root->value->first, k) && (!bound || !keyCampare(bound->value->first, root->value->first)))
        //         bound = root;

        //     if (!keyCampare(k, root->value->first))
        //         return (findBound2(root->right, k, bound));
        //     else
        //         return (findBound2(root->left, k, bound));
        //     return bound;
        // }

        iterator upper_bound(const key_type& k)
        {
            RBT<value_type, Compare> *bound = NULL;
            bound = findBound(_rbt.root, k, bound);
            return iterator(bound ? bound->value : NULL, &_rbt);
        }
        
        const_iterator lower_bound (const key_type& k) const
        {
            RBT<value_type, Compare> *bound = NULL;
            bound = findBound2(_rbt.root, k, bound);
            return iterator(bound ? bound->value : NULL, &_rbt);
        }

        const_iterator upper_bound (const key_type& k) const
        {
            RBT<value_type, Compare> *bound = NULL;
            bound = findBound(_rbt.root, k, bound);
            return iterator(bound ? bound->value : NULL, &_rbt);
        }

        pair<const_iterator,const_iterator> equal_range (const key_type& k) const
        {
            return (ft::make_pair(lower_bound(k), upper_bound(k)));
        }

        pair<iterator,iterator>             equal_range (const key_type& k)
        {
            return (ft::make_pair(lower_bound(k), upper_bound(k)));
        }

        void swap (map& src)
        {
            map tmp;
			tmp.copy_inner_data(*this);
			this->copy_inner_data(src);
			src.copy_inner_data(tmp);
			tmp.reset_data();
        }
        
        class value_compare
        {
            public:
                Compare comp;
                value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
                typedef bool result_type;
                typedef value_type first_argument_type;
                typedef value_type second_argument_type;
                bool operator() (const value_type& x, const value_type& y) const
                {
                    return comp(x.first, y.first);
                }
        };

        value_compare value_comp() const
        {
            return value_compare(keyCampare);
        }

        map &operator=(const map &rhs)
        {
            clear();
            _rbt.cpy(rhs._rbt.root);
            _size = rhs.size();
            return (*this);
        }

        mapped_type   &operator[](const key_type& key)
        {
            value_type to_find = ft::make_pair<const key_type, mapped_type>(key, mapped_type());
			RBT<value_type, Compare>* node = _rbt.search(to_find);
            if (!node)
            {
                _size++;
                node = _rbt.insert(to_find);
            }
            return node->value->second;
        }


        //----> Capacity :
		size_type max_size() const {return _rbt.get_allocator().max_size();}
		size_type size() const{return _size;}
		bool empty() const {return (size() == 0);} 
        
        // --> allocator getter
        allocator_type get_allocator() const { return _myAllocator;}
        //
        key_compare key_comp() const { return keyCampare; }

        // // --> Iterators
        iterator begin() {
            RBT<value_type, Compare>* node = _rbt.findMin(_rbt.root);
            if (!node) return iterator(NULL, &_rbt);
            return (iterator(node->value, &_rbt));
        }

        const_iterator begin() const {
            RBT<value_type, Compare>* node = _rbt.findMin(_rbt.root);
            if (!node) return iterator(NULL, &_rbt);
            return (iterator(node->value, &_rbt));
        }

		iterator end() {return iterator(NULL, &_rbt);}
        
        const_iterator end() const {return iterator(NULL, &_rbt);}
		
        reverse_iterator rbegin(){return reverse_iterator(iterator(NULL, &_rbt));}
		const_reverse_iterator rbegin() const {return reverse_iterator(iterator(NULL, &_rbt));}
		reverse_iterator rend(){return reverse_iterator(begin());}
        const_reverse_iterator rend() const{
            RBT<value_type, Compare>* node = _rbt.findMin(_rbt.root);
            if (!node) return reverse_iterator(iterator(NULL, &_rbt));
            return reverse_iterator(iterator(node->value, &_rbt));
        }

        void    clear()
        {
            _rbt.preOrder(_rbt.root);
            _rbt.root = NULL;
            _size = 0;
        }
    
        RBT<value_type, Compare>    _rbt;

    private:
        size_t  _size;
        size_t  _capacity;
        Alloc   _myAllocator;
        key_compare keyCampare;
    
        template <class InputIterator>
        void    insertIters(InputIterator first, InputIterator last)
        {
            while (first != last)
                insert(*first++);
        }

        void	copy_inner_data(const map& other)
		{
            _rbt.root = other._rbt.root;
			_myAllocator = other.get_allocator();
			_size = other.size();
			_capacity = other.max_size();
		}

        void	reset_data()
		{
            _rbt.root = NULL;
			_size = 0;
		}

        // Function to print binary tree in 2D
        // It does reverse inorder traversal
        void print2DUtil(RBT<value_type, Compare> *root, int space) const // todo remove
        {
            // Base case
            if (root == NULL)
                return;
        
            // Increase distance between levels
            space += 3;
        
            // Process right child first
            print2DUtil(root->right, space);
        
            // Print current node after space
            // count
            // std::cout<<std::endl;
            for (int i = 3; i < space; i++)
                std::cout<<" ";
            std::cout<<root->value->first;
            if (root->parent)
                std::cout <<"|"<< (root->parent->value->first);
            std::cout<<"\n";
        
            // Process left child
            print2DUtil(root->left, space);
        }
        // Wrapper over print2DUtil()
        void print2D() const
        {
            std::cout << "\n-----------------" << std::endl;
            // Pass initial space count as 0
            print2DUtil((_rbt.root), 1);
            std::cout << "-----------------\n" << std::endl;
        }

        RBT<value_type, Compare>    *findBound(RBT<value_type, Compare> *root, const key_type&k, RBT<value_type, Compare> *bound) const
        {
            if (!root) return bound;

            if (keyCampare(k, root->value->first) && (!bound ||  !keyCampare(bound->value->first, root->value->first)))
                bound = root;

            if (!keyCampare(k, root->value->first))
                return (findBound(root->right, k, bound));
            else
                return (findBound(root->left, k, bound));
            return bound;
        }

        RBT<value_type, Compare>    *findBound2(RBT<value_type, Compare> *root, const key_type&k, RBT<value_type, Compare> *bound) const
        {
            if (!root) return bound;
            if (!keyCampare(root->value->first, k) && (!bound || !keyCampare(bound->value->first, root->value->first)))
                bound = root;

            if (!keyCampare(k, root->value->first))
                return (findBound2(root->right, k, bound));
            else
                return (findBound2(root->left, k, bound));
            return bound;
        }
};

template <class Key, class T, class Compare, class Alloc>
  bool operator== ( const ft::map<Key,T,Compare,Alloc>& lhs,
                    const ft::map<Key,T,Compare,Alloc>& rhs )
{
    if (lhs.size() != rhs.size())
        return false;
    return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class Key, class T, class Compare, class Alloc>
  bool operator!= ( const ft::map<Key,T,Compare,Alloc>& lhs,
                    const ft::map<Key,T,Compare,Alloc>& rhs )
{
    return !(lhs == rhs);
}

template <class Key, class T, class Compare, class Alloc>
  bool operator<  ( const ft::map<Key,T,Compare,Alloc>& lhs,
                    const ft::map<Key,T,Compare,Alloc>& rhs )
{
    if (rhs == lhs)
		return false;
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class Key, class T, class Compare, class Alloc>
  bool operator<= ( const ft::map<Key,T,Compare,Alloc>& lhs,
                    const ft::map<Key,T,Compare,Alloc>& rhs )
{
	return ((lhs == rhs) || operator<(lhs, rhs));
}
template <class Key, class T, class Compare, class Alloc>
  bool operator>  ( const ft::map<Key,T,Compare,Alloc>& lhs,
                    const ft::map<Key,T,Compare,Alloc>& rhs )
{
	if (lhs == rhs)
		return false;
	return (!operator<(lhs, rhs));
}

template <class Key, class T, class Compare, class Alloc>
  bool operator>= ( const ft::map<Key,T,Compare,Alloc>& lhs,
                    const ft::map<Key,T,Compare,Alloc>& rhs )
{
	return (lhs == rhs || operator>(lhs, rhs));
}