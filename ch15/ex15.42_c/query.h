/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-08 10:47:24
 */
/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-08 10:41:33
 */
/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-08 10:08:18
 */
#ifndef QUERY_H
#define QUERY_H

#include "query_base.h"
#include "textquery.h"
#include "wordquery.h"
#include <memory>
#include <string>
#include <iostream>

class Query
{
public:
    friend Query operator~(const Query &);
    friend Query operator&(const Query &, const Query &);
    friend Query operator|(const Query &, const Query &);

public:
    // build a new WordQuery
    Query(const std::string &s) : q(new WordQuery(s)) { std::cout << "Query::Query(const std::string& s) where s=" + s + "\n"; }

    // interface functions: call the corresponding Query_base operatopns
    QueryResult eval(const TextQuery &) const;
    std::string rep() const;

private:
    std::shared_ptr<Query_base> q;
    Query(std::shared_ptr<Query_base> query) : q(query) { std::cout << "Query::Query(std::shared_ptr<Query_base> query)\n"; }
};

#endif