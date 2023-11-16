/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-15 15:06:47
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto new_ends = unique(words.begin(), words.end());
    words.erase(new_ends, words.end());
}

void biggies(vector<string> &word, vector<string>::size_type sz)
{
    elimDups(word);

    // sort by size, but maintain alphabetical order for same size.
    stable_sort(word.begin(), word.end(), [](const string &s1, const string &s2)
                { return s1.size() < s2.size(); });

    // get an iterator to the first one whose size() is >= sz
    auto wc = partition(word.begin(), word.end(), [sz](const string &str)
                        { return str.size() >= sz; });

    // print the biggies
    // only here is different
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