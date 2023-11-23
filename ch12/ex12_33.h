/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-11-23 10:15:39
 */
#ifndef CP5_ex12_33_h
#define CP5_ex12_33_h
#include "ex12_22.h"
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