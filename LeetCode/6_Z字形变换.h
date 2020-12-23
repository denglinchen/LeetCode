#pragma once
/*
完成时间2020年12月22日
题目地址：https://leetcode-cn.com/problems/zigzag-conversion/
*/
#include"LCInclude.h"
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)return s;
        // 先计算列数
        int unit = (2 * numRows) - 2; // 每一对竖直边和斜边的字符数
        int unit_cols = unit - numRows + 1; // 每一对边的列数
        int cols = (s.size() / unit) * unit_cols;
        int remainder = s.size() % unit;
        if (remainder > 0)
            cols += unit_cols;

        // 建立二维矩阵
        vector<vector<char>> mat(numRows, vector<char>(cols, ' '));

        // 填充位置
        int row = 0;
        int col = 0;
        int index = 0;

        while (index < s.size() && row < numRows && col< cols)
        {
            // 在垂直的列
            if ((index % unit) < numRows)
            {
                // 填充矩阵
                mat[row][col] = s[index];
                // 移动填充位置和字符串下标
                ++row;
                ++index;
                if (row >= numRows)
                {
                    row = numRows - 2;
                    ++col;
                }
            }
            // 在斜边
            else
            {
                // 填充矩阵
                mat[row][col] = s[index];
                --row;
                ++col;
                ++index;
            }
        }

        // 按顺序输出
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

        // 返回结果
        return s;
    }
};

void test_main()
{
    string test = "LEETCODEISHIRING";
    cout << Solution().convert(test, 4) << endl;
}
