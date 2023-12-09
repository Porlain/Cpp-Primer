/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-08 15:23:14
 */
#include "notquery.h"

inline Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

QueryResult NotQuery::eval(const TextQuery &t) const
{
    auto result = query.eval(t);
    auto ret_lines = std::make_shared<std::set<line_no>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file().size();
    for (size_t i = 0; i != sz; ++i)
    {
        if (beg == end || *beg != i)
            ret_lines->insert(i);
        else if (beg != end)
            ++beg;
    }
    return QueryResult(rep(), result.get_file(), ret_lines);
}

std::string NotQuery::rep() const
{
    std::cout << "NotQuery::rep()\n";
    return "~(" + query.rep() + ")";
}
