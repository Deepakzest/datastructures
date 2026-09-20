class Solution {
public:
    int DP(int amount, vector<int>& coins,vector<vector<int>>&memory,int currentindex)
    {
        if(amount==0)
        {
            return 1;//there is a way
        }
        if(currentindex>=coins.size())
        {
            return 0;//no way
        }
        if(memory[currentindex][amount]!=-1)
        {
            return memory[currentindex][amount];
        }
        int select=0;
        if(coins[currentindex]<=amount)
        {
            select=DP(amount-coins[currentindex],coins,memory,currentindex);
        }
        int notselected=DP(amount,coins,memory,currentindex+1);
        memory[currentindex][amount]=select+notselected;
        return memory[currentindex][amount];
    }
    //similar to unbounded knapsack
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>memory(coins.size()+1,vector<int>(amount+1,-1));
        return DP(amount,coins,memory,0);//starting from zero
        
    }
};
