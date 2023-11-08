#include <iostream>
#include <string>
using namespace std;

int fact(int i)
{
    return i > 1 ? i * fact(i - 1) : 1;
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

int main()
{
    int val;
    bool gate = true;
    while (gate)
    {
        cout << "Please input value:";
        cin >> val;
        cout << "The factorial of val is:" << fact(val) << endl;

        gate = is_continue();
    }
    return 0;
}
