//
// Created by Administrator on 2018/1/22.
//

#ifndef PRIMER_STRVEC_H
#define PRIMER_STRVEC_H

#include <memory>

template <typename T>
class StrVec {
public:
    StrVec();
    StrVec(const StrVec&);
    StrVec &operator=(const StrVec&);
    ~StrVec();
    void push_back(const T&);
    size_t size() const { return first_free - elements; };
    size_t capacity() const { return cap - elements; };
    T *begin() const { return elements; };
    T *end() const { return first_free; } ;

    void reserve(size_t new_cap);
    void resize(size_t count);
    void resize(size_t count, const T&);
private:
    static std::allocator<T> alloc;
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<T*, T*> alloc_n_copy(const T*, const T*);
    void free();
    void reallocate();
    T *elements;
    T *first_free;
    T *cap;
};

#endif //PRIMER_STRVEC_H
