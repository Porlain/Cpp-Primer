#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    for (int score; cin >> score;)
    {
        if (score < 60)
            cout << scores[0] << endl;
        else
        {
            score = (score - 50) / 10;
            cout << scores[score] << endl;
        }
    }

    return 0;
}