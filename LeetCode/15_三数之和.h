#pragma once
/*
完成时间2020年11月24日
题目地址：https://leetcode-cn.com/problems/3sum/
*/
#include"LCInclude.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 判断数组是否违规
        if (nums.size() < 3)
            return vector<vector<int>>();

        // 数组排序
        sort(nums.begin(), nums.end());
        //最后的结果数组
        vector<vector<int>> ret;

        int first_index = 0; // 第一个数字的下标
        // 遍历数组
        for (; first_index < nums.size() - 2; ++first_index)
        {
            // 重复时跳过
            if (first_index - 1 >= 0 && nums[first_index] == nums[first_index - 1])
                continue;

            // 寻找后面两个数字
            int target = -nums[first_index]; // 和的目标
            int start = first_index + 1;
            int end = nums.size() - 1;
            // 双指针法寻找
            while (end > start)
            {
                if (nums[start] + nums[end] > target)
                    --end;
                else if (nums[start] + nums[end] < target)
                    ++start;
                else
                {
                    // 找到的情况
                    vector<int> this_ret = { nums[first_index], nums[start], nums[end] };
                    ret.push_back(this_ret);
                    // 跳过重复
                    ++start;
                    --end;
                    while (start < nums.size() && nums[start] == nums[start - 1])
                        ++start;
                    while (end >= 0 && nums[end] == nums[end + 1])
                        --end;
                }
            }
        }

        // 返回结果
        return ret;
    }
};
