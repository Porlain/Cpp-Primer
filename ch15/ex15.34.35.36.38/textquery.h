/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-07 20:33:19
 */
#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include "StrBlob.cpp"
#include <iostream>
#include <fstream>
#include <map>
#include <set>
using std::shared_ptr;
class QueryResult;

class TextQuery
{
public:
    TextQuery(std::ifstream &);
    QueryResult query(const string &) const;

private:
    StrBlob texts;
    std::map<string, shared_ptr<std::set<StrBlob::size_type>>> result;
};

class QueryResult
{
public:
    using ResultIter = std::set<StrBlob::size_type>::iterator;
    friend std::ostream &print(std::ostream &, const QueryResult &);
    QueryResult(const string &w, StrBlob li, shared_ptr<std::set<StrBlob::size_type>> re) : word(w), lines(li), result(re) {}

public:
    ResultIter begin() const { return result->begin(); }
    ResultIter end() const { return result->end(); }
    shared_ptr<StrBlob> get_file() const { return std::make_shared<StrBlob>(lines); }

private:
    string word;
    StrBlob lines;
    shared_ptr<std::set<StrBlob::size_type>> result;
};

#endif