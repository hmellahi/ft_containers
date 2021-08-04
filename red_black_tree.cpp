#include <map>
#include "map.hpp"
// #include <iostream>
// #include "pair.hpp"
#define NAMESPACE ft
int main()
{
    //  pair <std::string,int> planet, homeplanet;

//   planet = make_pair("Earth",6371);

//   homeplanet = planet;

//   std:cout << "Home planet: " << homeplanet.first << '\n';
//   std::cout << "Planet size: " << homeplanet.second << '\n';
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

NAMESPACE::map<char,int> mymap;
  NAMESPACE::map<char,int>::iterator it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
//   mymap['c']=30;
//   mymap['d']=40;
//   mymap['e']=50;
//   mymap['f']=60;

//   it=mymap.find('b');
//   mymap.erase (it);                   // erasing by iterator

  mymap.erase ('b');          
//   mymap.erase ('9');           // erasing by key

//   it=mymap.find ('e');
//   mymap.erase ( it, mymap.end() );    // erasing by range

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
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
    return 0;
}