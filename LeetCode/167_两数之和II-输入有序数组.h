#pragma once
/*
完成时间2020年11月19日
题目地址：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
*/
#include"LCInclude.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0; // 左指针
        int right = numbers.size() - 1; // 右指针
        while (right > left)
        {
            int num = numbers[left] + numbers[right]; // 当前两个指针所指得数字之和
            if (num < target) // 如果相加之和小于目标
            {
                // 左指针右移，下一次两数之和变大
                ++left;
            }
            else if (num > target) // 如果相加之和大于目标
            {
                // 右指针左移
                --right;
            }
            else // 相等的情况
            {
                return vector<int>{left + 1, right + 1};
            }
        }

        return vector<int>{};
    }
};

