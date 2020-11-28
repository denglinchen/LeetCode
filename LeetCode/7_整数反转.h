#pragma once
/*
完成时间2020年11月25日
题目地址：https://leetcode-cn.com/problems/reverse-integer/
*/
#include"LCInclude.h"
using namespace std;

class Solution {
public:
    int reverse(int x) {
        // 判断最简单的情况
        if (x< 10 && x> -10)
            return x;

        // 记录反转之后的数字
        int rev = 0;
        
        // 逐位反转
        while (x != 0)
        {
            // 这一次的数字
            int pop = x % 10;
            x /= 10;
            // 判断是否溢出
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
                return 0;
            else if(rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
                return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};