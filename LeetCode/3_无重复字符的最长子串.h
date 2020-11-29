#pragma once
/*
���ʱ��2020��11��29��
��Ŀ��ַ��https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
*/
#include"LCInclude.h"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // �ȴ����������
        if (s.size() < 2)
            return s.size();

        // �������ڱ����ַ���
        int max_len = 1; // ���ظ�����ַ���
        unordered_map<char, int> counter; // �洢�ַ����ڵ��±�
        // ��ָ��
        int i = 0;
        // ����һ��Ԫ�ؼ����ϣmap
        counter[s[0]] = 0;
        // ��ָ��
        for (int j = i + 1; j < s.size(); ++j)
        {
            // �ڴ�����û���ظ�
            if (counter.count(s[j]) == 0)
            {
                // ��鲢�Ҹ�����󳤶�
                max_len = (j - i + 1) > max_len ? (j - i + 1) : max_len;
                // �����ַ��ļ����ϣmap
                counter[s[j]] = j;
            }
            // �����ظ�
            else
            {
                // �������ڴ�С
                int new_i = counter[s[j]] + 1;
                while (i < new_i)
                {
                    counter.erase(s[i++]);
                }
                // �޸ĸ��ظ��ַ��ڹ�ϣmap�е�ֵ
                counter[s[j]] = j;
            }
        }

        // ���ؼ�¼����󳤶�
        return max_len;
    }
};

void test_main()
{
    string test = "aa";
    cout << Solution().lengthOfLongestSubstring(test) << endl;
}