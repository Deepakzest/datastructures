class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int>freq;//ordered map
        for(auto num:nums)
        {
            freq[num]++;
        }
        int result=0;
        for (auto pair:freq)
        {
            if(freq.find(pair.first+1)!=freq.end())
            {
                result=max(result,pair.second+freq[pair.first+1]);
            }
        }
        return result;
    }
};
/*
We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

 

Example 1:

Input: nums = [1,3,2,2,5,2,3,7]

Output: 5

Explanation:

The longest harmonious subsequence is [3,2,2,2,3].
*/
