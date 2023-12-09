/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-08 15:19:28
 */
#include "andquery.h"
#include <algorithm>

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

QueryResult AndQuery::eval(const TextQuery &t) const
{
    QueryResult left = lhs.eval(t), right = rhs.eval(t);
    auto ret_lines = std::make_shared<std::set<line_no>>();

    std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));

    auto a = left.get_file(); 
    return QueryResult(rep(), left.get_file(), ret_lines);
}