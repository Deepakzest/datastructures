class Solution {
public:
    int DP(vector<int>&arr,int currentindex,unordered_map<int,int>&memory)
    {
        if(currentindex>=arr.size())
        {
            return 0;
        }
        if(memory.find(currentindex)!=memory.end())
        {
            return memory[currentindex];
        }
        int rob=arr[currentindex]+DP(arr,currentindex+2,memory);
        int notrob=DP(arr,currentindex+1,memory);
        memory[currentindex]=max(rob,notrob);
        return memory[currentindex];
    }
    int deleteAndEarn(vector<int>& nums) {
        //changing the problem similar to houserobber
        map<int,int>freq;//using ordered map so it stored in sorted order
        int maxi=-1;
        for(auto num:nums)
        {
            maxi=max(maxi,num);
            freq[num]++;
        }
        vector<int>arr(maxi+1,-1);
        for(auto num:freq)
        {
            int i=num.first;
            int j=num.second;
            arr[i]=i*j;
        }
        //now same house robber problem
        unordered_map<int,int>memory;
        return DP(arr,0,memory);//starting index;
    }
};

/*
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.

 

Example 1:

Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.
Example 2:

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.
*/
