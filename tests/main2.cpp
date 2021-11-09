
#include <iostream>
// #include <time.h>
#include <sys/time.h>
#if NS
#define NAMESPACE "FT  : "
#include "../src/vector.hpp"
#include "../src/stack.hpp"
#include "../src/map.hpp"
#else
#define NAMESPACE "STD : "
#include <vector>
#include <stack>
#include <map>
namespace ft = std;
#endif

int main()
{
    ft::vector<int> myvector;
    int sum (0);
    myvector.push_back (100);
    myvector.push_back (200);
    myvector.push_back (300);

    while (!myvector.empty())
    {
        sum+=myvector.back();
        myvector.pop_back();
    }

    std::cout << "The elements of myvector add up to " << sum << '\n';
}