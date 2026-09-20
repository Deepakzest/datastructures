class Solution {
public:
    int helper(vector<int>& nums, unordered_map<int,int>&DP,int currentindex,int lastindex)
    {
        if(currentindex>lastindex)
        {
            return 0;
        }
        if(currentindex>=nums.size())
        {
            return 0;
        }
        if(DP.find(currentindex)!=DP.end())
        {
            return DP[currentindex];//memoization
        }
        int k=currentindex;//since while returning currentindex value will change
        int rob=nums[currentindex]+helper(nums,DP,currentindex+2,lastindex);//if we rob that house we cannot rob next house so i+2
        int norob=helper(nums,DP,currentindex+1,lastindex);//if we are not robbing that house we can move to next house ,so i+1
        DP[k]=max(rob,norob);
        return DP[k];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        unordered_map<int,int>DP1,DP2;
        int firsthouse=helper(nums,DP1,0,nums.size()-2);//if we start from first house we cannot rob last house[0 to n-2]
        int secondhouse=helper(nums,DP2,1,nums.size()-1);//if we start from secondhouse we can rob last house[1 to n-1]
        return max(firsthouse,secondhouse);
        
    }
};
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000
*/
