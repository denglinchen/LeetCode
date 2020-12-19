#pragma once
/*
完成时间2020年12月19日
题目地址：https://leetcode-cn.com/problems/palindromic-substrings/
*/
#include"LCInclude.h"
using namespace std;

class Solution {
public:
    // 计算以mid1, mid2为中心位置的回文串个数
    int getSubStrings(string& s, int mid1, int mid2)
    {
        int ret = 0;
        int len = s.size();
        while (mid1 >= 0 && mid2 < len && s[mid1] == s[mid2])
        {
            --mid1;
            ++mid2;
            ++ret;
        }
        return ret;
    }

    // 采用中心扩展法
    int countSubstrings(string s) {
        int ret = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            // 奇数对称的情况
            ret += getSubStrings(s, i, i);
            // 偶数对称的情况
            if (i + 1 < s.size())
            {
                ret += getSubStrings(s, i, i + 1);
            }
        }

        // 返回结果
        return ret;
    }
};
