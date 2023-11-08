#include <iostream>
#include <string>
using namespace std;

inline bool is_shorter(const string &lft, const string &rht) // defining in the header is better.
{
    return lft.size() < rht.size();
}

int main()
{
    cout << is_shorter("porlain", "mooophy") << endl;
    return 0;
}