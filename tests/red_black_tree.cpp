#include <map>
#include "map.hpp"
#include <vector>
#include <sys/time.h>
// #include <iostream>
// #include "pair.hpp"

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}
#define NAMESPACE ft
#include <map>

#include <vector>
#include <iostream>
#include <iterator>
#include <utility>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <random>
#include "vector.hpp"

using namespace std;
int main()
{
     /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            // test 1: test with capacity greater than or equal the size + n (reallocation must'nt happen)
            /*------------------ std::vectors ---------------------*/
            {
                std::vector<std::string> v1(1e6, "string2");
                v1.reserve(1e6 + 200);
                start = get_time();
                v1.insert(v1.begin() + 1e5, 100, "string1");
                end = get_time();
                diff = end - start;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string> ft_v1(1e6, "string2");
                ft_v1.reserve(1e6 + 200);
                ft_v1.insert(ft_v1.begin() + 1e5, 100, "string1");
            }
            /*--------------------------------------------------------------------------------------*/
            // test 2: test with capacity lesser than the size + n (reallocation must happen)
            /*------------------ std::vectors ---------------------*/
            {
                std::vector<std::string> v1(1e6, "string2");
                start = get_time();
                v1.insert(v1.begin() + 1e5, 200, "string1");
                end = get_time();
                diff = end - start;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string> ft_v1(1e6, "string2");
                ualarm(diff * 1e3, 0);
                ft_v1.insert(ft_v1.begin() + 1e5, 200, "string1");
                ualarm(0, 0);
            }
            /*--------------------------------------------------------------------------------------*/
        }
        /*
         * strings to store the resutls
         */
        std::string str, ft_str;
        /*
         * var to store the size and the capacity
         */
        ft::vector<std::string>::size_type s, ft_s;
        ft::vector<std::string>::size_type c, ft_c;
        /*
         * bool to store the comparison
         */
        bool cond;

        /*------------------------------- test 1: empty vector ----------------------------------------*/
        // insert at the begin
        {
            std::vector<std::string> v;
            ft::vector<std::string> ft_v;
            v.insert(v.begin(), 100, "hello");
            ft_v.insert(ft_v.begin(), 100, "hello");
            ft_v.begin()->length();

            s = v.size();
            ft_s = ft_v.size();
            // std::cout << s << std::endl;
            // std::cout << ft_s << std::endl;
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = ((str == ft_str) && (s == ft_s) && (c == ft_c));
            if (!cond)
                std::cout << "yyy";
        }
        // insert at the end
        {
            std::vector<std::string> v;
            ft::vector<std::string> ft_v;

            v.insert(v.end(), "hello");
            ft_v.insert(ft_v.end(), "hello");
            ft_v.begin()->length();

            str.clear();
            ft_str.clear();

            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
            if (!cond)
                std::cout << "yyy2";
        }
        // /*---------------------------------------------------------------------------------------------------*/
        // /*------------------------------- test 2: the vector capacity >= size + n ----------------------------------------*/
        {
            std::vector<std::string> v(20, "string");
            ft::vector<std::string> ft_v(20, "string");
            ft::vector<std::string>::iterator valid_it;

            v.reserve(100);
            ft_v.reserve(100);
            std::cout << "yay" << ft_v.capacity() << "|" << v.capacity() << std::endl;
            valid_it = ft_v.begin();
            v.insert(v.begin() + 15, 70, "hello");
            ft_v.insert(ft_v.begin() + 15, 70, "hello");

            std::cout << ft_v.capacity() << "|" << v.capacity() << std::endl;
            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            std::cout << ft_c << std::endl;
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c) && (&(*valid_it) == &(*ft_v.begin())));
            if (!cond)
                std::cout << "yyy3";
        }
        // /*---------------------------------------------------------------------------------------------------*/
        // /*------------------------------- test 3: the vector capacity < size + n && n > size ----------------------------------------*/
        {
            std::vector<std::string> v(20, "string");
            ft::vector<std::string> ft_v(20, "string");

            v.insert(v.begin() + 10, 100, "hello");
            ft_v.insert(ft_v.begin() + 10, 100, "hello");

            std::cout << ft_v.capacity() << "|" << v.capacity() << std::endl;
            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
            if (!cond)
                std::cout << "yyy4";
        }
        // /*---------------------------------------------------------------------------------------------------*/
        // /*------------------------------- test 4: the vector capacity < size + n && n <= size ----------------------------------------*/
        {
            std::vector<std::string> v(20, "string");
            ft::vector<std::string> ft_v(20, "string");

            std::cout <<"yay" << ft_v.capacity() << "|" << v.capacity() << std::endl;

            v.insert(v.begin() + 10, 15, "hello");
            ft_v.insert(ft_v.begin() + 10, 15, "hello");
            std::cout << ft_v.capacity() << "|" << v.capacity() << std::endl;

            str.clear();
            ft_str.clear();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
            cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
            if (s != ft_s)
                std::cout << "yyy5";
            if (str != ft_str)
                std::cout << "yyy5";
            // if (c != ft_c)
            //     std::cout << c << "|" << ft_c;
        }
        // /*---------------------------------------------------------------------------------------------------*/
}