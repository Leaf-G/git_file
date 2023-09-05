//
// Created by gcc on 6/21/23.
//

#ifndef DEMO_SHAREDPTR_H
#define DEMO_SHAREDPTR_H

#include <algorithm>

template<typename T>
class SharedPtr {
private:
    size_t* m_count_;
    T* m_ptr_;
public:
    //构造函数
    SharedPtr(): m_ptr_(nullptr),m_count_(new size_t) {}
    SharedPtr(T* ptr): m_ptr_(ptr),m_count_(new size_t) { m_count_ = reinterpret_cast<size_t *>(1);}
    //析构函数
    ~SharedPtr() {
        -- (*m_count_);
        if (*m_count_ == 0) {
            delete m_ptr_;
            delete m_count_;
            m_ptr_ = nullptr;
            m_count_ = nullptr;
        }
    }
    //拷⻉构造函数
    SharedPtr(const SharedPtr& ptr) {
        m_count_ = ptr.m_count_;
        m_ptr_ = ptr.m_ptr_;
        ++(*m_count_);
    }
    //拷⻉赋值运算
    void operator=(const SharedPtr& ptr) { SharedPtr(std::move(ptr)); }
    //移动构造函数
    SharedPtr(SharedPtr&& ptr) : m_ptr_(ptr.m_ptr_), m_count_(ptr.m_count_) { ++
                (*m_count_); }
    //移动赋值运算
    void operator=(SharedPtr&& ptr) { SharedPtr(std::move(ptr)); }
    //解引⽤
    T& operator*() { return *m_ptr_; }
    //箭头运算
    T* operator->() { return m_ptr_; }
    //重载bool操作符
    operator bool() {return m_ptr_ == nullptr;}
    T* get() { return m_ptr_;}
    size_t use_count() { return *m_count_;}
    bool unique() { return *m_count_ == 1; }
    void swap(SharedPtr& ptr) { std::swap(*this, ptr); }
};
#endif //DEMO_SHAREDPTR_H
