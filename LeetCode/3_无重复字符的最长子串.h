#pragma once
/*
完成时间2020年11月29日
题目地址：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
*/
#include"LCInclude.h"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 哈希集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();

        // 右指针，初始值为-1
        int rk = -1, ans = 0;

        // 枚举左指针的位置
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
            {
                // 左指针右移
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1]))
            {
                // 不断的移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }

            // 检查并且刷新答案
            ans = max(ans, rk - i + 1);
        }

        return ans;
    }
};

void test_main()
{
    string test = "aa";
    cout << Solution().lengthOfLongestSubstring(test) << endl;
}