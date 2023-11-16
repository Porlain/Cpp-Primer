/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-15 11:20:17
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

int main()
{
    vector<string> vs{"a", "v", "a", "s", "v", "a", "a"};
    print(vs);
    elimDups(vs);
    print(vs);
    cout << vs.size() << endl;
    cout << vs.capacity() << endl;
    return 0;
}