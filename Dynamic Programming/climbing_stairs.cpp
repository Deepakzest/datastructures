class Solution {
public:
    int climbStairs(int n,vector<int>&DP)
    {
        if(n<=3)
        {
            return DP[n]=n;
        }
        if(DP[n]!=-1)
        {
            return DP[n];
        }
        return DP[n]=climbStairs(n-1)+climbStairs(n-2);
        
    }
    int climbStairs(int n) {
        vector<int>DP(n+1,-1);
        return climbStairs(n,DP);
        
    }
};

/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/
