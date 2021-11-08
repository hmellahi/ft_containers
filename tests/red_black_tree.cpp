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
int main()
{
using namespace std;
std::cout << "\t\033[1;37m[-------------------- ["  << std::left << " = operator (lhs.size < rhs.size) "
              << "] --------------------]\t\t\033[0m";
    
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::map ---------------------*/
            std::map<int, std::string> m1;
            std::map<int, std::string> m2;
            ft::map<int, std::string> ft_m1;
            ft::map<int, std::string> ft_m2;

            for (int i = 0; i < 1e6; ++i)
            {
                m1.insert(std::make_pair(i, "string1"));
                m2.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair(i, std::string("string1")));
                ft_m2.insert(ft::make_pair(i, std::string("string2")));
            }

            start = get_time();
            m1 = m2;
            end = get_time();
            diff = end - start;
            /*-----------------------------------------------------*/
            /*------------------ ft::map ---------------------*/
            ft_m1 = ft_m2;
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::map ---------------------*/
        std::map<int, std::string> m1;
        std::map<int, std::string> m2;
        ft::map<int, std::string> ft_m1;
        ft::map<int, std::string> ft_m2;
        for(int i = 0; i < 100; ++i)
        {
            m2.insert(std::make_pair(i, "value"));
            ft_m2.insert(ft::make_pair(i, string("value")));
        }
        m1 = m2;
        /*-----------------------------------------------------*/
        /*------------------ ft::map ---------------------*/
        ft_m1 = ft_m2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); ++it) // fill res from m1
            res += it->second;

        for (ft::map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
            ft_res += it->second;
    //   std::cout<< res << std::endl;
    //   std::cout<< ft_res << std::endl;
      if (res != ft_res)
        std::cout << "noooo" <<std::endl;
    else
        std::cout << "y" <<std::endl;

    }
        // // EQUAL(res == ft_res);
    // }
    // int res(0);
    // {
        // int myints[] = {12, 82, 37, 64, 15};
        // ft::map<int, int> m;
        // for (size_t i = 0; i < 5; ++i)
        //     m.insert(ft::make_pair(myints[i], (int)i)); //todo
    //     ft::map<int, int>::iterator it = --m.end();
    //     for (;; --it)
    //     {
    //         if (it == m.begin())
    //         {
    //             res += it->first;
    //             break;
    //         }
    //         res += it->first;
    //     }
    // }
  
  
  return 0;
}
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
using namespace std;
int main2() {
    // int myints[] = {12, 82, 37, 64, 15};
    // ft::map<int, int> m;
    // for (size_t i = 0; i < 5; ++i)
    //       m.insert(ft::make_pair(myints[i], (int)i));
    // std::cout << *m.upper_bound(64) << std::endl;
    // std::cout << *m.lower_bound(64) << std::endl;
    // int res(0), tmp;
    // int myints[] = {12, 82, 37, 64, 15};
    // ft::map<int, int> m;
    // for (int i = 0; i < 5; ++i)
    //     m.insert(ft::make_pair(myints[i], i));
    // ft::map<int, int>::iterator it = m.begin(), eit = --m.end();
    // tmp = eit->first;
    // m.print2D();
    // m.erase(15);
    // std::cout << "--------------------------------" << std::endl;
    // m.print2D();
    // {
    //     std::map<int, std::string> m1;
    //     ft::map<int, std::string> ft_m1;
    //     for (int i = 0; i < 5; i++)
    //     {
    //         m1.insert(std::make_pair(i, "string2"));
    //         ft_m1.insert(ft::make_pair(i, std::string("string2")));
    //     }

    //     // m1.erase(m1.begin(), m1.end());
    //     // /*-----------------------------------------------------*/
    //     // /*------------------ ft::maps ---------------------*/
    //     ft_m1.print2D();
    //     ft_m1.erase(ft_m1.begin(), ft_m1.end());
    //     ft_m1.print2D();
    // }
    // // ft_m1.erase(0);
    // // std::cout << *(--ft_m1.end()) << std::endl;
    // // ft_m1.erase(--(--ft_m1.end()), ft_m1.end());
    // // ft_m1.print2D();
    // exit(0);
    {
            time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::map<int, std::string> ft_m1;
            for (int i = 0; i < 1e6; i++)
            {
                m1.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair(i, string("string2")));
            }

            m1.erase(m1.begin(), m1.end());
            /*-----------------------------------------------------*/
            /*------------------ ft::maps ---------------------*/
            ft_m1.erase(ft_m1.begin(), ft_m1.end());
            std::cout << "size" << ft_m1.size();
            /*----------------------------------------------------*/
        }
        // system("leaks a.out");
        exit(0);
    std::map<char, int> m;
        ft::map<char, int> ft_m;
        std::map<char, int>::iterator it;
        ft::map<char, int>::iterator ft_it;

        // insert some values:
        ft_m['a'] = 10;
        ft_m['b'] = 20;
        ft_m['c'] = 30;
        ft_m['d'] = 40;
        ft_m['e'] = 50;
        ft_m['f'] = 60;

        m['a'] = 10;
        m['b'] = 20;
        m['c'] = 30;
        m['d'] = 40;
        m['e'] = 50;
        m['f'] = 60;

        int cond = m.size() == ft_m.size();// && comparemaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        it = m.find('b');
        ft_it = ft_m.find('b');

        cond = cond && (it->first == ft_it->first) && (it->second == ft_it->second);
        m.erase(it);   
        ft_m.print2D();
        ft_m.erase(ft_it); // erasing by iterator
        ft_m.print2D();

        cond = cond;//&& comparemaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        int ret = m.erase('c');       // erasing by key
        int ft_ret = ft_m.erase('c'); // erasing by key
        ft_m.print2D();
        // exit(0);
        cond = cond && ret == ft_ret;// && comparemaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        it = m.find('e');
        ft_it = ft_m.find('e');

        cond = cond && (it->first == ft_it->first) && (it->second == ft_it->second) && m.size() == ft_m.size();

        m.erase(it, m.end());          // erasing by range
        ft_m.erase(ft_it, ft_m.end()); // erasing by range

        cond = cond && m.empty() == ft_m.empty();// && comparemaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        /* ---------- Testing some edge cases ---------- */

        std::map<int, std::string> m2;
        ft::map<int, std::string> ft_m2;

        for (int i = 0; i < 1e5; i++)
        {
            m2.insert(std::make_pair(i, "string1"));
            ft_m2.insert(ft::make_pair(i, std::string("string1")));
        }

        std::map<int, std::string>::reverse_iterator it2 = m2.rbegin();
        ft::map<int, std::string>::reverse_iterator ft_it2 = ft_m2.rbegin();

        m2.erase(m2.begin());
        ft_m2.erase(ft_m2.begin());

        cond = cond && m2.size() == ft_m2.size();// && comparemaps(m2.begin(), m2.end(), ft_m2.begin(), ft_m2.end());

        m2.erase(it2->first);
        ft_m2.erase(ft_it2->first);

        cond = cond && m2.size() == ft_m2.size();// && comparemaps(m2.begin(), m2.end(), ft_m2.begin(), ft_m2.end());

        std::map<int, std::string> m3;
        ft::map<int, std::string> ft_m3;
        std::vector<int> vec;
        std::vector<int> ft_vec;
        // std::random_device randDev;
        // std::mt19937 generator(randDev());
        // std::uniform_int_distribution<int> distr(0, 1e8);

        for (int i = 0; i < 1e6; i++)
        {
            m3.insert(std::make_pair(i, "string1"));
            ft_m3.insert(ft::make_pair(i, string("string1")));
        }

        // for (size_t i = 0; i < 1e6; ++i)
        // {
        //     int n = distr(generator);
        //     int ret1 = m3.erase(n);
        //     int ret2 = ft_m3.erase(n);

        //     if (ret1 != ret2)
        //     {
        //         cond = false;
        //         break;
        //     }
        // }
  if (false)
  {
    bool cond = 1;
        /*---------------------------------- time limit test --------------------------------------------*/
        // {
        //     int res, ft_res;

        //     std::map<int, std::string> m;
        //     ft::map<int, std::string> ft_m;
        //     for (int i = 0; i < 1e6; ++i)
        //     {
        //         m.insert(std::make_pair(i, "value"));
        //         ft_m.insert(ft::make_pair(i, std::string("value")));
        //     }
        //     res = m.lower_bound(1e5)->first;

        //     // ualarm(diff * 1e3, 0);
        //     ft_res = ft_m.lower_bound(1e5)->first;
        //     cond = ft_res == res;
        // }
        std::map<int, std::string> m;
        ft::map<int, std::string> ft_m;
        int arr[] = {20, 10, 100, 15, 60, 90, 65, 200, 150}; // size = 9
        for (int i = 0; i < 9; ++i)
        {
            m.insert(std::make_pair(arr[i], "value"));
            ft_m.insert(ft::make_pair(arr[i], std::string("value")));
        }
        std::map<int, std::string> const c_m(m.begin(), m.end());
        ft::map<int, std::string> const c_ft_m(ft_m.begin(), ft_m.end());
        cond = (cond && (m.lower_bound(15)->first == ft_m.lower_bound(15)->first));
        cond = (cond && (m.lower_bound(65)->first == ft_m.lower_bound(65)->first));
        cond = (cond && (m.lower_bound(63)->first == ft_m.lower_bound(63)->first));
        cond = (cond && (m.lower_bound(120)->first == ft_m.lower_bound(120)->first));
        cond = (cond && (m.lower_bound(70)->first == ft_m.lower_bound(70)->first));

        cond = (cond && (c_m.lower_bound(15)->first == c_ft_m.lower_bound(15)->first));
        cond = (cond && (c_m.lower_bound(65)->first == c_ft_m.lower_bound(65)->first));
        cond = (cond && (c_m.lower_bound(63)->first == c_ft_m.lower_bound(63)->first));
        cond = (cond && (c_m.lower_bound(120)->first == c_ft_m.lower_bound(120)->first));
        cond = (cond && (c_m.lower_bound(70)->first == c_ft_m.lower_bound(70)->first));
        std::cout << cond << std::endl;
  }
  if (false)
  {
        bool cond(false);
        // erasing all the elements in the map;
        {
            time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::map<int, std::string> ft_m1;
            for (int i = 0; i < 1e6; i++)
            {
                m1.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair(i, std::string("string2")));
            }

            m1.erase(m1.begin(), m1.end());
            /*-----------------------------------------------------*/
            /*------------------ ft::maps ---------------------*/
            ft_m1.erase(ft_m1.begin(), ft_m1.end());
            /*----------------------------------------------------*/
        }
        std::map<char, int> m;
        ft::map<char, int> ft_m;
        std::map<char, int>::iterator it;
        ft::map<char, int>::iterator ft_it;

        // insert some values:
        ft_m['a'] = 10;
        ft_m['b'] = 20;
        ft_m['c'] = 30;
        ft_m['d'] = 40;
        ft_m['e'] = 50;
        ft_m['f'] = 60;

        m['a'] = 10;
        m['b'] = 20;
        m['c'] = 30;
        m['d'] = 40;
        m['e'] = 50;
        m['f'] = 60;

        // cond = m.size() == ft_m.size() && comparemaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        it = m.find('b');
        ft_it = ft_m.find('b');

        cond = cond && (it->first == ft_it->first) && (it->second == ft_it->second);
        m.erase(it);       // erasing by iterator
        ft_m.erase(ft_it); // erasing by iterator

        // cond = cond && comparemaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());
        std::cout << "a, here" << std::endl;

        int ret = m.erase('c');       // erasing by key
        int ft_ret = ft_m.erase('c'); // erasing by key

        // cond = cond && ret == ft_ret && comparemaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        it = m.find('e');
        ft_it = ft_m.find('e');

        // cond = cond && (it->first == ft_it->first) && (it->second == ft_it->second) && m.size() == ft_m.size();

        m.erase(it, m.end());          // erasing by range
        ft_m.erase(ft_it, ft_m.end()); // erasing by range

        // cond = cond && m.empty() == ft_m.empty() && comparemaps(m.begin(), m.end(), ft_m.begin(), ft_m.end());

        /* ---------- Testing some edge cases ---------- */

        std::map<int, std::string> m2;
        ft::map<int, std::string> ft_m2;
        std::cout << "a, here" << std::endl;
        for (int i = 0; i < 1e5; i++)
        {
            m2.insert(std::make_pair(i, "string1"));
            ft_m2.insert(ft::make_pair(i, std::string("string1")));
        }

        std::map<int, std::string>::reverse_iterator it2 = m2.rbegin();
        ft::map<int, std::string>::reverse_iterator ft_it2 = ft_m2.rbegin();

        m2.erase(m2.begin());
        ft_m2.erase(ft_m2.begin());

        // cond = cond && m2.size() == ft_m2.size() && comparemaps(m2.begin(), m2.end(), ft_m2.begin(), ft_m2.end());

        m2.erase(it2->first);
        ft_m2.erase(ft_it2->first);

        // cond = cond && m2.size() == ft_m2.size() && comparemaps(m2.begin(), m2.end(), ft_m2.begin(), ft_m2.end());

        std::map<int, std::string> m3;
        ft::map<int, std::string> ft_m3;
        std::vector<int> vec;
        std::vector<int> ft_vec;
        // std::random_device randDev; todo
        // std::mt19937 generator(randDev()); todo
        // std::uniform_int_distribution<int> distr(0, 1e8); todo

        for (int i = 0; i < 1e6; i++)
        {
            m3.insert(std::make_pair(i, std::string("string1")));
            ft_m3.insert(ft::make_pair(i, std::string("string1")));
        }

        // for (size_t i = 0; i < 1e6; ++i)
        // {
        //     // int n = distr(generator); todo
        //     // int ret1 = m3.erase(n); todo
        //     // int ret2 = ft_m3.erase(n); todo

        //     // if (ret1 != ret2) todo
        //     // {
        //     //     cond = false;
        //     //     break;
        //     // }
        // }

        if (!m3.empty())
        {
            m3.erase(m3.begin(), m3.end());
            m3.erase(m3.begin(), m3.end());
        }
        if (!ft_m3.empty())
        {
            ft_m3.erase(ft_m3.begin(), ft_m3.end());
            ft_m3.erase(ft_m3.begin(), ft_m3.end());
        }
        // cond = cond && (m3.size() == ft_m3.size() && comparemaps(m3.begin(), m3.end(), ft_m3.begin(), ft_m3.end()));

        // EQUAL(cond);
}
  return 0;
}