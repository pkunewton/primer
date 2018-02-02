//
// Created by Administrator on 2018/2/2.
//
#include "orquery.h"

QueryResult OrQuery::eval(const TextQuery &text) const {
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto res_lines = std::make_shared<std::set<line_no >>(left.begin(), left.end());
    res_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), res_lines, left.get_file());
}
