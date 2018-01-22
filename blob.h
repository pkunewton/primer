//
// Created by Administrator on 2018/1/22.
//

#ifndef PRIMER_BLOB_H
#define PRIMER_BLOB_H

#include <memory>
#include <vector>

template <typename T>
class Blob {
public:
    typedef T value_type;
    typedef std::vector<T>::size_type size_type;
    Blob();
    Blob(std::initializer_list<T> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T&);
    void push_back(T &&);
    void pop_back();

    T& back();
    T& operator[](size_type i);
private:
    std::shared_ptr<std::vector<T>> data;
    void check(std::size_t i, const std::string &msg) const ;
};

#endif //PRIMER_BLOB_H
