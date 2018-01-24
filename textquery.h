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
#include "Blob.h"

class QueryResult;
class Query;
class Query_Base;
class OrQuery;
class AndQuery;
class BinaryQuery;
class NotQuery;
class WordQuery;

class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
//    typedef std::vector<std::string>::size_type line_no;
    TextQuery(std::ifstream);
    QueryResult query(const std::string &s) const ;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<set<line_no>> word_map;
};

class QueryResult {
    friend std::ostream& print(std::ostream&, QueryResult&);
public:
    QueryResult();
private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no >> sp_lines;
    BlobPtr<std::string> file;
};

std::ostream& print(std::ostream&, QueryResult&);



#endif //PRIMER_TEXTQUERY_H
