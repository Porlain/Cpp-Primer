/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-22 16:24:41
 */
#ifndef CP5_ex12_27_h
#define CP5_ex12_27_h
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
using std::shared_ptr;
using std::string;
using std::vector;

// declare QueryResult to create a query function
class QueryResult;

// TextQuery contains functions for constructors and query words
class TextQuery
{
public:
    using linenum = vector<string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(const string &) const;

private:
    shared_ptr<vector<string>> texts;
    std::map<string, shared_ptr<std::set<linenum>>> result;
};

// QueryResult contains functions for constructors and print result
class QueryResult
{
public:
    friend std::ostream &print(std::ostream &, const QueryResult &);
    QueryResult(const string &w, shared_ptr<vector<string>> li, shared_ptr<std::set<TextQuery::linenum>> re) : word(w), lines(li), result(re) {}

private:
    string word;
    shared_ptr<vector<string>> lines;
    shared_ptr<std::set<TextQuery::linenum>> result;
};
// To maintain readability,
// it is best to store the header file and the function implementation supported by the class separately
// So, we will create implementation.cpp file
#endif