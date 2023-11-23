/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-22 16:55:25
 */
#include "ex12_27.h"
#include "ex12_27_sup.cpp"
#include <iostream>
using namespace std;

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }
}

int main()
{
    ifstream file("../data/storyDataFile.txt");
    runQueries(file);
}