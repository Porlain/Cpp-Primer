/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-15 13:59:22
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
void print(vector<string> const &vec); // declare the function

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    print(words);
    auto new_ends = unique(words.begin(), words.end());
    print(words);
    words.erase(new_ends, words.end());
}

void print(vector<string> const &vec)
{
    for (auto i : vec)
        cout << i << " ";

    cout << endl;
}

inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    vector<string> vs{"1234", "1234", "1234", "Hi", "alan", "wang"};
    print(vs);

    elimDups(vs);
    print(vs);

    stable_sort(vs.begin(), vs.end(), isShorter);
    print(vs);
    
    cout << vs.size() << endl;
    cout << vs.capacity() << endl;
    return 0;
}