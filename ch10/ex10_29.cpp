/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-16 11:12:32
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream inf("../data/book.txt");
    istream_iterator<string> in(inf), eof;
    vector<string> vec;

    copy(in, eof, inserter(vec, vec.begin()));

    copy(vec.cbegin(), vec.cend(), ostream_iterator<string>(cout, "\n"));
    return 0;
}