/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamza <hamza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 21:28:08 by hmellahi          #+#    #+#             */
/*   Updated: 2021/07/21 14:37:55 by hamza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Stack.hpp"
#include "vector.hpp"
// #include <ft::vector>
int main2()
{
    // ft::stack<char> iterable_stack;
	// for (char letter = 'a'; letter <= 'z'; letter++)
	// 	iterable_stack.push(letter);
	// while (!iterable_stack.empty())
	// {
	// 	std::cout << iterable_stack.top() << " ";
	// 	iterable_stack.pop();
	// }
	// std::cout << std::endl;
	// for (ft::stack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	// // 	std::cout << *it;
	// ft::vector<int> mylist;
	// ft::vector<int> mylist;
	// mylist.pop_back(); will sigfault
	// std::cout << mylist.front();
	// set some initial content:
	// for (int i=0;i<10;i++) mylist.push_back(i);

	// mylist.resize(5);
	// mylist.resize(8,100);
	// mylist.resize(12, 7);
	// mylist.pop_back();
	// std::cout << "mylist contains:";
	// for (ft::vector<int>::iterator it = mylist.begin() ; it != mylist.end(); ++it)
    // 	std::cout << ' ' << *it;
	// std::cout << "\n-----\n";
	// for (ft::vector<int>::reverse_iterator it = mylist.rbegin() ; it != mylist.rend(); ++it)
    // 	std::cout << ' ' << *it;
	// mylist.front() -= mylist.back();

	// std::cout << "\nmylist.front() is now " << mylist.at(0) << '\n';
	// // mylist.push_back
	// std::cout << '\n';
	// int sum (0);
	// while (!mylist.empty())
	// {
	// 	sum+=mylist.back();
	// 	mylist.pop_back();
	// }

	// std::cout << "The elements of mylist add up to " << sum << '\n';

	// ft::vector<int> myvector;
	// int * p;
	// unsigned int i;

	// // allocate an array with space for 5 elements using ft::vector's allocator:
	// p = myvector.get_allocator().allocate(5);

	// // construct values in-place on the array:
	// for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

	// std::cout << "The allocated array contains:";
	// for (i=0; i<5; i++) std::cout << ' ' << p[i];
	// std::cout << '\n';

	// // destroy and deallocate:
	// for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	// myvector.get_allocator().deallocate(p,5);


    // ft::vector<std::string> inventory;
    // inventory.push_back("inventory1");
    // inventory.push_back("inventory2");
    // inventory.push_back("inventory3");
    // ft::vector<std::string>::iterator myIterator = inventory.begin();
    // ft::vector<std::string>::const_iterator iter;
//     std::cout << "Your items:\n";
// 	ft::vector<int> myvector;
//   for (int i=1; i<=5; i++) myvector.push_back(i);
// #include <typeinfo>
//   std::cout << "myvector contains:";
// //   for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
//     // std::cout << ' ' << *it;
//   std::cout << *( myvector.begin() + 3) << '\n';

	// iter = inventory.begin();
	// myIterator = inventory.begin();
    // for (; iter != inventory.end(); iter++)
    // {
    //    std::cout << *iter << std::endl;
    // }
	// iter = myIterator;
	// *myIterator = "hey";
	//  std::cout << "myvector contains:";
  	// for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    // std::cout << ' ' << *it;
  	// std::cout << '\n';
	// *iter = "hey";

	//  ft::vector<int> first;                                // empty ft::vector of ints
	ft::vector<int> first;
	ft::vector<int> second;
    ft::vector<int> third;

  first.assign(7,4);             // 7 ints with a value of 100
	for (ft::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
    std::cout << ' ' << *it;
	std::cout << "\n";
  ft::vector<int>::iterator it;
  it=first.begin() + 1;

//   second.assign (it,first.end()-1); // the 5 central values of first

//   int myints[] = {1776,7,4}; // fix
//   third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';
//   ft::vector<int> second (4,100);                      // four ints with value 100
//   ft::vector<int> third (mylist.begin(),mylist.end());  // iterating through second
//   ft::vector<int> fourth (third);                       // a copy of third

//   // the iterator constructor can also be used to construct from arrays:
//   int myints[] = {16,2,77,29};
//   ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

//   std::cout << "The contents of fifth are:";
//   for (ft::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
//     std::cout << ' ' << *it;
//   try {
// 	  std::cout << third.at(100) <<'\n';
//   }
//   catch(std::exception &e)
//   {
// 	  std::cout << e.what();
//   }

//   ft::vector<int> foo (3,100);   // three ints with a value of 100
//   ft::vector<int> bar (5,200);   // five ints with a value of 200
// std::cout << &bar << std::endl;
//   std::cout << &foo << std::endl;
//   foo.swap(bar);

//   std::cout << "foo contains:";
//   for (unsigned i=0; i<foo.size(); i++)
//     std::cout << ' ' << foo[i];
//   std::cout << '\n';

//   std::cout << "bar contains:";
//   for (unsigned i=0; i<bar.size(); i++)
//     std::cout << ' ' << bar[i];
//   std::cout << '\n';
//   std::cout << &bar << std::endl;
//   std::cout << &foo << std::endl;

//  unsigned int i;
//   ft::vector<int> foo (3,100);   // three ints with a value of 100
//   ft::vector<int> bar (5,200);   // five ints with a value of 200
// //   foo.swap(bar);
// swap(foo, bar);

//   std::cout << "foo contains:";
//   for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   std::cout << "bar contains:";
//   for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

  ft::vector<int> myvector;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) myvector.push_back(i);

  // erase the 6th element
  myvector.erase (myvector.begin() + 5);

  // erase the first 3 elements:
  myvector.erase (myvector.begin(),myvector.begin()+3);

  std::cout << "myvector contains:" << myvector.capacity() << "\n";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
	// ft::vector<int> myvector;
//   myvector.push_back (100);
//   myvector.push_back (200);
//   myvector.push_back (300);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   myvector.clear();
//     std::cout << ' ' << myvector.size() << "::"<< myvector.capacity() << std::endl;

//   myvector.push_back (1101);
//   myvector.push_back (2202);

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
#include <vector>
#define TESTED_NAMESPACE std
#define TESTED_TYPE int

void	is_empty(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct)
{
	std::cout << "is_empty: " << vct.empty() << std::endl;
}

int		main(void)
{
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
	return (0);
}
