#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto number = numbers.begin(); number != numbers.end(); ++number)
        *number *= 2;

    for (auto num : numbers)
        cout << num << endl;
    return 0;
}