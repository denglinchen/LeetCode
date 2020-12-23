#pragma once
/*
���ʱ��2020��12��22��
��Ŀ��ַ��https://leetcode-cn.com/problems/zigzag-conversion/
*/
#include"LCInclude.h"
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)return s;
        // �ȼ�������
        int unit = (2 * numRows) - 2; // ÿһ����ֱ�ߺ�б�ߵ��ַ���
        int unit_cols = unit - numRows + 1; // ÿһ�Աߵ�����
        int cols = (s.size() / unit) * unit_cols;
        int remainder = s.size() % unit;
        if (remainder > 0)
            cols += unit_cols;

        // ������ά����
        vector<vector<char>> mat(numRows, vector<char>(cols, ' '));

        // ���λ��
        int row = 0;
        int col = 0;
        int index = 0;

        while (index < s.size() && row < numRows && col< cols)
        {
            // �ڴ�ֱ����
            if ((index % unit) < numRows)
            {
                // ������
                mat[row][col] = s[index];
                // �ƶ����λ�ú��ַ����±�
                ++row;
                ++index;
                if (row >= numRows)
                {
                    row = numRows - 2;
                    ++col;
                }
            }
            // ��б��
            else
            {
                // ������
                mat[row][col] = s[index];
                --row;
                ++col;
                ++index;
            }
        }

        // ��˳�����
        index = 0;
        for(int r = 0; r< mat.size(); ++r)
            for (int c = 0; c < mat[0].size(); ++c)
            {
                if (mat[r][c] != ' ')
                {
                    s[index] = mat[r][c];
                    ++index;
                }
                
            }

        // ���ؽ��
        return s;
    }
};

void test_main()
{
    string test = "LEETCODEISHIRING";
    cout << Solution().convert(test, 4) << endl;
}
