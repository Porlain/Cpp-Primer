/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-08 14:33:10
 */
#ifndef ANDQUERY_H
#define ANDQUERY_H

#include "binaryquery.h"

class AndQuery : public BinaryQuery
{
public:
    friend Query operator&(const Query &, const Query &);
    AndQuery(const Query &l, const Query &r) : BinaryQuery(l, r, "&") { std::cout << "AndQuery::AndQuery()\n"; }

    QueryResult eval(const TextQuery &) const override;
};

#endif