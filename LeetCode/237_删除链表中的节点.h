/*
完成时间2020年11月18日
题目地址：https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
*/
#pragma once
#include"LCInclude.h"

class Solution {
public:
    void deleteNode(ListNode* node) {
        // 判空
        if (node == nullptr)
            return;

        // 删除操作
        if (node->next != nullptr)
        {
            // 非空的时候 下一个节点的元素向前拷贝再删除下一个节点
            node->val = node->next->val;
            node->next = node->next->next;
        }
    }
};

// 测试程序
void test_main()
{
    ListNode* head = new ListNode(1);
    ListNode* it = head;
    ListNode* removeNode = nullptr;
    const int RemoveNumber = 3; // 需要删除的数字
    for (int i = 2; i <= 10; ++i)
    {
        it->next = new ListNode(i);
        it = it->next;
        if (it->val == RemoveNumber)
            removeNode = it;
    }

    Solution().deleteNode(removeNode);
    it = head;
    while (it != nullptr)
    {
        cout << it->val << ",";
        it = it->next;
    }
    cout << endl;
}