#ifndef CP5_ex12_32_h
#define CP5_ex12_32_h
#include "ex12_22.h"
#include <iostream>
#include <fstream>
#include <map>
#include <set>
using std::shared_ptr;
class QueryResult;

// TextQuery contains functions for constructors and query words
class TextQuery
{
public:
    TextQuery(std::ifstream &);
    QueryResult query(const string &) const;

private:
    StrBlob texts;
    std::map<string, shared_ptr<std::set<StrBlob::size_type>>> result;
};

// QueryResult contains functions for constructors and print result
class QueryResult
{
public:
    friend std::ostream &print(std::ostream &, const QueryResult &);
    QueryResult(const string &w, StrBlob li, shared_ptr<std::set<StrBlob::size_type>> re) : word(w), lines(li), result(re) {}

private:
    string word;
    StrBlob lines;
    shared_ptr<std::set<StrBlob::size_type>> result;
};

#endif