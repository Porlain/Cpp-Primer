/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-04 20:37:33
 */
// @See ex10_16.cpp
// note: When the public and private declarations are not displayed,
//       the class is private by default and the struct is public by default.
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

class Shorter
{
public:
    bool operator()(const string &s1, const string &s2) const
    {
        return s1.size() < s2.size();
    }
};

class BiggerEqual
{
    size_t sz;

public:
    BiggerEqual(size_t size) : sz(size) {}
    bool operator()(const string &str)
    {
        return str.size() >= sz;
    }

private:
};

class Print
{
public:
    void operator()(string const &s) { cout << s << " "; }
};

void biggies(vector<string> &word, vector<string>::size_type sz)
{
    elimDups(word);

    // sort by size, but maintain alphabetical order for same size.
    stable_sort(word.begin(), word.end(), Shorter());

    // get an iterator to the first one whose size() is >= sz
    auto wc = find_if(word.begin(), word.end(), BiggerEqual(sz));

    // print the biggies
    for_each(wc, word.end(), Print());
}

int main()
{
    vector<string> vs{"1234", "1234", "1234", "Hi", "alan", "wang"};

    biggies(vs, 3);

    cout << endl;
    return 0;
}