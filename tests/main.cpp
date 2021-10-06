#include "vector.hpp"
#include "stack.hpp"
#include  <vector>
#include  <stack>

<<<<<<< HEAD
//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   ft::vector<int> foo (3,0);
//   ft::vector<int> bar (5,0);

//   bar = foo;
//   foo = ft::vector<int>();

//   std::cout << "Size of foo: " << int(foo.size()) << '\n';
//   std::cout << "Size of bar: " << int(bar.size()) << '\n';

//  	ft::vector<int> foo (3,100);   // three ints with a value of 100
//   	ft::vector<int> bar (3,300);   // two ints with a value of 200

//   if (foo==bar) std::cout << "foo and bar are equal\n";
//   if (foo!=bar) std::cout << "foo and bar are not equal\n";
//   if (foo< bar) std::cout << "foo is less than bar\n";
//   if (foo> bar) std::cout << "foo is greater than bar\n";
//   if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//   if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
// ft::vector<int> first2;                                // empty ft::vector of ints
//   ft::vector<int> second2 (4,100);                       // four ints with value 100
//   ft::vector<int> third3 (second.begin(),second.end());  // iterating through second
// //   ft::vector<int> fourth (third);                       // a copy of third

//   // the iterator constructor can also be used to construct from arrays:
//   int myints2[] = {16,2,77,29};
//   ft::vector<int> fifth (myints2, myints2 + sizeof(myints2) / sizeof(int) );

//   std::cout << "The contents of fifth are:";
//   for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';
	return 0;
}

// #include "common.hpp"
// #include <vector>
// #define TESTED_NAMESPACE std
// #define TESTED_TYPE int

// void	is_empty(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct)
// {
// 	std::cout << "is_empty: " << vct.empty() << std::endl;
// }

int		main3(void)
{
// 	std::deque<int> mydeque (3,100);          // deque with 3 elements
//   std::vector<int> myvector (2,200);        // vector with 2 elements

//   std::stack<int> first;                    // empty stack
//   std::stack<int> second (mydeque);         // stack initialized to copy of deque

//   std::stack<int,std::vector<int> > third(myvector);  // empty stack using vector
//   std::stack<int,std::vector<int> > fourth (myvector);

//   std::cout << "size of first: " << first.size() << '\n';
//   std::cout << "size of second: " << second.size() << '\n';
//    third.pop();
//   std::cout << "size of third: " << third.size() << '\n';
//   std::cout << "size of fourth: " << fourth.size() << '\n';

// 	 ft::vector<int> myvector (3,100);
//   ft::vector<int>::iterator it;
// it = myvector.begin();
//   it = myvector.insert ( it , 200 );

//   myvector.insert (it,2,300);

//   // "it" no longer valid, get a new one:
//   it = myvector.begin();

//   std::vector<int> anothervector (2,400);
//   myvector.insert (it+2,anothervector.begin(),anothervector.end());

//   int myarray [] = { 501,502,503 };
//   myvector.insert (myvector.begin(), myarray, myarray+3);

//   std::cout << "myvector contains:";
//   for (it=myvector.begin(); it<myvector.end(); it++)
//     std::cout << ' ' << *it;
//   std::cout << '\n';
//  ft::vector<int> myvector;

//   // set some initial content:
//   for (int i=1;i<10;i++) myvector.push_back(i);

//   myvector.resize(5);
//   myvector.resize(8,100);
//   myvector.resize(12);

//   std::cout << "myvector contains:";
//   for (size_t i=0;i<myvector.size();i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';


	// const int size = 5;
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it(vct.begin());
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator ite(vct.end());


// 	for (int i = 1; it != ite; ++i)
// 		*it++ = i;
// 	// printSize(vct, 1);
//  puts("----");
// 	// *ite = *it;
// 	it = vct.begin();
// 	ite = vct.begin();
// 	if (it >= ite)
// 		std::cout << "yes"; 
// 	// std::cout << *(it) << std::endl;
// 	// std::cout << *(ite) << std::endl;
// 	std::cout << *(++ite) << std::endl;
// 	std::cout << *(ite++) << std::endl;
// 	std::cout << *ite++ << std::endl;
// 	std::cout << *++ite << std::endl;

// 	// it->m();
// 	// ite->m();

// 	std::cout << *(++it) << std::endl;
// 	std::cout << *(it++) << std::endl;
// 	std::cout << *it++ << std::endl;
// 	std::cout << *++it << std::endl;

// 	std::cout << *(--ite) << std::endl;
// 	std::cout << *(ite--) << std::endl;
// 	std::cout << *--ite << std::endl;
// 	std::cout << *ite-- << std::endl;

// 	// (*it).m();
// 	// (*ite).m();

// 	std::cout << *(--it) << std::endl;
// 	std::cout << *(it--) << std::endl;
// 	std::cout << *it-- << std::endl;
// 	std::cout << *--it << std::endl;
	// const int start_size = 7;
	// TESTED_NAMESPACE::vector<TESTED_TYPE> vct(start_size, 20);
	// TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
	// TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
	// TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator ite = vct.begin();
	// if (ite == ite)
	// 	puts("dasd");
	// for (int i = 2; i < start_size; ++i)
	// 	it[i] = (start_size - i) * 3;
	// //printSize(vct, true);

	// vct.resize(10, 42);
	// //printSize(vct, true);

	// vct.resize(18, 43);
	// //printSize(vct, true);
	// vct.resize(10);
	// //printSize(vct, true);
	// vct.resize(23, 44);
	// //printSize(vct, true);
	// vct.resize(5);
	// //printSize(vct, true);
	// vct.reserve(5);
	// vct.reserve(3);
	// //printSize(vct, true);
	// vct.resize(87);
	// vct.resize(5);
	// //printSize(vct, true);

	// is_empty(vct2);
	// vct2 = vct;
	// is_empty(vct2);
	// vct.reserve(vct.capacity() + 1);
	// //printSize(vct, true);
	// //printSize(vct2, true);

	// vct2.resize(0);
	// is_empty(vct2);
	//printSize(vct2, true);
	// std::vector<int> myvector;
	// for (int i=1; i<=5; i++) myvector.push_back(i);

	// std::cout << "myvector contains:";
	// for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	
	return (0);
}


// #include <list>
// #define T1 int
// #define T2 std::string
// typedef std::pair<const T1, T2> T3;

// static int iter = 0;

// template <typename MAP, typename U>
// void	ft_erase(MAP &mp, U param)
// {
// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	mp.erase(param);
// 	printSize(mp);
// }

// template <typename MAP, typename U, typename V>
// void	ft_erase(MAP &mp, U param, V param2)
// {
// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	mp.erase(param, param2);
// 	printSize(mp);
// }

// int		main(void)
// {
	// std::list<T3> lst;
	// C++ program for illustration
// of std::allocator() function
#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main()
{

	// allocator for string values
	allocator<string> myAllocator;

	// allocate space for three strings
	string* str = myAllocator.allocate(3);

	// construct these 3 strings
	myAllocator.construct(str, "Geeks");
	myAllocator.construct(str + 1, "for");
	//myAllocator.construct(str + 2, "Geeks");
	str[2] = 4;
	cout << str[0] << str[1] << str[2];

	// destroy these 3 strings
	myAllocator.destroy(str);
	myAllocator.destroy(str + 1);
	myAllocator.destroy(str + 2);

	// deallocate space for 3 strings
	myAllocator.deallocate(str, 3);
// }

	// unsigned int lst_size = 10;
	// for (unsigned int i = 0; i < lst_size; ++i)
	// 	lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	// TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	// printSize(mp);

	// ft_erase(mp, ++mp.begin());

	// ft_erase(mp, mp.begin());
	// ft_erase(mp, --mp.end());

	// ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
	// ft_erase(mp, --(--(--mp.end())), --mp.end());

	// mp[10] = "Hello";
	// mp[11] = "Hi there";
	// printSize(mp);
	// ft_erase(mp, --(--(--mp.end())), mp.end());

	// mp[12] = "ONE";
	// mp[13] = "TWO";
	// mp[14] = "THREE";
	// mp[15] = "FOUR";
	// printSize(mp);
	// ft_erase(mp, mp.begin(), mp.end());

	return (0);
}
=======
int main()
{
    ft::vector<int> van(5, 10);
    ft::vector<int> vat;
    vat.push_back(1);
    vat.push_back(2);
    vat.push_back(3);
    vat.push_back(4);
    // std::ft::vector<int> bo(++van.begin(),--van.end());
    //  if (bo == van)
    //     std::cout << "kik" << std::endl;
    // else
    //     std::cout << "kok" << std::endl;
    // // constuct with n range && capacity && push && pop back
    // ft::vector<int> vectorr(10, 100);
    // std::cout << "vectorr ---" << std::endl;
    // vectorr.push_back(4);
    // vectorr.push_back(4);
    // vectorr.pop_back();
    // for (ft::vector<int>::iterator it = vectorr.begin(); it != vectorr.end(); it++)
    //     std::cout << *it << std::endl;
    // std::cout << vectorr.capacity() << std::endl;
    // // construct  with iterators
    // ft::vector<int>::iterator it = vectorr.begin();
    // it++;
    // it++;
    // it++;
    // ft::vector<int> vec(vectorr.begin(), it);
    // std::cout << "vec ---" << std::endl;
    // for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    //     std::cout << *it << std::endl;
    // // copy construct
    // ft::vector<int> vecto(vec);
    // std::cout << "vecto ---" << std::endl;
    // for (ft::vector<int>::iterator it = vecto.begin(); it != vecto.end(); it++)
    //     std::cout << *it << std::endl;
    // // assign && reserve
    // std::cout << "vectorr assign" << std::endl;
    // vectorr.assign(4, 5);
    // vectorr.reserve(100);
    // for (ft::vector<int>::iterator it = vectorr.begin(); it != vectorr.end(); it++)
    //     std::cout << *it << std::endl;
    // std::cout << vectorr.capacity() << std::endl;
    // // swap && erase
    // std::cout << "erase" << std::endl;
    ft::vector<int> va;
    va.push_back(1);
    va.push_back(2);
    va.push_back(3);
    va.push_back(4);
    // ft::vector<int>::iterator to = va.erase(va.begin());
    // for (ft::vector<int>::iterator it = va.begin(); it != va.end(); it++)
    //     std::cout << *it << std::endl;
    // std::cout << *to << std::endl;
    // // erase range of its
    // std::cout << "range erase" << std::endl;
    // ft::vector<int>::iterator top = va.erase(va.begin(), va.end());
    // for (ft::vector<int>::iterator it = va.begin(); it != va.end(); it++)
    //     std::cout << *it << std::endl;
    //     std::cout << *to << std::endl;
    // resize
    // std::cout << "resize" << std::endl;
    // va.resize(6,10);
    // for (ft::vector<int>::iterator it = va.begin(); it != va.end(); it++)
    //     std::cout << *it << std::endl;
    // std::cout << va.size() << std::endl;
    // insert
    ft::vector<int>::iterator po = va.insert(++va.begin(), 3);
    // std::cout << "insert" << std::endl;
    va.insert(++va.begin(),17, 5);
    va.insert(++va.begin(),van.begin(), --van.end()); 
    std::cout << *va.erase(va.begin()) << "lol"<< std::endl;
    std::cout << *va.erase(++va.begin(),--va.end()) << "lol"<< std::endl;
    std::cout << *po << std::endl;
    std::cout << va.capacity() << std::endl;
    va.assign(vat.begin(), vat.end());
    std::cout << "n" << std::endl;
     for (ft::vector<int>::iterator it = va.begin(); it != va.end(); it++)
        std::cout << *it << std::endl;
    std::cout << "n" << std::endl;
    std::cout << va.capacity() << std::endl;
    ft::stack<int, ft::vector<int> > stonk(va);
    std::cout << stonk.size() << " stack size" <<  std::endl;

    // std::cout << &(*po) << " " << &(*(++va.begin())) << std::endl;
    // std::cout << *po << std::endl;
    // std::cout << *po << std::endl;
    // std::cout << "n" << std::endl;
    // std::cout << "n" << std::endl;
    // for (ft::vector<int>::iterator it = van.begin(); it != van.end(); it++)
    //     std::cout << *it << std::endl;
    // std::cout << va.capacity() << "   lol"<< std::endl;
    // std::cout << va.size() << "   lol"<< std::endl;
    // std::cout << *po << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::vector<int> vo(5, 10);
    std::vector<int> vol;
    vol.push_back(1);
    vol.push_back(2);
    vol.push_back(3);
    vol.push_back(4);
    // vo.push_back(4);
    // vo.push_back(4);
    // vo.pop_back();
    // vo.assign(4, 5);
    // vo.reserve(100);
    // for (std::vector<int>::iterator it = vo.begin(); it != vo.end(); it++)
    //     std::cout << *it << std::endl;
    // std::cout << vo.capacity() << std::endl;
    std::vector<int> vop;
    vop.push_back(1);
    vop.push_back(2);
    vop.push_back(3);
    vop.push_back(4);
    // vop.push_back(5);
    //  std::vector<int>::iterator too = vop.erase(vop.begin());
    // for (std::vector<int>::iterator it = vop.begin(); it != vop.end(); it++)
    //     std::cout << *it << std::endl;
    // std::vector<int>::iterator tat = vop.erase(vop.begin(), vop.end());
    // for (std::vector<int>::iterator it = vop.begin(); it != vop.end(); it++)
    //     std::cout << *it << std::endl;
        // std::cout << vop.capacity() << std::endl;
    std::vector<int>::iterator pol = vop.insert(++vop.begin(),3);
    vop.insert(++vop.begin(),17,5);
    vop.insert(++vop.begin(),vo.begin(),--vo.end());
    std::cout << *vop.erase(vop.begin()) << "lol "<< std::endl;
    std::cout << *vop.erase(++vop.begin(),--vop.end()) << "lol"<< std::endl;
    std::cout << *pol << std::endl;
    std::cout << vop.capacity() << std::endl;
    vop.assign(vol.begin(), vol.end());
    std::cout << "n" << std::endl;
    for (std::vector<int>::iterator it = vop.begin(); it != vop.end(); it++)
        std::cout << *it << std::endl;
    std::cout << "n" << std::endl;
    std::stack<int, std::vector<int> > stank(vop);
    std::cout << vop.capacity() << std::endl;
    std::cout << stank.size() << " stack size" << std::endl;
    // while (1);
    return (0);
}
>>>>>>> 796a4f676054c8f30e8330ac0f1b0d1ec8c0d963
