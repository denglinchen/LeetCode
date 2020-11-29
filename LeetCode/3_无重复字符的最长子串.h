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
        // 先处理特殊情况
        if (s.size() < 2)
            return s.size();

        // 滑动窗口遍历字符串
        int max_len = 1; // 无重复的最长字符串
        unordered_map<char, int> counter; // 存储字符所在的下标
        // 左指针
        int i = 0;
        // 将第一个元素加入哈希map
        counter[s[0]] = 0;
        // 右指针
        for (int j = i + 1; j < s.size(); ++j)
        {
            // 在窗口中没有重复
            if (counter.count(s[j]) == 0)
            {
                // 检查并且更新最大长度
                max_len = (j - i + 1) > max_len ? (j - i + 1) : max_len;
                // 将该字符的加入哈希map
                counter[s[j]] = j;
            }
            // 出现重复
            else
            {
                // 调整窗口大小
                int new_i = counter[s[j]] + 1;
                while (i < new_i)
                {
                    counter.erase(s[i++]);
                }
                // 修改该重复字符在哈希map中的值
                counter[s[j]] = j;
            }
        }

        // 返回记录的最大长度
        return max_len;
    }
};

void test_main()
{
    string test = "aa";
    cout << Solution().lengthOfLongestSubstring(test) << endl;
}