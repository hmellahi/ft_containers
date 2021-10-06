#pragma once
#include <memory>
#include "pair.hpp"
#include "debug.hpp"


// template <class T1, class T2>
//   bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
// { return rhs<lhs; }

template<typename T,
        class Compare = std::less<T>                     // map::key_compare // todo    
        >
class RBT
{
    public: // private bruh
        typedef T value_type;
        typedef RBT self_type;

        value_type      *value;
        RBT  *right;
        RBT  *left;
        RBT  *root;
        RBT  *parent;
        std::allocator<self_type> _myAllocater;
        Compare key_compare;

    public:
        RBT()
        {
            right = left = root = parent = NULL;
        }
        RBT(const value_type& val)
        :value(new value_type(val))
        {
            right = left = NULL;
            root = this;
            parent = NULL;
        }
        RBT(RBT<value_type, Compare> *root)
        {
            right = left = parent = NULL;
            this->root = root;
            // value = new ;
        }
        ~RBT()
        {
            // traverseInOrder();
            // traverse(); todo : fix double free
        }
        RBT &operator=(const RBT &rhs)
        {
            root = rhs.root;
            left = rhs.left;
            right = rhs.right;
            parent = rhs.parent;
            value = rhs.value;   
            return (*this);
        }
        void   destroy(RBT<value_type, Compare> *node)
        {
            _myAllocater.destroy(node);
            _myAllocater.deallocate(node, 1);
        }

        // void    traverseInOrder()//(void (*func)(RBT<value_type, Compare> *))
        // {
        //     // for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        //         // func(it);
        //     if (!root)
        //         return ;
        //     // RBT<value_type, Compare> *curr =  root->search(root->findMin(root));
        //     // RBT<value_type, Compare> *tmp;
        //     // // curr = curr->next();
        //     // while (curr != NULL)
        //     // {
        //     //     tmp = curr->next();
        //     //     std::cout << curr->value->first << std::endl;
        //     //     _myAllocater.deallocate(curr, 1);
        //     //     curr = tmp;
        //     // }
        //     // exit(0);
        // }
        // RBT &operator=(RBT const &rhs)
        // {
        //     return (*this);
        // }
        RBT    *insert_helper(RBT *root, RBT* new_node)
        {
            if (!root)
                return new_node;
            // if (new_node->value->first > root->value->first)
            if (!Compare{}(new_node->value->first, root->value->first))
            {
                root->right = insert_helper(root->right, new_node);
                root->right->parent = root;
            }
            // if (new_node->value->first < root->value->first)
            else if (Compare{}(new_node->value->first, root->value->first))
            {
                root->left = insert_helper(root->left, new_node);
                root->left->parent = root;
            }
            return root;
        }
        void    traverse_helper(RBT *root)
        {
            if (!root) return ;
            traverse_helper(root->left);
            // std::cout << root->value << std::endl;
            // _myAllocater.deallocate(root, 1);
            // func(root);
            // _myAllocater.destroy(root);
            RBT* tmp = root->right;
            _myAllocater.deallocate(root, 1);
            traverse_helper(tmp);
            tmp = NULL;
        }
        void    traverse()
        {
            traverse_helper(root);
            root = NULL;
        }
        RBT     *insert(const value_type& val)
        {
            // RBT*    new_node = new RBT(val);
            RBT*    new_node = _myAllocater.allocate(1);
            _myAllocater.construct(new_node, val);
            this->root = insert_helper(root, new_node);
            return (new_node);
        }
        RBT     *find(RBT* root, const value_type& val) const
        {
            if (!root || root->value->first == val.first)
                return root;
            // if (val.first > root->value->first)
            if (!Compare{}(val.first, root->value->first))
                return (find(root->right, val));
            else
                return (find(root->left, val));
        }
        operator RBT<const value_type, Compare> () const { return RBT<const value_type, Compare>(); }
        RBT<value_type, Compare> *search(const value_type& val) const
        {
            return (find(this->root, val));
        }
        RBT *findMin(RBT *root) const
        {
            if (!root)
                return NULL;
            RBT*   small = root;
            while (small->left)
                small = small->left;
            return (small);
        }
        value_type  *findMax(RBT *root) const
        {
            RBT*   small = root;
            while (small->right)
                small = small->right;
            return (small->value);
        }
        RBT<value_type, Compare> *prev()
        {
            RBT<value_type, Compare>* curr;
            RBT<value_type, Compare>* p;
            if (root == NULL)
                return NULL;
            //If the current node has a null right child,
            if (left == NULL)
            {
                p = parent;
                curr = new RBT(*value);
                // curr = _myAllocater.allocate(1); // todo : leaks | wtf bruh??? no need to allocate
                // _myAllocater.construct(curr, value);
                // std::cout << curr->value->first << " curr >> " << curr->value->second << '\n';
                //move up the tree until we have moved over a left child link
                while (p && curr == p->left) // right?
                {
                // std::cout << p->value->first << "inside >> " << p->value->second << '\n';
                    curr = p;
                    p = p->parent;
                }
                // if (p)
                    // std::cout << p->value->first << "parent >> " << p->value->second << '\n';
                // std::cout << p->right->value->first << "parent >> " << p->right->value->second << '\n';
                // INFO(curr->value->first);
                curr = p;
            }   
            //If the current node has a non-null right child,
            else
            {
                // Take a step down to the right
                curr = left;
                //Then run down to the left as far as possible
                while (curr->right)
                    curr = curr->right;
            }
            return (curr);
        }
        RBT<value_type, Compare> *next()
        {
            RBT<value_type, Compare>* curr;
            RBT<value_type, Compare>* p;
            if (root == NULL)
                return NULL;
            //If the current node has a null right child,
            if (right == NULL)
            {
                p = parent;
                // curr = new RBT(value);
                curr = _myAllocater.allocate(1); // todo : leaks | wtf bruh??? no need to allocate
                _myAllocater.construct(curr, *value);
                // std::cout << curr->value->first << " curr >> " << curr->value->second << '\n';
                //move up the tree until we have moved over a left child link
                while (p && p->right && curr->value->first == p->right->value->first)
                {
                    curr = p;
                    p = p->parent;
                }
                // if (p)
                    // std::cout << p->value->first << "parent >> " << p->value->second << '\n';
                // std::cout << p->right->value->first << "parent >> " << p->right->value->second << '\n';
                // INFO(curr->value->first);
                curr = p;
            }   
            //If the current node has a non-null right child,
            else
            {
                // Take a step down to the right
                curr = right;
                //Then run down to the left as far as possible
                while (curr->left)
                    curr = curr->left;
            }
            return (curr);
        }

        size_t    erase(const value_type& val)
        {
            if (!root) return 0;
            RBT<value_type, Compare>* node = root->search(val);
            RBT<value_type, Compare>* garbage = node;
            if (!node)
                return 0;
            // if (!node->right)
            // {
            //     node->parent
            // }
            //     // node->parent = node->left;
            // else if (!node->left)
            //     node->parent = node->right;
            if (node->left && node->right)
            {
                // Find inorder successor of the node
                RBT *min = findMin(node->right);
                // copy min content
                node->value = min->value;
                // special case
                // incase that min is 
                if (min == node->right)
                {
                    garbage = node->right;
                    node->right = garbage->right;
                    if (garbage->right)
                        garbage->right->parent = node;
                }
                // remove min
                if (min->parent && min->parent->right == min)
                    min->parent->right = NULL;
                else if (min->parent && min->parent->left == min)
                    min->parent->left = NULL;
                // deallocate min
                garbage = min;
            }
            else if (node->right)
            {
                garbage = node->right;
                node->value = garbage->value;
                node->right = garbage->right;
                node->left = garbage->left;
                if (garbage->right)
                    garbage->right->parent = node;
                if (garbage->left)
                    garbage->left->parent = node;
            }
            else if (node->left)
            {
                garbage = node->left;
                node->value = garbage->value;
                node->right = garbage->right;
                node->left = garbage->left;
                if (garbage->right)
                    garbage->right->parent = node;
                if (garbage->left)
                    garbage->left->parent = node;
            }
            else
            {
				if (node->parent && node->parent->right == node)
                    node->parent->right = NULL;
                else if (node->parent && node->parent->left == node)
                    node->parent->left = NULL;
                else
                {
                    // _myAllocater.destroy(garbage);
                    // _myAllocater.deallocate(garbage, 1); // leaks
                    root = NULL;
                }
            }
            // todo leaks
            // free node
            // if (!flag)
            // {
                // _myAllocater.destroy(garbage);
                // _myAllocater.deallocate(garbage, 1);
            // }
            // (node->parent->value).second = 42;
            return 1;
        }

        std::allocator<T> get_allocator() const { return _myAllocater;}
};