#include "vec.h"
#include <vector>
#include <iostream>

int main()
{
    Vec<int> v = { 1, 2, 3, 4, 5 };

    std::cout << v.capacity() << "\n";
    Vec<int> v2;

    v2 = v;
    std::cout << v2.capacity() << "\n";
    v2.push_back(99);
    v2.resize(2, 2);

    for (auto t : v2)
        std::cout << t << " ";


    std::cout << v2.capacity() << "\n";

    return 0;
}
