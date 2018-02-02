//
// Created by Administrator on 2018/2/1 0001.
//

#ifndef PRIMER_QUERY_H
#define PRIMER_QUERY_H

#include "textquery.h"

class Query {
    friend Query operator~(const Query&);
    friend Query operator&(const Query&, const Query&);
    friend Query operator|(const Query&, const Query&);
public:
    Query(const std::string&);
    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const { return q->rep(); }
private:
    Query(std::shared_ptr<Query_Base> query): q(query) { }
    std::shared_ptr<Query_Base> q;
};

// Query 类的构造函数，指向一个WordQuery对象
inline Query::Query(const std::string &s):
        q(std::shared_ptr<Query_Base>(new WordQuery(s))){ }

#endif //PRIMER_QUERY_H
