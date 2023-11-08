#include <iostream>
using namespace std;
int main()
{
    int a = 0, b = 1;
    int *p1 = &a, *p2 = &b;

    // change the value to which the pointer points
    *p1 = 10;
    cout << *p1 << endl;
    // change the value of a pointer.
    p2 = p1;
    cout << *p2 << endl;
    
    cout << a << " " << b << endl;
    return 0;
}
