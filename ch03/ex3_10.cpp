#include <iostream>
#include <string>
using namespace std;

int main()
{
    // string str("Hello, world!");
    // for (int i = 0; i < str.size(); i++)
    //     if (!ispunct(str[i]))
    //         cout << str[i] << endl;
    for (string str; getline(cin, str);)
        for (auto i : str)
        {
            if (!ispunct(i))
                cout << i << endl;
        }
    return 0;
}