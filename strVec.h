//
// Created by Administrator on 2018/1/22.
//

#ifndef PRIMER_STRVEC_H
#define PRIMER_STRVEC_H

#include <memory>

template <typename T>
class StrVec {
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec<T>&);
    StrVec<T> &operator=(const StrVec<T>&);
    ~StrVec() { free(); }
    void push_back(const T&);
    std::size_t size() const { return first_free - elements; };
    std::size_t capacity() const { return cap - elements; };
    T *begin() const { return elements; };
    T *end() const { return first_free; } ;

    void reserve(std::size_t new_cap);
    void resize(std::size_t count);
    void resize(std::size_t count, const T &t);
private:
    static std::allocator<T> alloc;
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<T*, T*> alloc_n_copy(const T*, const T*);
    void alloc_n_move(std::size_t new_cap);
    void free();
    void reallocate();
    T *elements;
    T *first_free;
    T *cap;
};

#endif //PRIMER_STRVEC_H
