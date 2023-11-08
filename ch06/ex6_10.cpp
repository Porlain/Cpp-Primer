#include <iostream>
using namespace std;

void swap(int *p, int *p1)
{
    int temp = *p;
    *p = *p1;
    *p1 = temp;
}

int main()
{
    int a = 10, b = 5;
    int *p = &a, *p1 = &b;
    // swap(&a, &b);
    swap(p, p1);
    cout << "a = " << a << " "
         << "b = " << b << endl;
    return 0;
}
