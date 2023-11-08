#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    for (int score; cin >> score;)
    {
        cout << ((score < 60) ? scores[0] : (scores[(score - 50) / 10])) << endl;
    }

    return 0;
}