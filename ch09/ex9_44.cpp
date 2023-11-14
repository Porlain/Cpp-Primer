/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 15:24:09
 */

#include <string>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

void replace_with(string &s, const string oldval, const string newval)
{
    int oldsize = oldval.size();
    for (int pos = 0; pos < s.size() - oldsize;)
    {
        if (s[pos] == oldval[0] && s.substr(pos, oldsize) == oldval)
        {
            s.replace(pos, oldsize, newval);
            pos += newval.size();
        }
        else
            ++pos;
    }
}

int main()
{
    string s{"To drive straight thru is a foolish, tho courageous act."};
    replace_with(s, "tho", "though");
    replace_with(s, "thru", "though");
    cout << s << endl;
    return 0;
}