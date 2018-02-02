//
// Created by Administrator on 2018/1/23 0023.
//
#include "textquery.h"
#include <sstream>

using std::vector;
using std::string;
using std::cout;

TextQuery::TextQuery(std::ifstream &ifs): file(new vector<string>) {
    string text;
    while (std::getline(ifs, text)){
        file->push_back(text);
        std::istringstream line(text);
        int number = file->size() - 1;
        string word;
        while (line >> word){
            std::shared_ptr<std::set<line_no >>
                    &sp_line = word_map[word];
            if(!sp_line){
                sp_line.reset(new std::set<line_no >);
            }
            sp_line->insert(number);
        }
    }
}

QueryResult TextQuery::query(const std::string &s) const {
    std::shared_ptr<std::set<line_no >> no_data(new std::set<line_no>);

    auto iter = word_map.find(s);
    if(iter != word_map.end()){
        return QueryResult(s, iter->second, file);
    }else {
        return QueryResult(s, no_data, file);
    }
}

std::ostream &print(std::ostream &os, const QueryResult &qr){
    os << qr.sought << " occurs " << qr.sp_lines->size()
                                  << " times\n";
    for(auto &index : *qr.sp_lines){
        os << "\t(line " << index + 1 << ") "
                                      << (*qr.file)[index];
    }
}


