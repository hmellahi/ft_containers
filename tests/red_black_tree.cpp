#include <map>
#include "map.hpp"
// #include "vector.hpp"
// #include <iostream>
// #include "pair.hpp"
#define NAMESPACE ft
int main()
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
  //     ft_m.insert(ft::make_pair(i, std::string("value")));// todo
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
    //       ft_m.insert(ft::make_pair(i, std::string("value")));// todo
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

    {

        ft::map<int, std::string> ft_m;
        for (int i = 0; i < 6; ++i)
          ft_m.insert(ft::make_pair(i, std::string("value")));
        ft::map<int, std::string>::iterator ft_it = --ft_m.end();
        // ft_m.print2D();
        // for (; ft_it != ft_m.begin(); ft_it--)
        //   std::cout << ft_it->first << std::endl;

        // ft::map<int, std::string>::iterator ft_it = ft_m.begin();
        // std::cout << "am here" << std::endl;
        // // for (; ft_it != ft_m.begin(); --ft_it)
        // // std::cout << ft_it->first << std::endl;
        // for (; ft_it != ft_m.end(); ++ft_it)
        //   std::cout << ft_it->first << std::endl;
        // std::cout << "am here 2" << std::endl;
    }
    // int res(0);
    // {
    //     int myints[] = {12, 82, 37, 64, 15};
    //     ft::map<int, int> m;
    //     for (size_t i = 0; i < 5; ++i)
    //         m.insert(ft::make_pair(myints[i], (int)i)); //todo
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