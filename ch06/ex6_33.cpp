#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>::const_iterator beg, vector<int>::const_iterator end)
{
    if (beg != end)
    {
        cout << *beg << " ";
        print(++beg, end);
    }
}

int main()
{
    vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(list.begin(), list.end());
    return 0;
}

