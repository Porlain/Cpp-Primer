/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 17:01:23
 */
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

string longest_word_allow(const string word, string str)
{
    string str_allow{"aceimnorsuvwxz"};
    if (string::npos == word.find_first_not_of(str_allow))
        if (word.size() > str.size())
            str = word;

    return str;
}

int main()
{
    ifstream ifs("../data/letter.txt");
    if (!ifs)
        return -1;
    string str = "";
    for (string cur; ifs>>cur;str = longest_word_allow(cur, str));

    cout << str << endl;

    return 0;
}