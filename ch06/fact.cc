#include <iostream>
#include <string>
#include "Chapter6.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;

int fact(int val)
{
    if (val < 1)
        return 1;
    else
        return val * fact(val - 1);
}

bool is_continue()
{
    string str;
    cout << "Do you want to continue?(yes/no)";
    cin >> str;
    if (str == "yes" || str == "y")
        return true;
    else
        return false;
}

int abs(int i)
{
    return i > 0 ? i : -i;
}