//
// Created by Administrator on 2018/2/2.
//

#ifndef PRIMER_BINARYQUERY_H
#define PRIMER_BINARYQUERY_H

#include "query_base.h"
#include "query.h"

class BinaryQuery : public Query_Base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s):
        lhs(l), rhs(r), op(s) { }
    std::string rep() const { return  "(" + lhs.rep() + " " + op + " " + rhs.rep() + ")"; }
    std::string op;
    Query lhs, rhs;
};
#endif //PRIMER_BINARYQUERY_H
