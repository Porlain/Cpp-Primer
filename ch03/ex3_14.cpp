#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers;
    int number;
    while (cin >> number)
    {
        numbers.push_back(number);
    }
    return 0;
}