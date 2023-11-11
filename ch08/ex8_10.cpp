/*
 * @Author: Porlain szbj2023@163.com
 * @Date: 2023-11-11 15:16:00
 *
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

int main()
{
    // read data and save to vector
    string filename = "../data/book.txt";
    ifstream in(filename);
    vector<string> books;
    if (in)
    {
        string book;
        while (getline(in, book))
        {
            books.push_back(book);
        }
    }

    // using istringstream to read
    for (const auto &str : books)
    {
        istringstream iss(str);
        string word;
        while (iss >> word)
            cout << word << endl;
    }

    return 0;
}
