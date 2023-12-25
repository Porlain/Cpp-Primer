/*
 * @Create: Created by Porlain on 2023
 * @Author: Porlain szbj2023@163.com
 * @LastEditTime: 2023-12-23 14:53:38
 * Here is just an example, to avoid errors, you need to add namespaces in the previous code
 */
#ifndef QUERY_H_
#define QUERY_H_

#include <string>
#include <iostream>
#include "../ch15/ex15.42_c/query_base.h"
#include "../ch15/ex15.42_c/wordquery.h"
#include "ex18_12_textquery.h"

namespace chapter15
{
	class Query
	{
		friend Query operator~(const Query&);
		friend Query operator|(const Query&, const Query&);
		friend Query operator&(const Query&, const Query&);
	public:
		Query(const std::string&);
		chapter10::QueryResult eval(const chapter10::TextQuery &t) const { return q->eval(t); }
		std::string rep() const { std::cout << "Query::rep()" << std::endl; return q->rep(); }
	private:
		Query(std::shared_ptr<Query_base> query) : q(query) { std::cout << "Query(std::shared_ptr<Query_base> query)" << std::endl; }
		std::shared_ptr<Query_base> q;
	};

	std::ostream& operator<<(std::ostream &os, const Query &query)
	{
		return os << query.rep();
	}

	inline Query::Query(const std::string &s) : q(new WordQuery(s)) { std::cout << "Query::Query(const std::string &s)" << std::endl; }
}

#endif
