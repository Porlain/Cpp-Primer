/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-28 16:15:13
 */
#ifndef CP5_TEXTQUERY_H_
#define CP5_TEXTQUERY_H_
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include <map>
#include <set>

#include "ex13_42_StrVec.cpp"

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
    shared_ptr<StrVec> texts;
    std::map<string, shared_ptr<std::set<linenum>>> result;
};

// QueryResult contains functions for constructors and print result
class QueryResult
{
public:
    friend std::ostream &print(std::ostream &, const QueryResult &);
    QueryResult(const string &w, shared_ptr<StrVec> li, shared_ptr<std::set<TextQuery::linenum>> re) : word(w), lines(li), result(re) {}

private:
    string word;
    shared_ptr<StrVec> lines;
    shared_ptr<std::set<TextQuery::linenum>> result;
};
// To maintain readability,
// it is best to store the header file and the function implementation supported by the class separately
// So, we will create implementation.cpp file
#endif