class Solution {
public:
    int helper(int n,vector<int>&DP)
    {
        if(n<=1)
        {
            return n;
        }
        if(n==2)
        {
            return 1;
        }
        if(DP[n]!=-1)
        {
            return DP[n];
        }
        return DP[n]=helper(n-1,DP)+helper(n-2,DP)+helper(n-3,DP);
        
    }
    int tribonacci(int n) {
        vector<int>DP(n+1,-1);
        return helper(n,DP);
    }
};
/*
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537
*/
