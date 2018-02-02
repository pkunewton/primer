//
// Created by Administrator on 2018/2/2.
//

#ifndef PRIMER_ORQUERY_H
#define PRIMER_ORQUERY_H

#include "binaryquery.h"
#include "query.h"
#include "query.h"
#include "binaryquery.h"

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right, std::string s):
            BinaryQuery(left, right, s) { }
    QueryResult eval(const TextQuery&) const override ;
};

inline Query operator|(const Query &l, const Query &r){
    return std::shared_ptr<Query_Base>(new OrQuery(l, r, "&"));
}
#endif //PRIMER_ORQUERY_H
