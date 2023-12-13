/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-13 14:15:04
 * @See ex12_27.h
 */
#ifndef TEXTQUERY_H_
#define TEXTQUERY_H_
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

#include "DebugDelete.h"

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

TextQuery::TextQuery(std::ifstream &in) : texts(new vector<string>)
{

    for (string line; std::getline(in, line);)
    {
        texts->push_back(line);
        int n = texts->size() - 1;
        std::istringstream line_stream(line);
        for (string word, words; line_stream >> words; word.clear())
        {
            std::copy_if(words.begin(), words.end(), std::back_inserter(word), ::isalpha);
            auto &num = result[word];
            if (!num)
                num.reset(new std::set<linenum>, DebugDelete()); // only here
            num->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &str) const
{
    static std::shared_ptr<std::set<linenum>> nodata(new std::set<linenum>);
    auto found = result.find(str);
    if (found == result.end())
        return QueryResult(str, texts, nodata);
    else
        return QueryResult(str, texts, found->second);
}

std::ostream &print(std::ostream &out, const QueryResult &qr)
{
    out << qr.word << " occurs: " << qr.result->size() << (qr.result->size() > 1 ? " times" : " time") << std::endl;
    for (auto i : *qr.result)
        out << "\t(line " << i + 1 << ") " << qr.lines->at(i) << std::endl;
    return out;
}

#endif