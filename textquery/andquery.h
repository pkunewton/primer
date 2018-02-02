//
// Created by Administrator on 2018/2/2.
//

#ifndef PRIMER_ANDQUERY_H
#define PRIMER_ANDQUERY_H

#include "query.h"
#include "binaryquery.h"

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right, std::string s):
            BinaryQuery(left, right, s) { }
    QueryResult eval(const TextQuery&) const override ;
};

inline Query operator&(const Query &l, const Query &r){
    return std::shared_ptr<Query_Base>(new AndQuery(l, r, "&"));
}

#endif //PRIMER_ANDQUERY_H
