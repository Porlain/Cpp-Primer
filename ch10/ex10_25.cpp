/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-15 16:50:58
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;
using namespace std::placeholders;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto new_ends = unique(words.begin(), words.end());
    words.erase(new_ends, words.end());
}

bool check_size(const string &str, size_t sz)
{
    return str.size() >= sz;
}

void biggies(vector<string> &word, vector<string>::size_type sz)
{
    elimDups(word);

    // only here
    auto wc = partition(word.begin(), word.end(), bind(check_size, _1, sz));

    for_each(
        word.begin(), wc, [](const string &str)
        { cout << str << " "; });
}

int main()
{
    vector<string> vs{"1234", "1234", "1234", "Hi", "alan", "wang"};

    biggies(vs, 3);

    cout << endl;
    return 0;
}