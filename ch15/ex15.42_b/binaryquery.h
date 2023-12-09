/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-08 14:32:53
 */
#ifndef BINARYQUERY_H
#define BINARYQUERY_H
#include "query_base.h"
#include "query.h"

class BinaryQuery : public Query_base
{
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s) : lhs(l), rhs(r), opSym(s) { std::cout << "BinaryQuery::BinaryQuery()  where s=" + s + "\n"; }
    std::string rep() const override;

    Query lhs, rhs;
    std::string opSym;
};
#endif
