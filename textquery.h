//
// Created by Administrator on 2018/1/23 0023.
//

#ifndef PRIMER_TEXTQUERY_H
#define PRIMER_TEXTQUERY_H

#include <memory>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <fstream>

class QueryResult;
class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
//    typedef std::vector<std::string>::size_type LineNo;
    TextQuery(std::ifstream);
    QueryResult query(const std::string &s) const ;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<set<line_no>> word_map;
};

#endif //PRIMER_TEXTQUERY_H
