#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str("Hello, world!");
    for (auto &s : str)
    {
        // notice 'X' rather than "X","X" is a string, end with '\0', the string in the memory is "X\0"
        // 'x' is a char,end with 'x', the char in the memory is 'x'
        // s is a char rather than a string
        s = 'X';
    }
    cout << str << endl;
    return 0;
}