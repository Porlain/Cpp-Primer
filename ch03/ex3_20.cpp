#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers;
    cout << "Please input numbers: " << endl;
    for (int i = 0; cin >> i; numbers.push_back(i))
        ;
    if (numbers.empty())
    {
        cout << "input at least one integer." << endl;
        return -1;
    }

    if (numbers.size() == 1)
    {
        cout << "only one integer " << numbers[0] << ", it doesn't have any adjacent elements." << endl;
        return -1;
    }
    // ========================================================================================================================
    // question one
    for (int i = 0; i < numbers.size() - 1; ++i)
        cout << numbers[i] + numbers[i + 1] << endl;

    // ========================================================================================================================
    // question two
    // int number_size = numbers.size();
    // int i = 0;
    // for (; i < number_size / 2; i++)
    // {
    //     cout << numbers[i] + numbers[number_size - i - 1] << endl;
    // }
    // // if number_size is a odd number, element in the middle will add to itself.
    // if (number_size % 2 == 1)
    // {
    //     cout << numbers[i] * numbers[i] << endl;
    // }

    return 0;
}