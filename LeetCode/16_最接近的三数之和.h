#pragma once
/*
���ʱ��2020��11��26��
��Ŀ��ַ��https://leetcode-cn.com/problems/3sum-closest/
*/
#include"LCInclude.h"
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = 0;
        // �ж������Ƿ�Ϲ�
        if (nums.size() < 3)
        {
            for (int& num : nums)
                ret += num;
            return ret;
        }
        ret = nums[0] + nums[1] + nums[2];
        // ����
        sort(nums.begin(), nums.end());
        // �����ѭ������һ�����ֵı���
        for (int first = 0; first < nums.size() - 2; ++first)
        {
            // �ڶ������ֺ͵��������ֵ��±�
            int sec = first + 1;
            int thr = nums.size() - 1;

            while (thr > sec)
            {
                // ��ǰ������֮��
                int cur_ret = nums[first] + nums[sec] + nums[thr];
                
                // �Ե�ǰ��͵Ľ����Ŀ�����Ĳ�ֵ����һ���ж�
                if (cur_ret == target)
                    // ��ȵ�ʱ��ֱ�ӷ��ؽ��
                    return cur_ret;
                else if(abs(cur_ret - target) <= abs(ret - target))
                {
                    // ��ǰ��ֵС��֮ǰ�Ĳ�ֵ����±�����Ľ��
                    ret = cur_ret;
                }

                // �ƶ��ڶ����͵�����ָ��
                if (cur_ret > target)
                {
                    --thr;
                    while (thr >= 0 && nums[thr] == nums[thr + 1])
                        --thr;
                }
                else if (cur_ret < target)
                {
                    ++sec;
                    while (sec < nums.size() && nums[sec] == nums[sec - 1])
                        ++sec;
                }
            }
        }

        // �������Ľ��
        return ret;
    }
};
