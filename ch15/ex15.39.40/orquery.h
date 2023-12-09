#ifndef ORQUERY_H
#define ORQUERY_H
#include "binaryquery.h"

class OrQuery : public BinaryQuery
{
public:
    friend Query operator|(const Query &, const Query &);

    OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|") { std::cout << "OrQuery::OrQuery\n"; }

    QueryResult eval(const TextQuery &) const override;
};
#endif