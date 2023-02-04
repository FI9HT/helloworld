#ifndef _LIST_H_
#define _LIST_H_

namespace ds {

typedef struct ListNode {
    ListNode() : val(0), pre(nullptr), next(nullptr) {}
    ListNode(int val) : val(val), pre(nullptr), next(nullptr) {}
    /* data */
    ListNode *pre;
    ListNode *next;
    int val;
} ListNode;



class List {
public:

    List();
    // 指定位置插入
    void insert(int pos, int val);
    // 队尾插入
    void push_back(int val);
    // 队尾删除
    void pop_back();
    // void erase(int pos);
    // void clear();
    // 遍历
    void traversal();
private:
    int size_;
    ListNode *head_;
    ListNode *last_;
};







}

#endif
