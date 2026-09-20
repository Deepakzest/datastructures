class Solution {
public:
    int mincost(vector<int>& cost,unordered_map<int,int>&DP,int currentindex)
    {
        if(currentindex==cost.size())return 0;
        if(currentindex>cost.size())return 1000;
        if(DP.find(currentindex)!=DP.end())return DP[currentindex];//memoization
        int onestep=cost[currentindex]+mincost(cost,DP,currentindex+1);
        int twostep=cost[currentindex]+mincost(cost,DP,currentindex+2);
        DP[currentindex]=min(onestep,twostep);
        return DP[currentindex];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int,int>DP;
        return min(mincost(cost,DP,0),mincost(cost,DP,1));//starting from 0 or 1
        
    }
};
/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase.

Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the staircase, which is the position just past the last step (index cost.length).

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
*/
