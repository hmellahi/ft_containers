#pragma once
#include "pair.hpp"


template<typename T,
        class Compare = std::less<T> 
        >
class AVL
{
    public: // private bruh
        typedef T value_type;
        typedef AVL self_type;

        value_type      *value;
        AVL  *right;
        AVL  *left;
        int     height;
        AVL  *root;
        AVL  *parent;
        std::allocator<self_type> _myAllocater;
        std::allocator<value_type> _valueAllocator;
        Compare key_compare;

        int     getHeight(AVL *node) const
        {
            if (node == NULL) return 0;
            return node->height;
        }
        
        int     getBalance(AVL *node) const
        {
            return (getHeight(node->left) - getHeight(node->right));
        }

        AVL*   rotateRight(AVL* y)
        {
            AVL* x = y->left;
            AVL* T2 = x->right;

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

        AVL*   rotateLeft(AVL* x)
        {
            AVL *y = x->right;
            // if (!y)
                // exit(0);
            AVL *T2 = y->left;

            // Perform rotation
            if (y->left)
                y->left->parent = x;
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
        AVL()
        {
            right = left = root = parent = NULL;
            value = NULL;
            height = 0;
        }
        AVL(const value_type& val)
        {
            value = _valueAllocator.allocate(1);
            _valueAllocator.construct(value, val);
            right = left = NULL;
            height = 1;
            root = this;
            parent = NULL;
        }
        AVL(AVL<value_type, Compare> *root)
        {
            right = left = parent = NULL;
            height = root->height;
            this->root = root;
        }
        void preOrder(AVL *root)
        {
            if(!root)
                return ;
            preOrder(root->left);
            _valueAllocator.deallocate(root->value, 1);
            preOrder(root->right);
            _myAllocater.deallocate(root, 1);
            root = NULL;
        }
        bool is_found;
        
        AVL*    iter(AVL* node, value_type min, value_type max, bool isLast, int &n)
        {
            if (!node) return NULL;

            node->left = iter(node->left, min, max, isLast, n);
            node->right = iter(node->right, min, max, isLast, n);
            
            if (node->value->first >= min.first && (isLast || max.first > node->value->first))
            {
                node = del(node, *(node->value), is_found);
                n++;
            }
            return node; 
        }

        void cpy(const AVL<value_type, Compare> *node)
        {
            if(!node)
                return ;
            cpy(node->left);
            if (node->value)
                insert(*(node->value));
            cpy(node->right);
        }
        ~AVL()
        {
        }
        AVL &operator=(const AVL &rhs)
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
        void   destroy(AVL<value_type, Compare> *node)
        {
            _myAllocater.destroy(node); // useless
            _myAllocater.deallocate(node, 1);
        }

        AVL    *balanceTree(AVL* root, const value_type& key)
        {
            // update current node height
            root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;
            // calculate node balance
            int balance = getBalance(root);

            // heavy right side
            if (balance < -1)
            {
                // right right
                if (!key_compare(key.first, root->right->value->first))
                    return rotateLeft(root);
                // right left
                else
                {
                    root->right = rotateRight(root->right);
                    return (rotateLeft(root));
                }
            }
            // heavy left side
            if (balance > 1)
            {
                // left left
                if (key_compare(key.first, root->left->value->first))
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
        AVL    *insert_helper(AVL *root, AVL* new_node)
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
            return balanceTree(root, *(new_node->value));
        }

        AVL     *insert(const value_type& val)
        {
            AVL*    new_node = _myAllocater.allocate(1);
            _myAllocater.construct(new_node, val);
            this->root = insert_helper(root, new_node);
            return (new_node);
        }

        AVL     *find(AVL* root, const value_type& val) const
        {
            if (!root || root->value->first == val.first)
                return root;
            if (!key_compare(val.first, root->value->first))
                return (find(root->right, val));
            else
                return (find(root->left, val));
        }

        operator AVL<const value_type, Compare> () const 
        {
            return AVL<const value_type, Compare>();
        }

        AVL<value_type, Compare> *search(const value_type& val) const
        {
            return (find(this->root, val));
        }

        AVL *findMin(AVL *root) const
        {
            if (!root)  
                return NULL;
            AVL*   small = root;
            while (small->left)
                small = small->left;
            return (small);
        }

        AVL *findMax(AVL *root) const
        {
            AVL*   small = root;
            while (small->right)
                small = small->right;
            return (small);
        }

        AVL<value_type, Compare> *prev()
        {
            AVL<value_type, Compare>* curr = this;
            AVL<value_type, Compare>* p;
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

        AVL<value_type, Compare> *next()
        {
            AVL<value_type, Compare>* curr = this;
            AVL<value_type, Compare>* p;
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

        AVL*    del(AVL* node, const value_type& val, bool &is_found)
        {
            if (!node) return node;
            if (val.first == node->value->first)
            {
                is_found = true;
                // in case if node has one child
                
                if (!node->right || !node->left)
                {
                    AVL* tmp = node->right ? node->right : node->left;
                    // in case if node to be deleted has no childs
                    if (!tmp)
                    {
                        tmp = node;
                        node = NULL;
                    }
                    // else one child
                    // copy child content to the node to be deleted
                    else
                    {
                        AVL* nodeParent = node->parent;
                        *node = *tmp;
                        node->parent = nodeParent;
                    }
                    _valueAllocator.deallocate(tmp->value, 1);
                    _myAllocater.deallocate(tmp, 1);
                }
                // else has two childs
                else
                {
                    // find inorder successor
                    AVL* minum = findMin(node->right);
                    // copy min values
                    value_type *tmp = node->value;
                    node->value = minum->value;
                    minum->value = tmp;
                    _valueAllocator.construct(minum->value, *(node->value));
                    node->right = del(node->right, *(node->value), is_found);
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
            return balanceTree(node, val);
        }

        bool    erase(const value_type& val)
        {
            bool is_found;
            root = del(root, val, is_found);
            return (is_found);
        }

        std::allocator<T> get_allocator() const { return _myAllocater;}
};