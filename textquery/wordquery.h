//
// Created by Administrator on 2018/2/2.
//

#ifndef PRIMER_WORDQUERY_H
#define PRIMER_WORDQUERY_H

#include "query_base.h"

class WordQuery : public Query_Base {
    friend class Query;
    WordQuery(const std::string &s): query_word(s) { }
    QueryResult eval(const TextQuery &t) const override {
        t.query(query_word);
    }
    std::string rep() const  override { return query_word; }
    std::string query_word;
};

#endif //PRIMER_WORDQUERY_H
