class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(auto num:nums)
        {
            freq[num]++;
        }
        priority_queue<pair<int,int>>maxheap;
        for(auto num:freq)
        {
            maxheap.push({num.second,num.first});
        }
        vector<int>result;
        while(k--)
        {
            result.push_back(maxheap.top().second);
            maxheap.pop();
        }
        return result;


        
    }
};


/*
Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]
*/
