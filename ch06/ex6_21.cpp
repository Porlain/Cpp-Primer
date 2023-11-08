#include <iostream>
using namespace std;

int large(const int i, const int *p)
{
    return i > (*p) ? i : (*p);
}

int main()
{
    int a = 10;
    cout << large(6, &a) << endl;
    return 0;
}
