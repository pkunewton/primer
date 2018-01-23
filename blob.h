//
// Created by Administrator on 2018/1/22.
//

#ifndef PRIMER_BLOB_H
#define PRIMER_BLOB_H

#include <memory>
#include <vector>

template <typename> class BlobPtr;

template <typename T>
class Blob {
    friend class BlobPtr<T>;
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
//    using size_type = std::vector<T>::size_type;

    Blob();
    Blob(std::initializer_list<T> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &t) { data->push_back(t); };
    void push_back(T &&t) { data->push_back(std::move(t)); };
    void pop_back();

    T& back();
    T& front();
    T& operator[](size_type i);

    const T& back() const ;
    const T& front() const;
    const T& operator[](size_type i) const ;
private:
    std::shared_ptr<std::vector<T>> data;
    void check(std::size_t i, const std::string &msg) const ;
};

template <typename T>
bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T>
bool operator < (const BlobPtr<T> &, const BlobPtr<T> &);

template <typename T>
class BlobPtr {
    friend bool operator==<T>(const BlobPtr<T> &, const BlobPtr<T> &);
    friend bool operator < <T>(const BlobPtr<T> &, const BlobPtr<T> &);
public:
    BlobPtr(): curr(0) { }
    BlobPtr(Blob<T> &a, std::size_t sz = 0);

    T& operator*() const {
        auto p = check(curr, "derefenrence past end");
        return (*p)[curr];
    };
    // 前置递增递减运算符
    BlobPtr<T> &operator++();
    BlobPtr<T> &operator--();
    // 后置递增递减运算符
    BlobPtr<T> &operator ++(int);
    BlobPtr<T> &operator --(int);
private:
    std::shared_ptr<std::vector<T>> check(std::size_t i, const std::string &msg) const ;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::
        check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if(!ret)
        throw std::runtime_error("unbound blobptr");
    if(i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

#endif //PRIMER_BLOB_H
