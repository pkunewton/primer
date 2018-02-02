//
// Created by Administrator on 2018/2/2.
//

#ifndef PRIMER_NOTQUERY_H
#define PRIMER_NOTQUERY_H

#include "query_base.h"
#include "query.h"

class NotQuery : public Query_Base {
    friend Query operator~(const Query&);
    NotQuery(const Query &q): query(q) { }
    std::string rep() const override { return  "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery &t) const ;
    Query query;
};

inline Query operator~(const Query &oprand){
    return std::shared_ptr<Query_Base>(new NotQuery(oprand));
}

#endif //PRIMER_NOTQUERY_H
