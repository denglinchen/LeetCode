/*
完成时间2020年11月17日
题目地址：https://leetcode-cn.com/problems/remove-element/
*/
#pragma once
#include"LCInclude.h"
#include"27_移除元素.h"
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = -1; // 新数组的下标
        // 遍历数组
        for (int i = 0; i < nums.size(); ++i)
        {
            // 如果当前数字不等于要删除的数字则加入新数组
            if (nums[i] != val)
            {
                nums[++index] = nums[i];
            }
        }

        //返回新数组的长度
        return index + 1;
    }
};

// 测试程序
void test_main()
{
    vector<int> test = { 1,1,2,2,3,3,4,5,5,6,7,7,8 };
    int ret = Solution().removeElement(test, 3);
    for (int i = 0; i < test.size(); ++i)
    {
        cout << test[i] << ", ";
    }
    cout << endl;
}