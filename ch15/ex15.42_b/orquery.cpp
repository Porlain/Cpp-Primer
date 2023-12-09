/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-08 16:01:57
 */
#include "orquery.h"

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery &t) const
{
    QueryResult right = rhs.eval(t), left = lhs.eval(t);

    auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());

    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), left.get_file(), ret_lines);
}

