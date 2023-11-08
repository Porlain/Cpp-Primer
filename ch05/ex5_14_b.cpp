#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> words;
    for (string str; cin >> str; words.push_back(str))
        ;

    int maxcnt = 0, tempcnt = 0;
    string maxstr = "", tempstr = "";

    for(int i=0;i<words.size();++i){
    
        string str = words[i];
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
    }
    cout << "the word " << maxstr << " occurred " << maxcnt + 1 << " times. " << endl;
    return 0;
}
