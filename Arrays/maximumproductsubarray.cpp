class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int product=1;
        for(int i=0;i<nums.size();i++)
        {
            product*=nums[i];
            ans=max(ans,product);
            if(product==0)
            {
                product=1;
            }
        }
        product=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            product*=nums[i];
            ans=max(ans,product);
            if(product==0)
            {
                product=1;
            }
        }
        return ans;
    }
};

/*
Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/
