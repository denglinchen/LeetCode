#pragma once
/*
���ʱ��2020��12��19��
��Ŀ��ַ��https://leetcode-cn.com/problems/palindromic-substrings/
*/
#include"LCInclude.h"
using namespace std;

class Solution {
public:
    // ������mid1, mid2Ϊ����λ�õĻ��Ĵ�����
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

    // ����������չ��
    int countSubstrings(string s) {
        int ret = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            // �����ԳƵ����
            ret += getSubStrings(s, i, i);
            // ż���ԳƵ����
            if (i + 1 < s.size())
            {
                ret += getSubStrings(s, i, i + 1);
            }
        }

        // ���ؽ��
        return ret;
    }
};
