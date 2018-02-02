//
// Created by LiuKe on 2018/1/23 0023.
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
#include "query.h"

class QueryResult;

class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
//    typedef std::vector<std::string>::size_type line_no;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string &s) const ;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no >>> word_map;
};

class QueryResult {
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(const std::string &sought, std::shared_ptr<std::set<TextQuery::line_no >> sp_lines,
                std::shared_ptr<std::vector<std::string>> file): sought(sought), sp_lines(sp_lines), file(file) { }

    const std::shared_ptr<std::vector<std::string>> get_file() const { return file; }
    std::set<TextQuery::line_no >::iterator
    begin() { return sp_lines->begin(); }
    std::set<TextQuery::line_no >::iterator
    end() { return sp_lines->end(); }
private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no >> sp_lines;
    std::shared_ptr<std::vector<std::string>> file;
};

std::ostream& print(std::ostream&, const QueryResult&);

class Query_Base {
    friend class Query;
public:
    using line_no = std::vector<std::string>::size_type;
    virtual ~Query_Base() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep() const = 0;
};

class WordQuery : public Query_Base {
    friend class Query;
    WordQuery(const std::string &s): query_word(s) { }
    QueryResult eval(const TextQuery &t) const override {
        t.query(query_word);
    }
    std::string rep() const  override { return query_word; }
    std::string query_word;
};


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

class BinaryQuery : public Query_Base {

};

class AndQuery : public BinaryQuery {

};

class OrQuery : public BinaryQuery {

};

#endif //PRIMER_TEXTQUERY_H
