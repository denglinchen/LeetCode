#pragma once
#include"LCInclude.h"
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
        {
            // 数组为空时直接返回0
            return 0;
        }
        else if (nums.size() == 1)
        {
            // 数组只有一个元素的时候直接返回1
            return 1;
        }

        int index_slow = 0;       // 慢指针
        int index_fast = 1;       // 快指针

        // 快指针遍历数组
        for (; index_fast < nums.size(); ++index_fast)
        {
            // 快指针遍历到不重复的元素的时候将这个不重复的元素写回到慢指针处
            if (nums[index_fast] != nums[index_fast - 1])
            {
                // 优化：只有快慢指针不相邻的时候才需要写入
                if (index_fast - index_slow > 1)
                    nums[index_slow + 1] = nums[index_fast];
                // 慢指针步进
                ++index_slow;
            }
        }

        //返回不重复部分的长度
        return index_slow + 1;
    }
};

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
