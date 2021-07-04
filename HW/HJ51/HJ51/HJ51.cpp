// HJ51.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
输入一个单向链表，输出该链表中倒数第k个结点，链表的倒数第1个结点为链表的尾指针。

链表结点定义如下：

struct ListNode

{

int       m_nKey;

ListNode* m_pNext;

};



正常返回倒数第k个结点指针，异常返回空指针

本题有多组样例输入。


输入描述：
输入说明
1 输入链表结点个数
2 输入链表的值
3 输入k的值

输出描述：
输出一个整数

示例1
输入：
8
1 2 3 4 5 6 7 8
4

输出：
5

*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
    ListNode(int v) {
        m_nKey = v;
        m_pNext = nullptr;
    }
};

ListNode* creatList(vector<int>& vec)
{
    if (vec.empty()) return nullptr;
    ListNode* head = new ListNode(vec[0]);
    ListNode* p = head;
    for (int i = 1; i < vec.size(); i++) {
        p->m_pNext = new ListNode(vec[i]);
        p = p->m_pNext;
    }
    return head;
}

int getKNode(ListNode* head, int k)
{
    if (head == nullptr) return NULL;
    if (k <= 0) return 0;
    ListNode* p = head;
    int j = 0;
    ListNode* res = head;
    while (p != nullptr) {
        if (j >= k) {
            res = res->m_pNext;
        }
        j++;
        p = p->m_pNext;
    }

    if (res != nullptr) {
        return res->m_nKey;
    }
    else {
        return 0;
    }
}

int main()
{
    int n, k;
    while (cin >> n) {
        vector<int> V(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> V[i];
        }
        cin >> k;
        // 构建链表
        ListNode* head = creatList(V);
        // 输出结果
        cout << getKNode(head, k) << endl;
    }
}