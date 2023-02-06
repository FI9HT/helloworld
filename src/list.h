#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>

namespace ds {

template <typename T>
struct ListNode {
    ListNode() : val(), pre(nullptr), next(nullptr) {}
    ListNode(const T& val) : val(val), pre(nullptr), next(nullptr) {}
    /* data */
    ListNode *pre;
    ListNode *next;
    T val; 
};

// 部分操作可能导致 undefined behavior，比如对size=0的链表访问begin迭代器
template <typename T>
class List {
public:
    // inner class iterator
    class iterator {
        // 为了让List通过iterator内部指针，来修改List的节点
        friend class List;
    public:
        iterator() = delete;
        // 只能拷贝构造
        iterator(ListNode<T> *ptr) : ptr_(ptr) {}
        iterator& operator++() {
            ptr_ = ptr_->next;
            return *this;
        }
        iterator& operator++(int) {
            iterator *tmp = this;
            ptr_ = ptr_->next;
            return *tmp;            
        }
        T operator*() {
            return (*ptr_).val;
        }
        T* operator->() {
            return &(ptr_->val);            
        }
        bool operator==(const iterator& it) {
            return ptr_ == it.ptr_;
        }
        bool operator!=(const iterator& it) {
            return ptr_ != it.ptr_;
        }
    private:
        ListNode<T>* ptr_;
    };
    
    List() : size_(0) {
        printf("List default ctor\n");
        head_ = new ListNode<T>();          // 头节点默认构造T
        printf("list ctor end");
        head_->next = head_->pre = head_;   // 环形结构
    }

    List(const List& list) : size_(list.size_) {
        printf("List copy ctor\n");
        // deep copy 
        for (auto it = list.begin(); it != end(); it++) {
            push_back(*it);
            size_++;
        }
    }
    List(List&& list) : head_(list.head_), size_(list.size_) {
        printf("List move ctor\n");
    }

    ~List() {
        if (head_ == nullptr) {
            return ;    // 正常不会
        }
        ListNode<T> *ptr = head_->next;
        while (ptr != head_ && ptr != nullptr) {
            auto tmp = ptr;
            ptr = ptr->next;
            delete tmp;
        }
        delete head_;
        head_ = nullptr;
    }
    // todo
    // List& operator=(const List& list);
    // List& operator=(List&& list);
    
    // iterator
    iterator begin() {
        return iterator(head_->next);
    }
    iterator end() {
        return iterator(head_);
    }

    void insert(iterator it, const T& val) {
        ListNode<T> *ptr = it.ptr_;
        ListNode<T> *node = new ListNode<T>(val);
        ptr->pre->next = node;
        node->pre = ptr->pre;
        ptr->pre = node;
        node->next = ptr;
        size_++;
    }

    void erase(iterator it) {
        ListNode<T> *ptr = it.ptr_;
        // 头节点不能被用户删除
        if (ptr == head_) {
            return ;
        }
        ptr->pre->next = ptr->next;
        ptr->next->pre = ptr->pre;
        if (ptr != nullptr) {
            delete ptr;
            ptr = nullptr;
        }
        size_--;        
    }

    void push_back(const T& val) {
        insert(end(), val);
    }
    void push_front(const T& val) {
        insert(begin(), val);
    }

    void pop_back() {
        erase(--end());        
    }
    void pop_front() {
        erase(begin());
    }

    void clear() {
        for (iterator it = begin(); it != end(); it++) {
            erase(it);
        }        
    }

    size_t size() {
        return size_;
    }

    bool empty() {
        return size_ == 0;
    }
    
    T front() {        
        return head_->next->val;
    }

    T back() {
        return head_->pre->val;        
    }
    
    // 遍历
    void traversal() {
        auto it = begin();
        printf("size[%zu][ ", size_);
        while (it++ != end()) {
            printf("%d ", (*it).a);      
        }
        printf("]\n");
    }

private:
    size_t      size_;
    ListNode<T> *head_;
};

}




#endif
