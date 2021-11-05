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
            if (x->right)
                x->right->parent = y;
            x->right = y;
            y->left = T2;
            // update parent
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
            if (y->left)
                y->left->parent = x;
            y->left = x;
            x->right = T2;
            // update parents
            // std::cout << y->left->parent->value->first << std::endl;
            // std::cout << x->value->first << std::endl;
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
        void cpy(const RBT<value_type, Compare> *root)
        {
            if(!root)
                return ;
            cpy(root->left);
            if (root->value)
                insert(*(root->value));
                // std::cout << "val:" << *(root->value) << " ";
            cpy(root->right);
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

        RBT    *balanceTree(RBT* root, RBT* new_node)
        {
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
                    // std::cout << "am here 2 WITH VAL" << new_node->value->first << std::endl;
                    // std::cout << "am here 2 WITH ROOT" << root->value->first << std::endl;
                    return rotateLeft(root);
                }
                // right left
                else
                {
                    // std::cout << "am here" << std::endl;
                    root->right = rotateRight(root->right);
                    return (rotateLeft(root));
                }
            }
            // heavy left side
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
            return balanceTree(root, new_node);
        }

        RBT     *insert(const value_type& val)
        {
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

        operator RBT<const value_type, Compare> () const 
        {
            return RBT<const value_type, Compare>();
        }

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

        RBT *findMax(RBT *root) const
        {
            RBT*   small = root;
            while (small->right)
                small = small->right;
            return (small);
        }

        RBT<value_type, Compare> *prev()
        {
            RBT<value_type, Compare>* curr = this;
            RBT<value_type, Compare>* p;
            if (root == NULL)
                return NULL;
            //If the current node has a null right child,
            if (left == NULL)
            {
                p = parent;
                //move up the tree until we have moved over a left child link
                while (p && p->left && curr->value->first == p->left->value->first) // right?
                {
                    curr = p;
                    p = p->parent;
                }
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
            RBT<value_type, Compare>* curr = this;
            RBT<value_type, Compare>* p;
            if (curr == NULL)
                return NULL;
            //If the current node has a null right child,
            if (right == NULL)
            {
                p = parent;
                //move up the tree until we have moved over a left child link
                while (p && p->right && curr->value->first == p->right->value->first)
                {
                    curr = p;
                    p = p->parent;
                }
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
                            if (node->parent->right == node)
                                node->parent->right = NULL;
                            else
                                node->parent->left = NULL;
                        }
                        tmp = node;
                        // std::cout << "has no childs: " << node->value->first << std::endl;
                        node = NULL;
                    }
                    // else one child
                    // copy child content to the node to be deleted
                    else
                    {
                        RBT* nodeParent = node->parent;
                        *node = *tmp;
                        node->parent = nodeParent;
                    }
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
                    // std::cout << "was here 2" << *(min->value);
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
            if (node == NULL)
                return node;
                    // std::cout << "node: begin()" << *(node->value);
            return balanceTree(root, node);
        }

        size_t    erase(const value_type& val)
        {
            bool is_found;
            root = del(root, val, is_found);
            return (is_found ? 1 : 0);
        }

        std::allocator<T> get_allocator() const { return _myAllocater;}
};