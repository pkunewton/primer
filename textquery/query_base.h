//
// Created by Administrator on 2018/2/2.
//

#ifndef PRIMER_QUERY_BASE_H
#define PRIMER_QUERY_BASE_H

#include "textquery.h"

class Query_Base {
    friend class Query;
public:
    using line_no = std::vector<std::string>::size_type;
    virtual ~Query_Base() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep() const = 0;
};

#endif //PRIMER_QUERY_BASE_H
