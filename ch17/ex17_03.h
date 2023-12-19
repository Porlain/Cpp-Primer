/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-19 11:00:03
 * @See ex12_27
 * @Answer:The orignal way is more formal.The second way is quick to implement, but hard to refactor. So the second way is better for testing.
 */
#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>
#include <sstream>
using std::get;
using std::shared_ptr;
using std::string;
using std::vector;

class TextQuery
{
public:
    using linenum = vector<string>::size_type;
    TextQuery(std::ifstream &);
    std::tuple<string, shared_ptr<vector<string>>, shared_ptr<std::set<TextQuery::linenum>>> query(const string &) const;

private:
    shared_ptr<vector<string>> texts;
    std::map<string, shared_ptr<std::set<linenum>>> result;
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
                num.reset(new std::set<linenum>);
            num->insert(n);
        }
    }
}

std::tuple<string, shared_ptr<vector<string>>, shared_ptr<std::set<TextQuery::linenum>>> TextQuery::query(const std::string &str) const
{
    static std::shared_ptr<std::set<linenum>> nodata(new std::set<linenum>);
    auto found = result.find(str);
    if (found == result.end())
        return std::tuple<string, shared_ptr<vector<string>>, shared_ptr<std::set<TextQuery::linenum>>>(str, texts, nodata);
    else
        return std::tuple<string, shared_ptr<vector<string>>, shared_ptr<std::set<TextQuery::linenum>>>(str, texts, found->second);
}

std::ostream &print(std::ostream &out, const std::tuple<string, shared_ptr<vector<string>>, shared_ptr<std::set<TextQuery::linenum>>> &qr)
{

    out << get<0>(qr) << " occurs: " << get<2>(qr)->size() << (get<2>(qr)->size() > 1 ? " times" : " time") << std::endl;
    for (auto i : *get<2>(qr))
    {
        out << "\t(line " << i + 1 << ") " << get<1>(qr)->at(i) << std::endl;
    }
    return out;
}