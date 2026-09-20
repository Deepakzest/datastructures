class Solution {
public:
    bool DP(int targetsum,vector<int>&nums,int currentindex,unordered_map<string,bool>&memory)
    {
        if(targetsum==0)
        {
            return true;
        }
        if(currentindex>=nums.size())
        {
            return false;
        }
        string currentkey=to_string(currentindex)+"_"+to_string(targetsum);
        if(memory.find(currentkey)!=memory.end())
        {
            return memory[currentkey];
        }
        bool possible=false;
        if(nums[currentindex]<=targetsum)
        {
        possible=DP(targetsum-nums[currentindex],nums,currentindex+1,memory);
        }
        if(possible)
        {
            return memory[currentkey]=true;//if already possible return true directly no need to check notpossible
        }
        bool notpossible=DP(targetsum,nums,currentindex+1,memory);
        return memory[currentkey]=possible||notpossible;
    }
    bool canPartition(vector<int>& nums) {
        int total=std::accumulate(nums.begin(),nums.end(),0);
        if(total%2!=0)return false;//cannot be partioned
        unordered_map<string,bool>memory;
        return DP(total/2,nums,0,memory);
    }
};

/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
*/
