/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-09 10:48:42
 */
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "query.cpp"
#include "andquery.cpp"
#include "orquery.cpp"
#include "notquery.cpp"
#include "textquery.cpp"
#include "binaryquery.cpp"
#include "wordquery.cpp"

using std::cout;
using std::endl;

int main()
{

    std::ifstream fin("../../data/storyDataFile.txt");
    TextQuery text(fin);
    auto q = ~Query("Alice");

    auto result = q.eval(text);
    print(cout, result);
    cout << endl;
    print(cout, result, -3, 5);
    cout << endl;
    print(cout, result, 3, 5);
    cout << endl;
    print(cout, result, 3, 20);
    cout << endl;
    return 0;
}