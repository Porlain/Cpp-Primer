#include <iostream>
using namespace std;

void print(const int i)
{
    cout << i << endl;
}

void print(const int arr[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
    {
        cout << arr[i] << endl;
    }
}

void print(const int *beg, const int *end)
{
    while (beg != end)
    {
        cout << *beg++ << endl;
    }
}

void print(const int (&arr)[2])
{
    for (auto a : arr)
        cout << a << endl;
}

void print(const char *p)
{
    // if point is not null
    if (p)
    {
        // if the val of point is not '\0'
        while (*p)
            cout << *p++ << endl;
    }
}

int main()
{
    int i = 0, j[2] = {0, 1};
    print(i);
    print(j, end(j) - begin(j));
    print(begin(j), end(j));
    print(j);

    // if you want to print char, notice '\0' at the end of char
    char ch[8] = "porlain";
    print(ch);
    return 0;
}
