class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int ans=INT_MAX;
        int sum=0;
        for(int right=0;right<nums.size();right++)
        {
            sum=sum+nums[right];
            while(sum>=target)
            {
                ans=min(ans,right-left+1);
                sum-=nums[left];
                left++;
                
            }
            
        }
        return ans==INT_MAX?0:ans;
    }
};

/*
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
*/
