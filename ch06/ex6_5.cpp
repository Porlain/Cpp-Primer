#include <iostream>
using namespace std;

int abs(int i)
{
    return i > 0 ? i : -i;
}

int main()
{   
    cout << abs(-5) << endl;
    return 0;
}
