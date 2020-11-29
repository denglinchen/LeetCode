#pragma once
/*
完成时间2020年11月28日
题目地址：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
*/
#include"LCInclude.h"
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int blank_num = 0; // 空格计数

        // 统计空格数目
        for (char& c : s)
            if (c == ' ')
                ++blank_num;

        // 新长度的定长string
        string new_str(s.size() + blank_num * 2, ' ');

        // 拷贝
        int new_i = 0;
        for (int i = 0; i < s.size(); ++i, ++new_i)
        {
            if (s[i] != ' ')
                new_str[new_i] = s[i];
            else
            {
                new_str[new_i++] = '%';
                new_str[new_i++] = '2';
                new_str[new_i] = '0';
            }
        }

        // 返回结果
        return new_str;
    }
};