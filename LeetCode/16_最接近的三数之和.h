#pragma once
/*
完成时间2020年11月26日
题目地址：https://leetcode-cn.com/problems/3sum-closest/
*/
#include"LCInclude.h"
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = 0;
        // 判断数组是否合规
        if (nums.size() < 3)
        {
            for (int& num : nums)
                ret += num;
            return ret;
        }
        ret = nums[0] + nums[1] + nums[2];
        // 排序
        sort(nums.begin(), nums.end());
        // 最外层循环，第一个数字的遍历
        for (int first = 0; first < nums.size() - 2; ++first)
        {
            // 第二个数字和第三个数字的下标
            int sec = first + 1;
            int thr = nums.size() - 1;

            while (thr > sec)
            {
                // 当前的三数之和
                int cur_ret = nums[first] + nums[sec] + nums[thr];
                
                // 对当前求和的结果与目标数的差值进行一次判断
                if (cur_ret == target)
                    // 相等的时候直接返回结果
                    return cur_ret;
                else if(abs(cur_ret - target) <= abs(ret - target))
                {
                    // 当前差值小于之前的差值则更新被保存的结果
                    ret = cur_ret;
                }

                // 移动第二个和第三个指针
                if (cur_ret > target)
                {
                    --thr;
                    while (thr >= 0 && nums[thr] == nums[thr + 1])
                        --thr;
                }
                else if (cur_ret < target)
                {
                    ++sec;
                    while (sec < nums.size() && nums[sec] == nums[sec - 1])
                        ++sec;
                }
            }
        }

        // 返回最后的结果
        return ret;
    }
};
