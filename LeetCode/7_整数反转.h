#pragma once
/*
���ʱ��2020��11��25��
��Ŀ��ַ��https://leetcode-cn.com/problems/reverse-integer/
*/
#include"LCInclude.h"
using namespace std;

class Solution {
public:
    int reverse(int x) {
        // �ж���򵥵����
        if (x< 10 && x> -10)
            return x;

        // ��¼��ת֮�������
        int rev = 0;
        
        // ��λ��ת
        while (x != 0)
        {
            // ��һ�ε�����
            int pop = x % 10;
            x /= 10;
            // �ж��Ƿ����
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
                return 0;
            else if(rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
                return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};