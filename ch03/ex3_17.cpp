#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> ivec;
    cout << "Please input words: " << endl;
    // Make letters uppercase
    for (string str; getline(cin, str); ivec.push_back(str))
        for (auto &s : str)
            s = toupper(s);

    // print worlds
    for (int i = 0; i < ivec.size(); i++)
    {
        for (auto s : ivec[i])
        {
            // if s is word or number, then print it, else \n
            if (isalnum(s))
                cout << s;
            else
                cout << endl;
        }
    }

    return 0;
}