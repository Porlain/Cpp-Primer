/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 13:49:07
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
