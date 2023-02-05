#include <stdio.h>

#include "list.h"

#ifndef Print
#define Print(format, args...) 	\
do { \
    fprintf(stdout, "[%s][%d] " format "\n", __FILE__, __LINE__, ##args); \
} while(0) 
#endif

#if 1
// ds::List::list_iterator ds::List<T>::list_iterator::operator++() {


// }



// template <typename T>
// ds::List<T>::List(const List& list) : size_(list.size_) {
//     Print("List copy ctor");
//     // deep copy 
//     // tode
// }

// template <typename T>
// ds::List<T>::List(List&& list) : size_(list.size_) {
//     Print("List copy ctor");
//     // shallow copy and free list
//     // todo
// }

// template <typename T>
// size_t ds::List<T>::size() {
//     return size_;
// }

// template <typename T>
// bool ds::List<T>::empty() {
//     return size_ == 0;
// }

// template <typename T>
// T ds::List<T>::front() {
//     if (!size_) {
//         // undefined behavior
//         return ;
//     }
//     return head_->next->val;
// }

// template <typename T>
// T ds::List<T>::back() {
//     // if (!size_) {
//     //     return 
//     // }
// };


#endif
// void ds::List::push_back(int val) {
//     if (head_ == nullptr) {
//         head_ = new ListNode(val);
//         last_ = nullptr;
//     } else {
//         ListNode *ptr = head_;
//         while (ptr->next != nullptr) {
//             ptr = ptr->next;
//         }
//         ListNode *node = new ListNode(val);
//         ptr->next = node;
//         node->pre = ptr;
//         node->next = nullptr;
//         last_ = nullptr;
//     }
//     size_++;
// }

// void ds::List::traversal() {
//     ListNode *ptr = head_;
//     printf("size: %d [ ", size_);
//     while (ptr != nullptr) {
//         printf("%d ", ptr->val);
//         ptr = ptr->next;
//     }
//     printf("]\n");    
// }

// void ds::List::pop_back() {
//     if (head_ == nullptr || !size_) {
//         return ;
//     }
//     ListNode *ptr = head_;

//     while (ptr->next != nullptr) {
//         ptr = ptr->next;
//     }
//     if (ptr->pre != nullptr) {
//         ptr->pre->next = ptr->next;
//     } else {
//         head_ = nullptr;
//     }
    
//     delete ptr;
//     size_--;
// }

// void ds::List::insert(int pos, int val) {
//     if (pos > size_ - 1) {
//         return ;
//     }
//     ListNode *ptr = head_;
//     while (pos-- && ptr != nullptr) {
//         ptr = ptr->next;
//     }
//     ListNode *node = new ListNode(val);
//     if (ptr->pre == nullptr) {
//         node->next = head_;
//         head_ = node;
//     } else {
//         ptr->pre->next = node;
//         node->pre = ptr->pre;
//         node->next = ptr;
//         ptr->pre = node;
//     }
// }