#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<unsigned int> scores(11, 0);
    unsigned grade;
    while (cin >> grade)
    {
        if (grade <= 100)
            // remember add *, which can change the score
            *(scores.begin() + (grade / 10)) += 1;
    }

    for (auto s : scores)
        cout << s << " ";
    return 0;
}