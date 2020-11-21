#pragma once
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;

// Definition for singly - linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

namespace TEST_TOOL
{
    void print_vector_int(vector<int>& vec)
    {
        if (vec.size() == 0)
            return;

        for (int i = 0; i < vec.size(); ++i)
        {
            cout << vec[i];
            if (i < vec.size() - 1)
                cout << ", ";
        }
    }
}
 
