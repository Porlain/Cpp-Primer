/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-08 16:40:05
 */
#ifndef _QUERYHISTORY_H
#define _QUERYHISTORY_H

#include "query.h"
#include <vector>

class QueryHistory
{
public:
    Query &operator[](size_t n) { return *query_vec[n]; }
    size_t add_query(const Query &);

private:
    std::vector<std::shared_ptr<Query>> query_vec;
};
#endif