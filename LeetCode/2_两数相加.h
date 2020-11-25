#pragma once
/*
完成时间2020年11月25日
题目地址：https://leetcode-cn.com/problems/add-two-numbers/
*/
#include"LCInclude.h"
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 判空
        if (l1 == nullptr)
            return l2;
        else if (l2 == nullptr)
            return l1;

        // 指针
        ListNode* header = l1;
        // 进位寄存的数字
        int buffer = 0;

        // 在l1链上求和
        while (l1 != nullptr && l2 != nullptr)
        {
            // 将链长补齐
            if (l1->next == nullptr && l2->next != nullptr)
                l1->next = new ListNode(0);
            else if (l2->next == nullptr && l1->next != nullptr)
                l2->next = new ListNode(0);
            // 当前节点的求和
            int this_add = l1->val + l2->val + buffer;
            buffer = this_add * 0.1;
            l1->val = this_add % 10;
            // 检查buffer
            if (l1->next == nullptr && l2->next == nullptr && buffer)
            {
                l1->next = new ListNode(buffer);
            }
            // 步进
            l1 = l1->next;
            l2 = l2->next;
        }

        // 返回header
        return header;
    }
};
