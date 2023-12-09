/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-08 16:44:20
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
#include "queryhistory.cpp"

int main()
{
    std::ifstream fin("../../data/storyDataFile.txt");
    TextQuery text(fin);
    QueryHistory history;
    Query q0("Alice");
    Query q1("hair");
    Query q2("Daddy");

    history.add_query(q0);
    history.add_query(q1);
    history[0] = history[0] | q2;

    auto result = history[0].eval(text);
    std::cout << result;
    return 0;
}