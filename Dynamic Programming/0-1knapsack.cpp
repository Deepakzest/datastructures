class Solution {
  public:
    int DP(int W, vector<int> &val, vector<int> &wt,int currentindex,int n,unordered_map<string,int>&memory)
    {
        if(currentindex==n)
        {
            return 0;
        }
        int current_weight=wt[currentindex];
        int current_val=val[currentindex];
        string currentkey=to_string(currentindex)+"_"+to_string(W);
        if(memory.find(currentkey)!=memory.end())
        {
            return memory[currentkey];
        }
        int selected=0;//since while finding max we cannot find max as it not not declatred in scope
        if(current_weight<=W)
        {
            selected=current_val+DP(W-current_weight,val,wt,currentindex+1,n,memory);
        }
        int notselected=DP(W,val,wt,currentindex+1,n,memory);
        memory[currentkey]=max(selected,notselected);
        return memory[currentkey];
        
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        unordered_map<string,int>memory;
        int n=val.size();//val==wt
        return DP(W,val,wt,0,n,memory);//starting from 0th index
    }
};

/*
Given two arrays, val[] and wt[], where each element represents the value and weight of an item respectively, and an integer W representing the maximum capacity of the knapsack (the total weight it can hold).

Put the items into the knapsack such that the total value obtained is maximum without exceeding the capacity W.

Note: You can either include an item completely or exclude it entirely — fractional selection of items is not allowed. Each item is available only once.

Examples :

Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).
Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
Output: 80
Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.
Constraints:

1 ≤ W, val.size(), val[i], wt.size(), wt[i] ≤ 103
wt.size() = val.size()
*/
