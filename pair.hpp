#pragma once
#include <iostream>
template<typename A, typename B>
class pair
{
    public:
        A first;
        B second;

        typedef pair self_type;
        typedef A first_type;
        typedef B second_type;
        
        pair()
        {
            this->first = first_type();
            this->second = second_type();
        }
        pair (const first_type& a, const second_type& b)
        {
            this->first = first;
            this->second = second;
        }
        // template<class U, class V>
        // pair (const pair<U,V>& pr)
        // {
        //     *this = pr;
        // }
        ~pair(){}
        pair(const pair& src) {*this = src;}
        pair& operator= (const pair& pr)
        {
            this->first = pr.first;
            this->second = pr.second;
            return (*this);
        }
};

template<typename A, typename B>
std::ostream& operator<<(std::ostream& is, pair<A, B>& obj)
{
    is << obj.first << "|" << obj.second << std::endl;
    return is;
}

template <class T1,class T2>
pair<T1,T2> make_pair (T1 x, T2 y)
{
  return (pair<T1,T2>(x,y));
}

template <class T1, class T2>
  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first==rhs.first && lhs.second==rhs.second; }

template <class T1, class T2>
  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs==rhs); }

template <class T1, class T2>
  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

template <class T1, class T2>
  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(rhs<lhs); }

template <class T1, class T2>
  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return rhs<lhs; }

template <class T1, class T2>
  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs<rhs); }