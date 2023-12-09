/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-08 17:23:44
 */
#include "textquery.h"
#include <sstream>
#include <algorithm>

// In this file, we should create
// TextQuery(); QueryResult query(const std::string &) const; in class TextQuery
// std::ostream &print(std::ostream &, const QueryResult &);  in class QueryResult

// a constructor function, so we should input and save texts
// don't forget we also need to save map<string, shared_ptr<set<linenum>>>
TextQuery::TextQuery(std::ifstream &in)
{

    for (string line; std::getline(in, line);)
    {
        texts.push_back(line);
        int n = texts.size() - 1;
        std::istringstream line_stream(line);
        for (string word, words; line_stream >> words; word.clear())
        {
            std::copy_if(words.begin(), words.end(), std::back_inserter(word), ::isalpha);
            auto &num = result[word];
            if (!num)
                num.reset(new std::set<StrBlob::size_type>);
            num->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &str) const
{
    static std::shared_ptr<std::set<StrBlob::size_type>> nodata(new std::set<StrBlob::size_type>);

    auto found = result.find(str);
    if (found == result.end())
        return QueryResult(str, texts, nodata);
    else
        return QueryResult(str, texts, found->second);
}

std::ostream &operator<<(std::ostream &os, const QueryResult &qr)
{
    os << qr.word << " occurs " << qr.result->size() << " "
       << "times"
       << "\n";

    // print each line in which the word appears
    for (auto &index : *qr.result)
    {
        os << "\t(line " << index + 1 << ") ";
        const StrBlobPtr wp(qr.lines, index);
        os << wp.deref() << "\n";
    }
    return os;
}
