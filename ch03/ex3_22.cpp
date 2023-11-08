#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> text;
    for (string str; getline(cin, str); text.push_back(str))
        ;

    for (auto &word : text)
    {
        for (auto &it : word)
        {
            if (isalnum(it))
                it = toupper(it);
        }
        cout << word << endl;
    }

    return 0;
}