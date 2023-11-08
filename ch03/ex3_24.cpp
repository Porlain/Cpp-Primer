#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    // 3.20 question two
    vector<int> numbers;
    for (int i; cin >> i; numbers.push_back(i))
        ;
    
    if (numbers.size() < 1)
        cout << "Please input at least one number." << endl;

    for (auto beg = numbers.cbegin(), end = numbers.cend() - 1; beg <= end; beg++, end--)
        cout << *beg + *end << endl;
        
    return 0;
}