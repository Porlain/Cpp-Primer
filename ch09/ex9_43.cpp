/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 15:19:13
 */
#include <string>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

void replace_with(string &s, const string oldval, const string newval)
{
    int oldsize = oldval.size();
    for (auto cur = s.begin(); cur != s.end() - oldsize;)
    {
        string temp(cur, cur + oldsize);
        if (oldval == temp)
        {
            cur = s.erase(cur, cur + oldsize);
            cur = s.insert(cur, newval.begin(), newval.end());
            cur += newval.size();
        }
        else
            ++cur;
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