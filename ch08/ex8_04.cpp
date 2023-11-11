/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-11 14:37:59
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

int main()
{
    string filename = "../data/book.txt";
    ifstream in(filename);
    vector<string> books;
    if (in)
    {
        string book;
        while (std::getline(in, book))
        {
            books.push_back(book);
        }
    }

    for (const auto &str : books)
        cout << str << endl;

    return 0;
}