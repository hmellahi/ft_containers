#include "RBT.hpp"
#include <map>
#include "map.hpp"
int main()
{
    RBT<pair<int, int >> B;
    RBT<std::string> b;
    // std::cout << a.insert(10)->value;
    // std::cout << a.insert(33)->value;
    // std::cout << a.insert(33)->value;
    // std::cout << a.insert(33)->value;
    // std::cout << a.insert(33)->value;
    // b.insert(*make_pair<int, int > (8, 5));
    // std::cout << *make_pair<int, int > (8, 5);
    // b.print();
    b.insert("HEY");
    b.insert("BBBB");
    // b.insert(70);
    b.print();
    std::cout << (b.search("HEYS"));
    // RBT<char> mymap;
    // std::map<char, std::string> mymap;

    // b.insert(40);
    // b.insert(20);
    // b.insert(70);

//   mymap['b'] = 100;
    // std::cout << mymap['c'] ;   
    //   std::cout << "mymap now contains " << mymap.size() << " elements.\n";
//   mymap['a'] = 200;
//   mymap['c'] = 300;

//   // show content:
//   for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
    // b.insert(60);
    // b.insert(80);
 
    // a.insert(20);
}