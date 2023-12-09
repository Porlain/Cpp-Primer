/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-08 10:49:53
 */
#include "wordquery.h"

QueryResult WordQuery::eval(const TextQuery &t) const
{
    return t.query(query_word);
}

std::string WordQuery::rep() const
{
    std::cout << "WodQuery::rep()\n";
    return query_word;
}