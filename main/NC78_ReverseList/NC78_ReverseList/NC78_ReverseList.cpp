// NC78_ReverseList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
题目描述
输入一个链表，反转链表后，输出新链表的表头。
示例1
输入
{1,2,3}
返回值
{3,2,1}
*/

#include <iostream>
using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};


class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pre = nullptr;
        ListNode* cur = pHead;
        ListNode* next;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

int main()
{
    int list[] = { 1,2,3 };
    int n = 3;
    ListNode* head = new ListNode(list[0]);
    ListNode* p = head;
    for (int i = 1; i < 3; i++) {
        p->next = new ListNode(list[i]);
        p = p->next;
    }

    Solution S;
    head = S.ReverseList(head);
    p = head;
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    
}

