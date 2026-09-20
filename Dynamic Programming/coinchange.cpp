class Solution {
public:
    int DP(vector<int>& coins, int amount, vector<vector<int>>&memory,int currentindex)
    {
        if(amount==0)
        {
            return 0;
        }
        if(currentindex>=coins.size())
        {
            return 100000;
        }
        if(memory[currentindex][amount]!=-1)
        {
            return memory[currentindex][amount];
        }
        int selected=100000;
        if(coins[currentindex]<=amount)
        {
            selected=1+DP(coins,amount-coins[currentindex],memory,currentindex); //adding 1 beacuse there is a way
        }
        int notselected=DP(coins,amount,memory,currentindex+1);
        memory[currentindex][amount]=min(selected,notselected);
        return memory[currentindex][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>memory(coins.size()+1,vector<int>(amount+1,-1));
        int ans=DP(coins,amount,memory,0);
        if(ans==100000)
        {
            return -1;
        }
        return ans;

    }
};
/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/
