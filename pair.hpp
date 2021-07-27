#pragma once
#include <iostream>
template<typename A, typename B>
class pair
{
    public:
        typedef pair self_type;
        A first;
        B last;
        pair()
        {
        }
        pair(A& first, B& last)
        {
            this->first = first;
            this->last = last;
        }
        ~pair(){}
        pair(const pair& src);
        pair &operator=(pair const &rhs)
        {
            return (*this);
        }
        bool operator>(const self_type& rhs) const{ return first > rhs.first; }
        bool operator==(const self_type& rhs) const{ return first == rhs.first; }
        bool operator=(const self_type& rhs) const{ return first = rhs.first; }
        // friend std::ostream& operator<<(std::ostream& is, pair<A, B>& obj);
};

template<typename A, typename B>
std::ostream& operator<<(std::ostream& is, pair<A, B>& obj)
{
    is << obj.first << "|" << obj.last << std::endl;
    return is;
}

template<typename A, typename B>
pair<A, B> *make_pair(A first, B last)
{
    return (new pair<A, B>(first, last));
}
