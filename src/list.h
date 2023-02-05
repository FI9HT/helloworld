#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>

#ifndef Print
#define Print(format, args...) 	\
do { \
	fprintf(stdout, "[%s][%d] " format "\n", __FILE__, __LINE__, ##args); \
} while(0) 
#endif

namespace ds {

// 模板T一定要实现默认构造函数
template <typename T>
struct ListNode {
    ListNode() : val(), pre(nullptr), next(nullptr) {}
    ListNode(const T& val) : val(val), pre(nullptr), next(nullptr) {}
    /* data */
    ListNode *pre;
    ListNode *next;
    T val; 
};

template <typename T>
class List {
public:
    // inner class iterator
    class iterator {
    public:
        iterator() {};
        iterator(ListNode<T> *ptr) : ptr_(ptr) {}
        iterator& operator++();
        iterator& operator++(int);
        T operator*();
        T* operator->();
        bool operator==(const iterator& it);
        bool operator!=(const iterator& it);
    private:
        ListNode<T>* ptr_;
    };
    // iterator
    iterator begin();
    iterator end();
    // ctor and operator=
    List();
    List(const List& list);
    // List(List&& list);
    // List& operator=(const List& list);
    // List& operator=(List&& list);
    // capacity
    size_t size();
    bool empty();
    // access
    T front();
    T back();
    // modify
    void push_back(const T& val);
    void push_front(const T& val);    
    void pop_back();
    void pop_front();
    // void erase(int pos);
    // void clear();    
    // traversal
    void traversal();
private:
    size_t      size_;
    ListNode<T> *head_;
};

}

// class iterator
template <typename T>
T ds::List<T>::iterator::operator*() {
    return (*ptr_).val;
}
template <typename T>
typename ds::List<T>::iterator& ds::List<T>::iterator::operator++() {
    // Print("++ptr");
    ptr_ = ptr_->next;
    return *this;
}
template <typename T>
typename ds::List<T>::iterator& ds::List<T>::iterator::operator++(int) {
    // Print("ptr++");
    iterator *tmp = this;
    ptr_ = ptr_->next;
    return *tmp;
}
template <typename T>
T* ds::List<T>::iterator::operator->() {
    return &(ptr_->val);
}
template <typename T>
bool ds::List<T>::iterator::operator==(const iterator& it) {
    return ptr_ == it.ptr_;
}
template <typename T>
bool ds::List<T>::iterator::operator!=(const iterator& it) {
    return ptr_ != it.ptr_;
}

// class List
// iterator
template <typename T>
typename ds::List<T>::iterator ds::List<T>::begin() {
    return iterator(head_->next);
}
template <typename T>
typename ds::List<T>::iterator ds::List<T>::end() {
    return iterator(head_);
}
// ctor
template <typename T>
ds::List<T>::List() : size_(0) {
    Print("List default ctor");
    head_ = new ListNode<T>();
    // 环形结构
    head_->next = head_->pre = head_;
}
template <typename T>
ds::List<T>::List(const List& list) : size_(list.size_) {
    Print("List copy ctor");
    // deep copy 
    for (auto it = list.begin(); it != end(); it++) {
        this->push_back(*it);
        size_++;
    }
}
// template <typename T>
// ds::List<T>::List(List&& list) : size_(list.size_) {
//     Print("List copy ctor");
//     // shallow copy and free list
//     // todo
// }
// modify
template<typename T>
void ds::List<T>::push_back(const T& val) {
    // stl 是通过迭代器实现的
    ListNode<T> *node = new ListNode<T>(val);
    head_->pre->next = node;
    node->pre = head_->pre;
    head_->pre = node;
    node->next = head_;
    size_++;
}
template<typename T>
void ds::List<T>::push_front(const T& val) {
    ListNode<T> *node = new ListNode<T>(val);
    head_->next->pre = node;
    node->next = head_->next;
    head_->next = node;
    node->pre = head_;
    size_++;
}
template<typename T>
void ds::List<T>::pop_back() {
    if (!size_) {
        return ;
    }
    ListNode<T> *node = head_->pre;
    node->pre->next = node->next;
    node->next->pre = node->pre;
    delete node;
    size_--;
}
template<typename T>
void ds::List<T>::pop_front() {
    if (!size_) {
        return ;
    }
    ListNode<T> *node = head_->next;
    node->pre->next = node->next;
    node->next->pre = node->pre;
    delete node;
    size_--;
}

// capacity
template <typename T>
size_t ds::List<T>::size() {
    return size_;
}

template <typename T>
bool ds::List<T>::empty() {
    return size_ == 0;
}
// access
template <typename T>
T ds::List<T>::front() {
    if (!size_) {
        // undefined behavior
        return head_->val;
    }
    return head_->next->val;
}
template <typename T>
T ds::List<T>::back() {
    if (!size_) {
        // undefined behavior
        return head_->val;
    }
    return head_->pre->val;
};
// traversal
template <typename T>
void ds::List<T>::traversal() {
    auto it = begin();
    printf("size[%d][ ", size_);
    while (it != end()) {
        printf("%d ", (*it).a);
        ++it;        
    }
    printf("]\n");
}

#endif
