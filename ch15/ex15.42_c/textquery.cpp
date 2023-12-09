/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-08 17:33:24
 */
#include "textquery.h"
#include <sstream>
#include <algorithm>

// In this file, we should create
// TextQuery(); QueryResult query(const std::string &) const; in class TextQuery
// std::ostream &print(std::ostream &, const QueryResult &);  in class QueryResult

// a constructor function, so we should input and save texts
// don't forget we also need to save map<string, shared_ptr<set<linenum>>>
TextQuery::TextQuery(std::ifstream &in) : texts(new vector<string>)
{
    for (string line; std::getline(in, line);)
    {
        texts->push_back(line);
        int n = texts->size() - 1;
        // next, we shoule save each word in line
        std::istringstream line_stream(line);
        for (string word, words; line_stream >> words; word.clear())
        {

            std::copy_if(words.begin(), words.end(), std::back_inserter(word), ::isalpha);
            // result is map<string, shared_ptr<set<linenum>>>, so num is shared_ptr<set<linenum>>
            auto &num = result[word];
            // if shared_ptr point to nullptr, then create and point to a new object
            // else insert the number of line
            if (!num)
                num.reset(new std::set<linenum>);
            num->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &str) const
{
    static std::shared_ptr<std::set<linenum>> nodata(new std::set<linenum>);
    // find return a pointer, which point to the found object
    // so, found is std::map<std::string, std::shared_ptr<std::set<linenum>>>
    // pay attention to the type of function, QueryResult
    // so, we should return an object of QueryResult, and construct it
    auto found = result.find(str);
    if (found == result.end())
        return QueryResult(str, texts, nodata);
    else
        return QueryResult(str, texts, found->second);
}

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
    os << "The result of your query " << qr.word << " is: \n";
    for (const auto &index : *qr.result)
        os << "\t(line " << index + 1 << ")"
           << *(qr.lines->begin() + index) << "\n";
    return os;
}

/*
Head is the first line of the range.
Trail is the last line of the range.
*/
std::ostream &print(std::ostream &os, const QueryResult &qr, size_t head, size_t trail)
{
    if (head > trail)
    {
        os << "illegal range!\n";
        return os;
    }
    else
    {
        os << "The result of your query " << qr.word << " is: \n";
        for (const auto &index : *qr.result)
        {
            if (index + 1 >= head && index + 1 <= trail)
            {
                os << "\t(line " << index + 1 << ")"
                   << *(qr.lines->begin() + index) << "\n";
            }
        }
        return os;
    }
}