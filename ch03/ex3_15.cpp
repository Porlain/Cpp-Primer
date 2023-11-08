#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> numbers;
    for(string str;getline(cin,str);numbers.push_back(str));
    return 0;
}