//
// Created by Administrator on 2018/1/22.
//
#include "strVec.h"

template <typename T>
void StrVec<T>::push_back(const T &t) {
    chk_n_alloc();
    alloc.construct(first_free++, t);
}

template <typename T>
std::pair<T*, T*> StrVec<T>::alloc_n_copy(const T *b, const T *e) {
    auto data = alloc.allocate(e-b);
    return {data, std::uninitialized_copy(b, e, data)};
}

template <typename T>
void StrVec<T>::free() {
    if(elements){
        for(auto p = first_free ; p != elements ; ){
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
StrVec<T>::StrVec(const StrVec<T> &s) {
    auto new_data = alloc_n_copy(s.begin(), s.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
}

template <typename T>
StrVec<T>& StrVec<T>::operator=(const StrVec<T> &s) {
    auto new_data = alloc_n_copy(s.begin(), s.end());
    free();
    elements = new_data.first;
    first_free = cap = new_data.second;
    return *this;
}

template <typename T>
void StrVec<T>::alloc_n_move(std::size_t new_cap) {
    auto new_data = alloc.allocate(new_cap);
    auto dst = new_data;
    auto elem = elements;
    for( ; elem != first_free ; ){
        alloc.construct(dst++, std::move(*elem++));
    }
    free();
    elements = new_data;
    first_free = dst;
    cap = elements + new_cap;

}

template <typename T>
void StrVec<T>::reallocate() {
    auto new_capacity = size() ? size() * 2 : 1;
    alloc_n_move(new_capacity);
}

template <typename T>
void StrVec<T>::reserve(std::size_t new_cap) {
    if(new_cap < capacity()) return;
    alloc_n_move(new_cap);
}

template <typename T>
void StrVec<T>::resize(std::size_t count) {
    resize(count, T());
}

template <typename T>
void StrVec<T>::resize(std::size_t count, const T &t) {
    if(count < size()){
        while (first_free != elements + count)
            alloc.destroy(--first_free);
    } else {
        if(count > capacity()) reserve(count * 2);
        while (first_free != elements + count)
            alloc.construct(first_free++, t);
    }
}
