#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    stack<string> words;
    for (string str; cin >> str; words.push(str))
        ;

    int maxcnt = 0, tempcnt = 0;
    string maxstr = "", tempstr = "";

    while (!words.empty())
    {
        string str = words.top();
        if (str == tempstr)
        {
            ++tempcnt;
            tempstr = str;
            if (tempcnt > maxcnt)
            {
                maxcnt = tempcnt;
                maxstr = tempstr;
            }
        }
        else
        {
            tempcnt = 0;
            tempstr = str;
        }
        words.pop();
    }
    cout << "the word " << maxstr << " occurred " << maxcnt + 1 << " times. " << endl;
    return 0;
}
