#pragma once
/*
���ʱ��2020��11��25��
��Ŀ��ַ��https://leetcode-cn.com/problems/add-two-numbers/
*/
#include"LCInclude.h"
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // �п�
        if (l1 == nullptr)
            return l2;
        else if (l2 == nullptr)
            return l1;

        // ָ��
        ListNode* header = l1;
        // ��λ�Ĵ������
        int buffer = 0;

        // ��l1�������
        while (l1 != nullptr && l2 != nullptr)
        {
            // ����������
            if (l1->next == nullptr && l2->next != nullptr)
                l1->next = new ListNode(0);
            else if (l2->next == nullptr && l1->next != nullptr)
                l2->next = new ListNode(0);
            // ��ǰ�ڵ�����
            int this_add = l1->val + l2->val + buffer;
            buffer = this_add * 0.1;
            l1->val = this_add % 10;
            // ���buffer
            if (l1->next == nullptr && l2->next == nullptr && buffer)
            {
                l1->next = new ListNode(buffer);
            }
            // ����
            l1 = l1->next;
            l2 = l2->next;
        }

        // ����header
        return header;
    }
};
