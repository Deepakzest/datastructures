class Solution {
public:
    int helper(vector<int>& nums, unordered_map<int,int>&DP,int currentindex)
    {
        if(currentindex>=nums.size())
        {
            return 0;
        }
        if(DP.find(currentindex)!=DP.end())
        {
            return DP[currentindex];//memoization
        }
        int k=currentindex;//since while returning currentindex value will change
        int rob=nums[currentindex]+helper(nums,DP,currentindex+2);//if we rob that house we cannot rob next house so i+2
        int norob=helper(nums,DP,currentindex+1);//if we are not robbing that house we can move to next house ,so i+1
        DP[k]=max(rob,norob);
        return DP[k];
    }
    int rob(vector<int>& nums) {
        unordered_map<int,int>DP;
        return helper(nums,DP,0);//starting from zero index
        
    }
};
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
*/
