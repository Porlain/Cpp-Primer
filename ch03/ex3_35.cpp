#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    for (auto i = 0; i < 10; ++i)
        arr[i] = i;

    for (auto p = arr; p != arr + 10; ++p)
        *p = 0;

    for (auto i : arr) cout << i << " ";
    return 0;
}
