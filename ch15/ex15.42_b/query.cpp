#include "query.h"

QueryResult Query::eval(const TextQuery &t) const
{
    return q->eval(t);
}

std::string Query::rep() const
{
    std::cout << "Query::rep() \n";
    return q->rep();
}

inline std::ostream &operator<<(std::ostream &out, const Query &query)
{
    return out << query.rep();
}