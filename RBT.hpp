#pragma once
#include <memory>
// #include "pair.hpp"
#include "debug.hpp"

template<typename T
        // class Compare = std::less<T>                     // map::key_compare // todo
        >
class RBT
{
    public:
        typedef T value_type;
        typedef RBT self_type;
        value_type      value;
        RBT  *right;
        RBT  *left;
        RBT  *root;
        RBT  *parent;
        std::allocator<self_type> _myAllocater;

    public:
        RBT()
        {
            right = left = root = parent = NULL;
        }
        RBT(const value_type& val)
        {
            value = val;
            right = left = NULL;
            root = this;
            parent = NULL;
        }
        ~RBT()
        {
            // traverseInOrder();
            // traverse(); todo : fix double free
        }
        // RBT(const RBT& src)
        // {

        // }
        void   destroy(RBT<value_type> *node)
        {
            _myAllocater.destroy(node);
            _myAllocater.deallocate(node, 1);
        }

        // void    traverseInOrder()//(void (*func)(RBT<value_type> *))
        // {
        //     // for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        //         // func(it);
        //     if (!root)
        //         return ;
        //     // RBT<value_type> *curr =  root->search(root->findMin(root));
        //     // RBT<value_type> *tmp;
        //     // // curr = curr->next();
        //     // while (curr != NULL)
        //     // {
        //     //     tmp = curr->next();
        //     //     std::cout << curr->value.first << std::endl;
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
            if (new_node->value > root->value)
            {
                root->right = insert_helper(root->right, new_node);
                root->right->parent = root;
            }
            else if (new_node->value < root->value)
            {
                root->left = insert_helper(root->left, new_node);
                root->left->parent = root;
            }
            return root;
        }
        // void    print_helper(RBT *root, void (*func)(RBT<value_type> *))
        // {
        //     if (!root) return ;
        //     print_helper(root->left);
        //     // std::cout << root->value << std::endl;
        //     // _myAllocater.deallocate(root, 1);
        //     func(root);
        //     print_helper(root->right);
        // }
        // void    traverse(void (*RBT)(RBT<value_type> *))
        // {
        // //    traverse_helper(root, func);
        // }
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
            if (!root || root->value.first == val.first)
                return root;
            if (val.first > root->value.first)
                return (find(root->right, val));
            else
                return (find(root->left, val));
        }
        RBT *search(const value_type& val) const
        {
            RBT*    node = find(this->root, val);
            return (node);
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
        value_type  findMax(RBT *root) const
        {
            RBT*   small = root;
            while (small->right)
                small = small->right;
            return (small ? small->value : value_type());
        }
        RBT<value_type> *prev()
        {
            RBT<value_type>* curr;
            RBT<value_type>* p;
            if (root == NULL)
                return NULL;
            //If the current node has a null right child,
            if (left == NULL)
            {
                p = parent;
                curr = new RBT(value);
                // curr = _myAllocater.allocate(1); // todo : leaks | wtf bruh??? no need to allocate
                // _myAllocater.construct(curr, value);
                // std::cout << curr->value.first << " curr >> " << curr->value.second << '\n';
                //move up the tree until we have moved over a left child link
                while (p && curr->value == p->left->value)
                {
                // std::cout << p->value.first << "inside >> " << p->value.second << '\n';
                    curr = p;
                    p = p->parent;
                }
                // if (p)
                    // std::cout << p->value.first << "parent >> " << p->value.second << '\n';
                // std::cout << p->right->value.first << "parent >> " << p->right->value.second << '\n';
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
        RBT<value_type> *next()
        {
            RBT<value_type>* curr;
            RBT<value_type>* p;
            if (root == NULL)
                return NULL;
            //If the current node has a null right child,
            if (right == NULL)
            {
                p = parent;
                curr = new RBT(value);
                // curr = _myAllocater.allocate(1); // todo : leaks | wtf bruh??? no need to allocate
                // _myAllocater.construct(curr, value);
                // std::cout << curr->value.first << " curr >> " << curr->value.second << '\n';
                //move up the tree until we have moved over a left child link
                while (p && curr->value == p->right->value)
                {
                // std::cout << p->value.first << "inside >> " << p->value.second << '\n';
                    curr = p;
                    p = p->parent;
                }
                // if (p)
                    // std::cout << p->value.first << "parent >> " << p->value.second << '\n';
                // std::cout << p->right->value.first << "parent >> " << p->right->value.second << '\n';
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

        int    erase(const value_type& val)
        {
            RBT<value_type>* node = root->search(val);
            bool flag = false;
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
                // find min value in right subtree
                RBT *min = findMin(node->right);
                // copy min content
                node->value = min->value;
                _myAllocater.destroy(min);
                _myAllocater.deallocate(min, 1);
                flag = true;
            }
            else if (node->parent && node->parent->right == node)
                node->parent->right = node->right;
            else if (node->parent && node->parent->left == node)
                node->parent->left = node->left;
            // free node
            if (!flag)
            {
                _myAllocater.destroy(node);
                _myAllocater.deallocate(node, 1);
            }
            // (node->parent->value).second = 42;
            return 1;
        }
};