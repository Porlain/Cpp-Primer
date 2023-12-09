/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-08 14:13:06
 */
#include "notquery.h"

inline Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

QueryResult NotQuery::eval(const TextQuery &t) const {}

std::string NotQuery::rep() const
{
    std::cout << "NotQuery::rep()\n";
    return "~(" + query.rep() + ")";
}
