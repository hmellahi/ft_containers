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
int main2()
{
    //  pair <std::string,int> planet, homeplanet;

//   planet = make_pair("Earth",6371);

//   homeplanet = planet;

//   std:cout << "Home planet: " << homeplanet.first << '\n';
//   std::cout << "Planet size: " utils<< homeplanet.second << '\n';
//     NAMESPACE::map<char, int> old;
//      old['d'] = 100;
//   old['a'] = 200;
//   old['c'] = 300;
//     // std::cout << old.size();

//     NAMESPACE::map<char, int> mymap(old.begin(), old.end());
//     // std::cout << mymap.size();

//   // show content:
//   for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
// NAMESPACE::map<char,int> mymap;

  // first insert function version (single parameter):
//   mymap.insert ( NAMESPACE::pair<char,int>('a',100) );
//   mymap.insert ( NAMESPACE::pair<char,int>('z',200) );

//   NAMESPACE::pair<NAMESPACE::map<char,int>::iterator,bool> ret;
//   ret = mymap.insert ( NAMESPACE::pair<char,int>('z',200) );
//   if (ret.second==false) {
//     std::cout << "element 'z' already existed";
//     std::cout << " with a value of " << ret.first->second << '\n';
//   }
//   NAMESPACE::map<char,int>::iterator it = mymap.begin();
//   mymap.insert (it, NAMESPACE::pair<char,int>('b',300));  // max efficiency inserting
//   mymap.insert (it, NAMESPACE::pair<char,int>('c',400));
//     //   for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     // std::cout << it->first << " => " << it->second << '\n';
// // showing contents:
// NAMESPACE::map<char,int> anothermap;
//   anothermap.insert(mymap.begin(),mymap.find('c'));

//   std::cout << "mymap contains:\n";
//   for (it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   std::cout << "anothermap contains:\n";
//   for (it=anothermap.begin(); it!=anothermap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

// NAMESPACE::map<char,int> mymap;
//   NAMESPACE::map<char,int>::iterator it;

//   // insert some values:
//   mymap['a']=10;
//   mymap['b']=20;
//   mymap['c']=30;
//   mymap['d']=40;
//   mymap['e']=50;
//   mymap['f']=60;
//  /*
//         a
//     b       c
//                 d
//                     e
//                         f
//  */
//   it=mymap.find('f');
//   mymap.erase (it);                   // erasing by iterator

// //   mymap.erase ('e');          
// //   mymap.erase ('9');           // erasing by key

// //   it=mymap.find ('e');
// //   mymap.erase ( it, mymap.end() );    // erasing by range
// // std::cout << mymap['b'];
//   // show content:
//   for (it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
  // NAMESPACE::map<char,int> mymap;
  // NAMESPACE::map<char,int>::key_compare mycomp = mymap.key_comp();

  // mymap['a']=100;
  // mymap['b']=200;
  // mymap['c']=300;

  // std::cout << "mymap contains:\n";

  // char highest = 'c';     // key value of last element
  // // std::cout << mymap.count('d');
  // NAMESPACE::map<char,int>::iterator it = mymap.begin();
  // do {
  //   std::cout << it->first << " => " << it->second << '\n';
  // } while ( mycomp((*it++).first, highest) );

  // std::cout << '\n';

  // NAMESPACE::map<char,int> mymap;

  // mymap['x']=100;
  // mymap['y']=200;
  // mymap['z']=300;

  // std::cout << "mymap contains:\n" << mymap.begin()->second;
  // for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';

  // mymap.clear();
  // mymap['a']=1101;
  // mymap['b']=2202;

  // std::cout << "mymap contains:\n";
  // for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';
  // mymap.clear();

//   NAMESPACE::map<char,int> mymap;
//   NAMESPACE::map<char,int>::iterator itlow,itup;

//   mymap['a']=20;
//   // mymap['b']=40;
//   mymap['c']=60;
//   mymap['d']=80;
//   mymap['e']=100;

//   itlow=mymap.lower_bound ('b');
//   std::cout << itlow->first ;  // itlow points to b
//   itup=mymap.upper_bound ('d');   // itup points to e (not d!)
// std::cout << itup->first ;
  // mymap.erase(itlow,itup);        // erases [itlow,itup) // todo : segfault

  // NAMESPACE::map<const char,int> mymap;

  // mymap['a']=10;
  // mymap['b']=20;
  // mymap['c']=30;
  // mymap['d']=40;
  // mymap['e']=40;

  // // NAMESPACE::map<const char,int> lol = mymap;
  // NAMESPACE::map<const char,int>::const_iterator it = mymap.begin(), ite = mymap.end();
  // for (; it != ite; ++it)
  //   std::cout << it->first << " => " << it->second << '\n';
  // std::map<int, std::string> m;
  // ft::map<int, std::string> ft_m;
  // for (int i = 0; i < 1e6; ++i)
  // {
  //     m.insert(std::make_pair(i, "value"));
  //     ft_m.insert(ft::make_pair(i, std::std::string("value")));// todo
  // }
  // std::cout << "waaath2" << std::endl;
  // start = get_time();
  // for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it)
  //     ;
  // for (ft::map<int, std::string>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                ;
  // {
  //     std::cout << "waaath1" << std::endl;
  //     int res(0);
  //     int myints[] = {12, 82, 37, 64, 15};
  //     ft::map<int, int> m;
  //     // todo
  //     for (int i = 0; i < 5; ++i)
  //         m.insert(ft::make_pair(myints[i], i));
  //     for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
  //         res += it->first;
  // }
    // it-;

			// std::cout << "- " << printPair(it, false) << std::endl;
  // it++;
  // std::cout << it->first << it->second;
  // std::cout << mymap['b'] << std::endl;
  // std::cout << it->first;
  // it++;
  // std::cout << it->first;
  // it++;
  // std::cout << it->first;
  // ft::pair<NAMESPACE::map<char,int>::iterator,NAMESPACE::map<char,int>::iterator> ret;
  // ret = mymap.equal_range('b');

  // std::cout << "lower bound points to: ";
  // std::cout << ret.first->first << " => " << ret.first->second << '\n';

  // std::cout << "upper bound points to: " ;
  // std::cout << ret.second->first << " => " << ret.second->second << '\n';


  // // print content:
  // for (NAMESPACE::map<const char,int>::iterator it=lol.rbegin(); it!=lol.rend(); it++)
  // mymap._rbt.preOrder( mymap._rbt.root);
  
  // while (it != mymap.end())
  // {
    // std::cout << it->first << " => " << it->second << '\n';it++;}
  // mymap.erase('a');
  // mymap.erase('b');
  // mymap.erase('c');
  // std::cout << mymap.size();
    // NAMESPACE::map<char,int>::iterator it=mymap.begin();
    // std::cout << it->first << " => " << it->second << '\n';
    // // std::cout << it->first << " => " << it->second << '\n';
    // // for (int i = 0; i < 10;i++)
    // //   it++;
    // // for (int i = 0; i < 8;i++)
    // //   it--;
    // std::cout << it->first << " => " << it->second << '\n';
    
// it++;
// std::cout << it->first << " => " << it->second << '\n';it++;
// // if (it)
// std::cout << it->first << " => " << it->second << '\n';it++;
// if (it)
// std::cout << it->first << " => " << it->second << '\n';
// it++;
// std::cout << it->first << " => " << it->second << '\n';
// it++;
// std::cout << it->first << " => " << it->second << '\n';
  // foo.swap(bar);
  // std::cout << foo.size();
  // std::cout << "foo contains:\n";
  // for (NAMESPACE::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';

  // std::cout << "bar contains:\n";
  // for (NAMESPACE::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
  //   std::cout << it->first << " => " << it->second << '\n';
// using namespace std;
//     allocator<int> myAllocator;
  
//     // allocate space for five ints
//     int* arr = myAllocator.allocate(5);
  
//     // construct arr[0] and arr[3]
//     myAllocator.construct(arr, 100);
//     arr[3] = 10;
  
//     cout << arr[3] << endl;
//     cout << arr[0] << endl;
  
//     // deallocate space for five ints
//     myAllocator.deallocate(arr, 5);
    // if ((it + 1))
    // NAMESPACE::map<char, int>::iterator it = mymap.begin();
    // NAMESPACE::map<char, int>::iterator it = mymap.begin();
    // std::cout << it->first << "|" << it->second << std::endl;
    // it++;
    // // std::cout << ((ite) == it) << std::endl;
    // std::cout << it->first << "|" << it->second << std::endl;
    // it++;
    // std::cout << it->first << "|" << it->second << std::endl;
    // it++;
    // std::cout << ((mymap.end()) == it) << std::endl;

    //     std::cout << it->first << "|" << it->second << std::endl;
    // it++;
    // if (it != mymap.end())
        // std::cout << it->first << "|" << it->second << std::endl;
    // it++;    // toodo : fking string not working
    // std::cout << *(mymap.end());
    // mymap[1] = "bruh";
    // std::cout << mymap[1]  << "\n";
    // RBT<string> b;
    // cout << mymap[1];
    // cout << a.insert(10)->value;
    // cout << a.insert(33)->value;
    // cout << a.insert(33)->value;
    // cout << a.insert(33)->value;
    // cout << a.insert(33)->value;
    // b.insert(*make_pair<int, int > (8, 5));
    // cout << *make_pair<int, int > (8, 5);
    // b.print();
    // b.insert("HEY");
    // b.insert("BBBB");
    // b.insert(70);
    // b.print();
    // cout << (b.search("HEY"));
    // RBT<char> mymap;
    // map<char, string> mymap;
    
    // b.insert(40);
    // b.insert(20);
    // b.insert(70);

//   mymap['b'] = 100;
    // cout << mymap['c'] ;   
    //   cout << "mymap now contains " << mymap.size() << " elements.\n";
//   mymap['a'] = 200;
//   mymap['c'] = 300;

//   // show content:
//   for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     cout << it->first << " => " << it->second << '\n';
    // b.insert(60);
    // b.insert(80);
 
    // a.insert(20);

    // {
    //   std::map<int, char> m;
    //   std::map<int, char>::iterator it, it1;

    //   ft::map<int, char> my_m;
    //   ft::map<int, char>::iterator my_it, my_it1, tmp;

    //   for (int i = 0; i < 10; ++i)
    //   {
    //       my_m.insert(ft::make_pair(i, static_cast<char>(i + 97)));
    //       m.insert(std::make_pair(i, static_cast<char>(i + 97)));
    //   }

    //   it = m.begin();
    //   it1 = ++(m.begin());
    //   my_it = my_m.begin();
    //   my_it1 = ++(my_m.begin());
    //   {
    //       ft::map<int, char>::const_iterator c_it, c_ob(my_it);
    //       c_it = my_it;
    //       std::cout << "my_it " << *my_it << std::endl;
    //       std::cout << "c_it " << (++c_it)->second << std::endl;
    //       std::cout << "c_ob " << c_ob->first << std::endl;
    //   }
    // }
    // {
    //   // time_t start, end, diff;
    //   std::map<int, std::string> m;
    //   ft::map<int, std::string> ft_m;
    //   for (int i = 0; i < 1e6; ++i)
    //   {
    //       m.insert(std::make_pair(i, "value"));
    //       ft_m.insert(ft::make_pair(i, std::std::string("value")));// todo
    //   }
    //   // std::cout << "waaath2" << std::endl;
    //   for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it)
    //       ;

    //   for (ft::map<int, std::string>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
    //       ;
    // }
    // {
    //     int res(0), tmp;
    //     int myints[] = {12, 82, 37, 64, 15};
    //     ft::map<int, int> m;
    //     for (int i = 0; i < 5; ++i)
    //         m.insert(ft::make_pair(myints[i], i));
    //     ft::map<int, int>::iterator it = m.begin(), eit = --m.end();
    //     tmp = eit->first;
    //     std::cout << "tmp " << tmp << std::endl;
    //     m.erase(eit);
    //     for (; it != m.end(); ++it)
    //         res += it->first;
    //     for (it = m.begin(); it != m.end(); ++it)
    //         std::cout << it->first << " " << it->second << std::endl;
    // }

    // {

    //     ft::map<int, std::string> ft_m;
    //     for (int i = 0; i < 6; ++i)
    //       ft_m.insert(ft::make_pair(i, std::std::string("value")));
    //     // ft::map<int, std::string>::iterator ft_it = --ft_m.end();
    //     // // ft_m.print2D();
    //     // for (; ft_it != ft_m.begin(); ft_it--)
    //     //   std::cout << ft_it->first << std::endl;

    //     ft::map<int, std::string>::iterator ft_it = ft_m.begin();
    //     std::cout << "am here" << std::endl;
    //     // for (; ft_it != ft_m.begin(); --ft_it)
    //     // std::cout << ft_it->first << std::endl;
    //     for (; ft_it != ft_m.end(); ++ft_it)
    //       std::cout << ft_it->first << std::endl;
    //     std::cout << "am here 2" << std::endl;
    // }
    // int res = 0;
    // {
    //   int myints[] = {12, 82, 37, 64, 15};
    //         ft::map<int, int> m;
    //         for (size_t i = 0; i < 5; ++i)
    //             m.insert(ft::make_pair(myints[i], (int)i)); //todo
    //         ft::map<int, int>::iterator it = --m.end();
    //         for (;; --it)
    //         {
    //             if (it == m.begin())
    //             {
    //                 res += it->first;
    //                 break;
    //             }
    //             res += it->first;
    //         }
    // }

    // {
    //         std::map<int, std::string> m1;
    //         std::map<int, std::string> m2;
    //         ft::map<int, std::string> ft_m1;
    //         ft::map<int, std::string> ft_m2;
    //         for (int i = 0; i < 1e6; ++i)
    //         {
    //             m1.insert(std::make_pair(i, "string1"));
    //             m2.insert(std::make_pair(i, "string2"));
    //             ft_m1.insert(ft::make_pair(i, std::std::string("string1"))); //todo
    //             ft_m2.insert(ft::make_pair(i, std::std::string("string2")));
    //         }

    //         m1 = m2;
    //         /*-----------------------------------------------------*/
    //         /*------------------ ft::map ---------------------*/
    //         ft_m1 = ft_m2;
    //         /*----------------------------------------------------*/
    //     }
    //     /*------------------------------------------------------------------------------------------*/
    //     /*------------------ std::map ---------------------*/
    //     std::map<int, std::string> m1;
    //     std::map<int, std::string> m2;
    //     ft::map<int, std::string> ft_m1;
    //     ft::map<int, std::string> ft_m2;
    //     for (int i = 0; i < 10; ++i)
    //     {
    //         m1.insert(std::make_pair(i, "string1"));
    //         m2.insert(std::make_pair(i, "string2"));
    //         ft_m1.insert(ft::make_pair(i, std::std::string("string1")));
    //         ft_m2.insert(ft::make_pair(i, std::std::string("string2")));
    //     }

    //     m1 = m2;
    //     ft_m1 = ft_m2;
    //     /*----------------------------------------------------*/
    //     /*------------------ strings to store the results ----*/
    //     std::string res, ft_res;
    //     /*----------------------------------------------------*/
    //     for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); ++it) // fill res from m1
    //         res += it->first;
    //   std::cout << "am here" << std::endl;
    //     for (ft::map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
    //         ft_res += it->first;
    //   std::cout << "am here2" << std::endl;

// {
//             time_t start, end, diff;
//             std::map<int, std::string> m1;
//             std::map<int, std::string> m2;
//             ft::map<int, std::string> ft_m1;
//             ft::map<int, std::string> ft_m2;
//             for (int i = 0; i < 1e6; ++i)
//             {
//                 m1.insert(std::make_pair(i, "string1"));
//                 m2.insert(std::make_pair(i, "string2"));
//                 ft_m1.insert(ft::make_pair(i, std::string("string1"))); //todo
//                 ft_m2.insert(ft::make_pair(i, std::string("string2")));
//             }

//             // start = get_time();
//             m1 = m2;
//             // end = get_time();
//             // diff = end - start;
//             // diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
//             /*-----------------------------------------------------*/
//             /*------------------ ft::map ---------------------*/
//             // ualarm(diff * 1e3, 0);
//             ft_m1 = ft_m2;
//             // ualarm(0, 0);
//             /*----------------------------------------------------*/
//         }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::map ---------------------*/
        if (false)
        {{
          std::map<int, std::string> m1;
          std::map<int, std::string> m2;
          ft::map<int, std::string> ft_m1;
          ft::map<int, std::string> ft_m2;
          for (int i = 0; i < 10; ++i)
          {
              m1.insert(std::make_pair(i, "string1"));
              m2.insert(std::make_pair(i, "string2"));
              ft_m1.insert(ft::make_pair(i, std::string("string1")));
              ft_m2.insert(ft::make_pair(i, std::string("string2")));
          }

          m1 = m2;
          ft_m1 = ft_m2;
          /*----------------------------------------------------*/
          /*------------------ strings to store the results ----*/
          std::string res, ft_res;
          /*----------------------------------------------------*/
          for (std::map<int, std::string>::iterator it = m1.begin(); it != m1.end(); ++it)
          { // fill res from m1
              res += it->second;
          }
          std::cout << "am here " << std::endl;
          for (ft::map<int, std::string>::iterator it = ft_m1.begin(); it != ft_m1.end(); ++it) // fill ft_res from ft_m1
              ft_res += it->second;
          // printf("%s|%s", ft_res, res);
          std::cout << ft_res << std::endl;
          std::cout << res << std::endl;
        }
        if (false)
        {
          time_t start, end, diff;
            std::map<int, std::string> m1;
            std::map<int, std::string> m2;
            ft::map<int, std::string> ft_m1;
            ft::map<int, std::string> ft_m2;
            for (int i = 0; i < 1e6; ++i)
            {
                m1.insert(std::make_pair(i, "string1"));
                m2.insert(std::make_pair(i, "string2"));
                ft_m1.insert(ft::make_pair(i, std::string("string1"))); //todo
                ft_m2.insert(ft::make_pair(i, std::string("string2")));
            }

            /*-----------------------------------------------------*/
            /*------------------ ft::map ---------------------*/
            start = get_time();
            m1 = m2;
            end = get_time();
            diff = end - start;
            std::cout << "std " << end - start << std::endl;

            start = get_time();
            ft_m1 = ft_m2;
            end = get_time();
            diff = end - start;
            std::cout << "ft " <<end - start << std::endl;

            start = get_time();
            m1.clear();
            end = get_time();
            diff = end - start;
            std::cout << "std clear " <<end - start << std::endl;

            start = get_time();
            ft_m1.clear();
            end = get_time();
            diff = end - start;
            std::cout << "ft clear" <<end - start << std::endl;

            start = get_time();
            m2.clear();
            end = get_time();
            diff = end - start;
            std::cout << "std clear " <<end - start << std::endl;

            start = get_time();
            ft_m2.clear();
            end = get_time();
            diff = end - start;
            std::cout << "ft clear" <<end - start << std::endl;
        }

      ft::pair<int,std::string> p;
      p = ft::make_pair(3, "sda");
      ft::pair<int,std::string> p2(3, "sda");
}

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

            for (int i = 0; i < 1e4; ++i)
            {
                m1.insert(std::make_pair(i, "string1"));
                ft_m1.insert(ft::make_pair(i, std::string("string1")));
            }

            for (int i = 0; i < 1e6; ++i)
            {
                m2.insert(std::make_pair(i, "string2"));
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
int main() {
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
    // std::map<int, std::string> m1;
    // ft::map<int, std::string> ft_m1;
    // for (int i = 0; i < 5; i++)
    // {
    //     m1.insert(std::make_pair(i, "string2"));
    //     ft_m1.insert(ft::make_pair(i, std::string("string2")));
    // }

    // m1.erase(m1.begin(), m1.end());
    // /*-----------------------------------------------------*/
    // /*------------------ ft::maps ---------------------*/
    // // ft_m1.erase(ft_m1.begin(), ft_m1.end());
    // ft_m1.print2D();
    // // ft_m1.erase(0);
    // // std::cout << *(--ft_m1.end()) << std::endl;
    // ft_m1.erase(--(--ft_m1.end()), ft_m1.end());
    // ft_m1.print2D();
    // exit(0);
    {
            time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::map<int, std::string> ft_m1;
            for (int i = 0; i < 1000; i++)
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
        std::random_device randDev;
        std::mt19937 generator(randDev());
        std::uniform_int_distribution<int> distr(0, 1e8);

        for (int i = 0; i < 1e6; i++)
        {
            m3.insert(std::make_pair(i, "string1"));
            ft_m3.insert(ft::make_pair(i, string("string1")));
        }

        for (size_t i = 0; i < 1e6; ++i)
        {
            int n = distr(generator);
            int ret1 = m3.erase(n);
            int ret2 = ft_m3.erase(n);

            if (ret1 != ret2)
            {
                cond = false;
                break;
            }
        }
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