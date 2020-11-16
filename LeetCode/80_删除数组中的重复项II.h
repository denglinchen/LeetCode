/*
完成时间：2020年11月16日
题目地址：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/
*/
#pragma once
#include"LCInclude.h"
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 判断nums的元素数量，排除特殊情况
        if (nums.size() <= 2)
        {
            return nums.size();
        }

        //一般情况的处理
        const int MAX_TIMES = 2; // 可以重复的最大次数2
        int cur_times = 1; // 当前元素的重复次数,起始时为第一个元素的次数1
        int slow = 0; // 慢指针从0开始
        int fast = 1; // 快指针从1开始

        //使用快指针对容器进行遍历
        for (; fast < nums.size(); ++fast)
        {
            if (nums[fast] == nums[slow] && cur_times < MAX_TIMES)
            {
                // 重复,且重复次数小于最大可重复次数
                nums[++slow] = nums[fast]; // 将该元素填充
                ++cur_times; //增加重复计数
            }
            else if (nums[fast] != nums[slow])
            {
                // 遇见新元素时
                nums[++slow] = nums[fast]; // 将新元素填充
                cur_times = 1; // 重置计数
            }
        }

        // 返回结果
        return slow + 1;
    }
};

//测试程序
void test_main()
{
    vector<int> test = { 1,1,2,2,3,3,4,5,5,6,7,7,8 };
    int ret = Solution().removeDuplicates(test);
    for (int i = 0; i < test.size(); ++i)
    {
        cout << test[i] << ", ";
    }
    cout << endl;
}


