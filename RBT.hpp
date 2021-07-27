#pragma once
#include <memory>
// #include "pair.hpp"

template<typename T>
class RBT
{
    private:
        typedef T value_type;
        typedef RBT self_type;
        bool _isRed;
        value_type      value;
        RBT  *right;
        RBT  *left;
        RBT  *root;

    public:
        RBT()
        {
            right = left = root = NULL;
        }
        RBT(const value_type& val)
        {
            value = val;
            right = left = NULL;
            _isRed = true;
        }
        ~RBT(){}
        RBT(const RBT& src);
        RBT &operator=(RBT const &rhs)
        {
            return (*this);
        }
        RBT    *insert_helper(RBT *root, RBT* new_node)
        {
            if (!root)
                return new_node;
            if (new_node->value > root->value){
                root->right = insert_helper(root->right, new_node);
            }
            else if (new_node->value < root->value){
                root->left = insert_helper(root->left, new_node);
            }
            return root;
        }
        void    print_helper(RBT *root)
        {
            if (!root) return ;
            print_helper(root->left);
            std::cout << root->value << std::endl;
            print_helper(root->right);
        }
        void    print()
        {
           print_helper(root);
        }
        RBT     *insert(const value_type& val)
        {
            RBT*    new_node = new RBT(val);
            return (root = insert_helper(root, new_node));
        }
        RBT     *find(RBT* root, const value_type& val)
        {
            if (!root || root->value == val)
                return root;
            if (val > root->value)
                return (find(root->right, val));
            // else if (val < root->value)
            else
                return (find(root->left, val));
            // return root;
        }
        value_type *search(const value_type& val)
        {
            // const value_type& ret = find(root, val);
            RBT*    node = find(root, val);
            // std::string vv = node->value;
            return (node);
        }
};