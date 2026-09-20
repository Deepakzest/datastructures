class Solution {
public:
    int DP(vector<int>& nums, int target,unordered_map<string,int>&memory,int currentindex)
    {
        string currentkey=to_string(currentindex)+"_"+to_string(target);
        if(target==0&&currentindex==nums.size())
        {
            return 1;//there is a way exist;
        }
        if(target!=0&&currentindex>=nums.size())
        {
            return 0;//no way exists
        }
        if(memory.find(currentkey)!=memory.end())
        {
            return memory[currentkey];
        }
        int plus=DP(nums,target-nums[currentindex],memory,currentindex+1);
        int minus=DP(nums,target+nums[currentindex],memory,currentindex+1);  //beacuse (-ve) of (-ve) is positive
        memory[currentkey]=plus+minus;
        return memory[currentkey];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int>memory;
        return DP(nums,target,memory,0);
        
    }
};
/*
494. Target Sum
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
*/
