/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-08 16:41:48
 */
#include "queryhistory.h"

size_t QueryHistory::add_query(const Query &query)
{
    std::shared_ptr<Query> p = make_shared<Query>(query);
    query_vec.push_back(p);
    return query_vec.size() - 1;
}