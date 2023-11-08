#include <iostream>
#include <string>
using namespace std;

int main()
{

    // ===================================================================================================
    // question one
    string str1, str2;
    cin >> str1 >> str2;
    if (str1 == str2)
    {
        cout << "The two strings are equal." << endl;
    }
    // if you want to use concise code
    // else
    //     cout << "The larger string is " << ((str1 > str2) ? str1 : str2);
    else if (str1 > str2)
    {
        cout << "The larger string is " << str1 << endl;
    }
    else
    {
        cout << "The larger string is " << str2 << endl;
    }

    // ===================================================================================================
    // question two
    // string str3, str4;
    // cin >> str3 >> str4;
    // if (str3.size() == str4.size())
    // {
    //     cout << "The two strings have the same length." << endl;
    // }
    // else
    //     cout << "The larger string is " << ((str3 > str4) ? str3 : str4);

    return 0;
}