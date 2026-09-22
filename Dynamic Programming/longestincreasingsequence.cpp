class Solution {
public:
    int DP(int current,int previous,vector<int>&nums,vector<vector<int>>&memory)
    {
        if(current>=nums.size())
        {
            return 0;
        }
        if(memory[current][previous+1]!=-1)
        {
            return memory[current][previous+1];
        }
        int notselected=DP(current+1,previous,nums,memory);
        int selected=0;
        if(previous==-1||nums[current]>nums[previous])
        {
            selected=1+DP(current+1,current,nums,memory);
        }
        memory[current][previous+1]=max(selected,notselected);
        return memory[current][previous+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>memory(nums.size()+1,vector<int>(nums.size()+1,-1));
        return DP(0,-1,nums,memory);
    }
};
/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
*/
