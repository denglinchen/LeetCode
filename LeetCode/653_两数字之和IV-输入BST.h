#pragma once
/*
完成时间2020年11月20日
题目地址：https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/
*/
#include"LCInclude.h"
using namespace std;

class Solution {
public:
    unordered_set<int> counter;
    bool findTarget(TreeNode* root, int k) {
        // 判空
        if (root == nullptr)
            return false;

        if (counter.count(k - root->val) > 0) // 当前节点满足结果
        {
            return true;
        }
        else // 当前节点不满足结果
        {
            // 把该节点插入hash表
            counter.insert(root->val);
            // 继续探查左右子节点
            return findTarget(root->right,k) || findTarget(root->left,k);
        }

        return false;
    }   
};
