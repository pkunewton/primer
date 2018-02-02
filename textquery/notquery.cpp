//
// Created by LiuKe on 2018/2/2.
//
#include "notquery.h"

QueryResult NotQuery::eval(const TextQuery &text) const {
    QueryResult res = query.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no >>();
    auto beg = res.begin(), end = res.end();
    auto sz = res.get_file()->size();
    for(std::size_t n = 0; n != sz; n++){
        if(beg == end || *beg != n){
            ret_lines->insert(n);
        } else if(beg != end){
            ++beg;
        }
    }
    return QueryResult(rep(), ret_lines, res.get_file());
}