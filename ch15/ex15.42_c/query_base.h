/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-09 10:49:49
 */
#ifndef QUERY_BASE_H
#define QUERY_BASE_H
#include "textquery.h"

class Query_base
{
public:
    friend class Query;

protected:
    using line_no = TextQuery::linenum;
    virtual ~Query_base() = default;

private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const = 0;
};

#endif