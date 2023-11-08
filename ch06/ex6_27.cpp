#include <iostream>
#include <initializer_list>
using namespace std;

int sum(initializer_list<int> list)
{
    int sum = 0;
    for (auto it : list)
        sum += it;
    return sum;
}

int main()
{
    auto il = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    cout << sum(il) << endl;
    return 0;
}
