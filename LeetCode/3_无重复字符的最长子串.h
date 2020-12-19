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
        // ��ϣ���ϣ���¼ÿ���ַ��Ƿ���ֹ�
        unordered_set<char> occ;
        int n = s.size();

        // ��ָ�룬��ʼֵΪ-1
        int rk = -1, ans = 0;

        // ö����ָ���λ��
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
            {
                // ��ָ������
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1]))
            {
                // ���ϵ��ƶ���ָ��
                occ.insert(s[rk + 1]);
                ++rk;
            }

            // ��鲢��ˢ�´�
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