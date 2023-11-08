#include <iostream>

using namespace std;

// This is a recursive function
int fact(int i)
{
    if (i < 0)
    {
        runtime_error err("Input cannot be a negative number");
        cout << err.what() << endl;
    }
    return i > 1 ? i * fact(i - 1) : 1;
}

// int fact(int i)
// {
//     int ret = 1;
//     while (i > 1)
//         ret *= i--;
//     return ret;
// }

int main()
{
    cout << fact(5) << endl;
    return 0;
}
