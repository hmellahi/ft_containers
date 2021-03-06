#pragma once
#include <iostream>

namespace ft
{
    template<typename A, typename B>
    class pair;
}

template<typename A, typename B>
class ft::pair
{
    public:
        A first;
        B second;

        typedef pair self_type;
        typedef A first_type;
        typedef B second_type;
        
        pair()
        : first(first_type())
        {
            this->second = second_type();
        }
        
        pair (const first_type& a, const second_type& b)
        : first(a), second(b)
        {
        }

        ~pair(){}
        template<typename U, typename V>
        pair(const pair<U, V>& src)
        :first(src.first), second(src.second)
        {
        }
        template<typename U, typename V>
        pair<A, B>& operator= (const ft::pair<U, V>& pr)
        {
            this->first = pr.first;
            this->second = pr.second;
            return (*this);
        }
};

// template<typename A, typename B>
// std::ostream& operator<<(std::ostream& is, ft::pair<A, B>& obj)
// {
//     is << obj.first << "|" << obj.second << std::endl;
//     return is;
// }

namespace  ft
{
  template <class T1,class T2>
  ft::pair<T1,T2> make_pair (T1 x, T2 y)
  {
    return (ft::pair<T1,T2>(x,y));
  }
} 

template <class T1, class T2>
  bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return lhs.first==rhs.first && lhs.second==rhs.second; }

template <class T1, class T2>
  bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return !(lhs==rhs); }

template <class T1, class T2>
  bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

template <class T1, class T2>
  bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return !(rhs<lhs); }

template <class T1, class T2>
  bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return rhs<lhs; }

template <class T1, class T2>
  bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{ return !(lhs<rhs); }