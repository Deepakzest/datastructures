class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int num:nums)
        {
            ans=ans^num;
        }
        return ans;
        /*
        unordered_map<int,int>mp;
        for(int num:nums)
        {
            mp[num]++;
        }
        for(auto &[num,count]:mp)
        {
            if(count==1)
            {
                return num;
            }
        }
        return -1;
        */
    }
};

/*
Example 1:

Input: nums = [2,2,1]

Output: 1

Example 2:

Input: nums = [4,1,2,1,2]

Output: 4

Example 3:

Input: nums = [1]

Output: 1
*/
