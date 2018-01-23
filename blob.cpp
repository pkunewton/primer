//
// Created by Administrator on 2018/1/22.
//
#include "blob.h"

template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()) { }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il):
        data(std::make_shared<std::vector<T>>(il)) { }

template <typename T>
void Blob<T>::check(std::size_t i, const std::string &msg) const {
    if (i > size()) {
        throw std::out_of_range(msg);
    }
}

template <typename T>
void Blob<T>::pop_back() {
    check(0, "pop back on empty blob!");
    data->pop_back();
}

template <typename T>
T& Blob<T>::back() {
    check(0, "back on empty blob");
    return data->back();
}

template <typename T>
const T& Blob<T>::back() const {
    check(0, "back on empty blob");
    return data->back();
}

template <typename T>
T& Blob<T>::front() {
    check(0, "front on empty blob");
    return data->front();
}

template <typename T>
const T& Blob<T>::front() const {
    check(0, "front on empty blob");
    return data->front();
}

template <typename T>
T& Blob<T>::operator[](size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
const T& Blob<T>::operator[](size_type i) const {
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
BlobPtr<T>::BlobPtr(Blob<T> &a, size_t sz):
        wptr(a.data), curr(sz) { }

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
    check(curr, "increment past end of blob");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++(int) {
    BlobPtr<T> ret = *this;
    ++*this;
    return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
    --curr;
    check(curr, "decrement past begin of blob");
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--(int) {
    BlobPtr<T> ret = *this;
    --*this;
    return ret;
}