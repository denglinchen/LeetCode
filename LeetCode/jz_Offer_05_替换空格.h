#pragma once
/*
���ʱ��2020��11��28��
��Ŀ��ַ��https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
*/
#include"LCInclude.h"
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int blank_num = 0; // �ո����

        // ͳ�ƿո���Ŀ
        for (char& c : s)
            if (c == ' ')
                ++blank_num;

        // �³��ȵĶ���string
        string new_str(s.size() + blank_num * 2, ' ');

        // ����
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

        // ���ؽ��
        return new_str;
    }
};