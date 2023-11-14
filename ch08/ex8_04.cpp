/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-14 13:48:31
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