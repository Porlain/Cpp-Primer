/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-08 16:20:02
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

int main()
{
    std::ifstream file("../../data/storyDataFile.txt");

    TextQuery tQuery(file);

    Query q = Query("fieryzzz") | Query("wind");

    std::cout << q.eval(tQuery);
    return 0;
}