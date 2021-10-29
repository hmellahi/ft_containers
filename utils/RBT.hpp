#pragma once
#include <memory>
#include "pair.hpp"
#include "debug.hpp"
#include <stdlib.h>  


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
        int     height;
        RBT  *root;
        RBT  *parent;
        std::allocator<self_type> _myAllocater;
        std::allocator<value_type> _valueAllocator;
        Compare key_compare;

        int     getHeight(RBT *node) const
        {
            if (node == NULL) return 0;
            return node->height;
        }
        
        int     getBalance(RBT *node) const
        {
            return (getHeight(node->left) - getHeight(node->right));
        }

        RBT*   rotateRight(RBT* y)
        {
            RBT* x = y->left;
            RBT* T2 = x->right;

            // do rotate
            x->right = y;
            y->left = T2;
            x->parent = y->parent;
            y->parent = x;
            // recalculate x and y heights
            x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
            y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

            // return new tree root
            return (x);
        }

        RBT*   rotateLeft(RBT* x)
        {
            RBT *y = x->right;
            // if (!y)
                // exit(0);
            RBT *T2 = y->left;

            // Perform rotation
            y->left = x;
            x->right = T2;
            // update parents
            y->parent = x->parent;
            x->parent = y;

            // Update heights
            x->height = std::max(getHeight(x->left),
                            getHeight(x->right)) + 1;
            y->height = std::max(getHeight(y->left),
                            getHeight(y->right)) + 1;

            // Return new root
            return y;
        }

    public:
        RBT()
        {
            right = left = root = parent = NULL;
            value = NULL;
            height = 0;
        }
        RBT(const value_type& val)
        {
            value = _valueAllocator.allocate(1);
            _valueAllocator.construct(value, val);
            right = left = NULL;
            height = 1;
            root = this;
            parent = NULL;
        }
        RBT(RBT<value_type, Compare> *root)
        {
            right = left = parent = NULL;
            height = root->height;
            this->root = root;
            // value = new ;
        }
        void preOrder(RBT *root)
        {
            if(!root)
                return ;
            preOrder(root->left);
            // if (root->value)
                // std::cout << "val:" << *(root->value) << " ";
            _valueAllocator.deallocate(root->value, 1);
            preOrder(root->right);
            _myAllocater.deallocate(root, 1);
            root = NULL;
        }
        ~RBT()
        {
            // if (value)
                // _valueAllocator.deallocate(value, 1);
                // std::cout << "value" << *value << std::endl;
                // _myAllocater.deallocate(value, 1);
            // traverseInOrder();
            // traverse(); todo : fix double free
        }
        RBT &operator=(const RBT &rhs)
        {
            root = rhs.root;
            left = rhs.left;
            right = rhs.right;
            parent = rhs.parent;
            if (value)
                _valueAllocator.deallocate(value, 1);
            value = _valueAllocator.allocate(1);
            _valueAllocator.construct(value, *(rhs.value));
            height = rhs.height;
            return (*this);
        }
        void   destroy(RBT<value_type, Compare> *node)
        {
            _myAllocater.destroy(node); // useless
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
            if (!key_compare(new_node->value->first, root->value->first))
            {
                root->right = insert_helper(root->right, new_node);
                root->right->parent = root;
            }
            else if (key_compare(new_node->value->first, root->value->first))
            {
                root->left = insert_helper(root->left, new_node);
                root->left->parent = root;
            }

            // update current node height
            root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;
            // calculate node balance
            int balance = getBalance(root);

            // heavy right side
            if (balance < -1)
            {
                // right right
                if (!key_compare(new_node->value->first, root->right->value->first))
                {
                    return rotateLeft(root);
                }
                // right left
                else
                {
                    root->right = rotateRight(root->right);
                    return (rotateLeft(root));
                }

            }
            // heavy left side
            // std::cout << "balance: " << new_node->value->first << "|" << root->left->value->first << std::endl;
            if (balance > 1)
            {
                // left left
                if (key_compare(new_node->value->first, root->left->value->first))
                    return rotateRight(root);
                // left right
                else
                {
                    root->left = rotateLeft(root->left);
                    return (rotateRight(root));
                }
            }
            return root;
        }
        // void    traverse_helper(RBT *root)
        // {
        //     if (!root) return ;
        //     traverse_helper(root->left);
        //     // std::cout << root->value << std::endl;
        //     // _myAllocater.deallocate(root, 1);
        //     // func(root);
        //     // _myAllocater.destroy(root);
        //     RBT* tmp = root->right;
        //     _myAllocater.deallocate(root, 1); 
        //     traverse_helper(tmp);
        //     tmp = NULL;
        // }
        // void    traverse()
        // {
        //     traverse_helper(root);
        //     root = NULL;
        // }
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
            if (!key_compare(val.first, root->value->first))
                return (find(root->right, val));
            else
                return (find(root->left, val));
        }
        operator RBT<const value_type, Compare> () const { return RBT<const value_type, Compare>(); }
        RBT<value_type, Compare> *search(const value_type& val) const
        {
            // std::cout << "val:" << val.first << std::endl;
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
                // curr = new RBT(*value);
                curr = this;
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
                curr = this;
                // std::cout << "curr: " << curr->value->first << std::endl;
                // std::cout << "parent: " << p->value->first << std::endl;
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

        RBT*    del(RBT* node, const value_type& val, bool &is_found)
        {
            if (!node) return node;
            if (val.first == node->value->first)
            {
                is_found = true;
                // in case if node has one child
                if (!node->right || !node->left)
                {
                    RBT* tmp = node->right ? node->right : node->left;
                    // in case if node to be deleted has no childs

                    if (!tmp)
                    {
                        // std::cout << node->value->first << std::endl;
                        if (node->parent)
                        {
                            if (node->parent->right == node->right)
                                node->parent->right = NULL;
                            else
                                node->parent->left = NULL;
                        }
                        tmp = node;
                        std::cout << "has no childs: " << node->value->first << std::endl;
                        node = NULL;
                    }
                    // else one child
                    // copy child content to the node to be deleted
                    else
                    {
                        if (node->parent)
                        {
                            if (node->parent->right == node->right)
                                node->parent->right = tmp;
                            else
                                node->parent->left = tmp;
                        }
                        // RBT* tmp2 = node;
                        *node = *tmp;
                        // node = tmp;
                        // tmp = tmp2;
                        // std::cout << "min: begin2()" << *(node->value);
                    }
                    // free tmp [todo]
                    // _myAllocater.destroy(tmp);
                    _valueAllocator.deallocate(tmp->value, 1);
                    _myAllocater.deallocate(tmp, 1);
                }
                // else has two childs
                else
                {
                    // find inorder successor
                    RBT* min = findMin(node->right);
                    // copy min values
                    node->value = min->value;
                    std::cout << "was here 2" << *(min->value);
                    // delete min [todo]
                    node->right = del(node->right, *(min->value), is_found);
                }
            }
            else if (!key_compare(val.first, node->value->first))
                node->right = del(node->right, val, is_found);
            else
                node->left = del(node->left, val, is_found);

            // If the tree had only one node
            // then return
            if (node    == NULL)
                return node;
                    // std::cout << "node: begin()" << *(node->value);
            // update current node height
            node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
            // calculate node balance
            int balance = getBalance(node);

            // heavy right side
            if (balance < -1)
            {
                // right right
                if (!key_compare(node->value->first, root->right->value->first))
                {
                    // node->pa
                    return rotateLeft(node);
                }
                // right left
                else
                {
                    node->right = rotateRight(node->right);
                    return (rotateLeft(node));
                }

            }
            // heavy left side
            if (balance > 1)
            {
                // left left
                if (key_compare(node->value->first, root->left->value->first))
                    return rotateRight(node);
                // left right
                else
                {
                    node->left = rotateLeft(node->left);
                    return (rotateRight(node));
                }

            }
            return node;
        }

        size_t    erase(const value_type& val)
        {
            bool is_found;
            root = del(root, val, is_found);
            return (is_found ? 1 : 0);
        }

        std::allocator<T> get_allocator() const { return _myAllocater;}
};