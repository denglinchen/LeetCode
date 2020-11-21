#pragma once
/*
完成时间2020年11月19日
题目地址：https://leetcode-cn.com/problems/two-sum/
*/
#include"LCInclude.h"
using namespace std;

class Solution {
public:
    // 对于数组中的每一个数字x是否存在另一个数字使得 target - x
    vector<int> twoSum(vector<int>& nums, int target) {
        // 利用哈希表存储 target-x 的下标
        unordered_map<int, int> reference;

        for (int i = 0; i < nums.size(); ++i)
        {
            // 查找目标值
            int target_index = reference[target - nums[i]];
            if (target_index != 0)
            {
                return vector<int>{target_index - 1, i};
            }

            // 将自己值存入哈希表
            reference[nums[i]] = i + 1;
        }

        // 无解则返回空vector
        return vector<int>{};
    }
};
