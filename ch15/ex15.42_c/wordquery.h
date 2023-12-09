#ifndef WORDQUERY_H
#define WORDQUERY_H

#include "query_base.h"

class WordQuery :public Query_base
{
    friend class Query;
    WordQuery(const std::string &s) : query_word(s) { std::cout << "WordQuery::WordQuery(" + s + ")\n"; }

    // virtual
    QueryResult eval(const TextQuery &) const override;
    std::string rep() const override;

    std::string query_word;
};
#endif