#pragma once
/*
完成时间2020年11月19日
题目地址：https://leetcode-cn.com/problems/remove-linked-list-elements/
*/
#include"LCInclude.h"
using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 判空
        if (head == nullptr)
            return head;

        // 先去除首部一样的元素
        while (head != nullptr && head->val == val)
            head = head->next;

        // 迭代器
        ListNode* it = head;
        // 遍历
        while (it != nullptr && it->next != nullptr)
        {
            // 发现需要删除的元素
            if (it->next->val == val)
            {
                // 快指针，探查下一个不等于val的节点
                ListNode* fast = it->next;
                while (fast != nullptr && fast->val == val)
                {
                    fast = fast->next;
                }
                // 删除中间等于val的节点
                it->next = fast;
            }
            // 步进
            it = it->next;
        }

        return head;
    }
};