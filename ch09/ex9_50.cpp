#include <iostream>
#include <string>
#include <vector>
using namespace std;

int sum_for_int(vector<string> const &vec)
{
    int sum = 0;
    for (auto const &s : vec)
        sum += stoi(s);

    return sum;
}

float sum_for_float(vector<string> const &vec)
{
    float sum = 0.0;
    for (auto const &s : vec)
        sum += stof(s);

    return sum;
}

int main()
{
    vector<string> vec = {"1", "2", "3", "4.5"};
    cout << sum_for_int(vec) << endl;
    cout << sum_for_float(vec) << endl;

    return 0;
}