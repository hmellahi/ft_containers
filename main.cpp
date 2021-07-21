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
#include "Vector.hpp"
#include <vector>
int main()
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
	// vector<int> mylist;
	// vector<int> mylist;
	// mylist.pop_back(); will sigfault
	// std::cout << mylist.front();
	// set some initial content:
	// for (int i=0;i<10;i++) mylist.push_back(i);

	// mylist.resize(5);
	// mylist.resize(8,100);
	// mylist.resize(12, 7);
	// mylist.pop_back();
	// std::cout << "mylist contains:";
	// for (Vector<int>::iterator it = mylist.begin() ; it != mylist.end(); ++it)
    // 	std::cout << ' ' << *it;
	// std::cout << "\n-----\n";
	// for (Vector<int>::reverse_iterator it = mylist.rbegin() ; it != mylist.rend(); ++it)
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

	// Vector<int> myvector;
	// int * p;
	// unsigned int i;

	// // allocate an array with space for 5 elements using vector's allocator:
	// p = myvector.get_allocator().allocate(5);

	// // construct values in-place on the array:
	// for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

	// std::cout << "The allocated array contains:";
	// for (i=0; i<5; i++) std::cout << ' ' << p[i];
	// std::cout << '\n';

	// // destroy and deallocate:
	// for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	// myvector.get_allocator().deallocate(p,5);


    // Vector<std::string> inventory;
    // inventory.push_back("inventory1");
    // inventory.push_back("inventory2");
    // inventory.push_back("inventory3");
    // vector<std::string>::iterator myIterator = inventory.begin();
    // vector<std::string>::const_iterator iter;
//     std::cout << "Your items:\n";
// 	vector<int> myvector;
//   for (int i=1; i<=5; i++) myvector.push_back(i);
// #include <typeinfo>
//   std::cout << "myvector contains:";
// //   for (vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
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
  	// for (Vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    // std::cout << ' ' << *it;
  	// std::cout << '\n';
	// *iter = "hey";

	//  vector<int> first;                                // empty vector of ints
	vector<int> first;
	vector<int> second;
    vector<int> third;

  first.assign(7,4);             // 7 ints with a value of 100
	for (vector<int>::iterator it = first.begin(); it != first.end(); ++it)
    std::cout << ' ' << *it;
	std::cout << "\n";
  vector<int>::iterator it;
  it=first.begin() + 1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';
//   vector<int> second (4,100);                      // four ints with value 100
//   vector<int> third (mylist.begin(),mylist.end());  // iterating through second
//   vector<int> fourth (third);                       // a copy of third

//   // the iterator constructor can also be used to construct from arrays:
//   int myints[] = {16,2,77,29};
//   vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

//   std::cout << "The contents of fifth are:";
//   for (vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
//     std::cout << ' ' << *it;
//   try {
// 	  std::cout << third.at(100) <<'\n';
//   }
//   catch(std::exception &e)
//   {
// 	  std::cout << e.what();
//   }

//   vector<int> foo (3,100);   // three ints with a value of 100
//   vector<int> bar (5,200);   // five ints with a value of 200
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
//   vector<int> foo (3,100);   // three ints with a value of 100
//   vector<int> bar (5,200);   // five ints with a value of 200
// //   foo.swap(bar);
// swap(foo, bar);

//   std::cout << "foo contains:";
//   for (vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   std::cout << "bar contains:";
//   for (vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   vector<int> myvector;

//   // set some values (from 1 to 10)
//   for (int i=1; i<=10; i++) myvector.push_back(i);

//   // erase the 6th element
//   myvector.erase (myvector.begin() + 5);

//   // erase the first 3 elements:
//   myvector.erase (myvector.begin(),myvector.begin()+3);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); ++i)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';
	vector<int> myvector;
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  myvector.clear();
    std::cout << ' ' << myvector.size() << "::"<< myvector.capacity() << std::endl;

  myvector.push_back (1101);
  myvector.push_back (2202);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

//   vector<int> foo (3,0);
//   vector<int> bar (5,0);

//   bar = foo;
//   foo = vector<int>();

//   std::cout << "Size of foo: " << int(foo.size()) << '\n';
//   std::cout << "Size of bar: " << int(bar.size()) << '\n';

//  	vector<int> foo (3,100);   // three ints with a value of 100
//   	vector<int> bar (3,300);   // two ints with a value of 200

//   if (foo==bar) std::cout << "foo and bar are equal\n";
//   if (foo!=bar) std::cout << "foo and bar are not equal\n";
//   if (foo< bar) std::cout << "foo is less than bar\n";
//   if (foo> bar) std::cout << "foo is greater than bar\n";
//   if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//   if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
// vector<int> first2;                                // empty vector of ints
//   vector<int> second2 (4,100);                       // four ints with value 100
//   vector<int> third3 (second.begin(),second.end());  // iterating through second
// //   vector<int> fourth (third);                       // a copy of third

//   // the iterator constructor can also be used to construct from arrays:
//   int myints2[] = {16,2,77,29};
//   vector<int> fifth (myints2, myints2 + sizeof(myints2) / sizeof(int) );

//   std::cout << "The contents of fifth are:";
//   for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

}
