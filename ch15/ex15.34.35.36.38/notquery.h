#ifndef NOTQUERY_H
#define NOTQUERY_H
#include "query_base.h"
#include "query.h"

class NotQuery : public Query_base
{
public:
    friend Query operator~(const Query &operand);

public:
    NotQuery(const Query &q) : query(q) { std::cout << "NotQuery::NotQuery()\n"; }

    // virtuals:
    QueryResult eval(const TextQuery &) const override;
    std::string rep() const override;

    Query query;
};
#endif