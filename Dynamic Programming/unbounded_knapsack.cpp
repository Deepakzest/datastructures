class Solution {
  public:
    int DP(vector<int>& val, vector<int>& wt, int capacity,unordered_map<string,int>&memory,int currentindex)
    {
        if(capacity==0)
        {
            return 0;
        }
        if(currentindex>=val.size())
        {
            return 0;
        }
        string currentkey=to_string(currentindex)+"_"+to_string(capacity);
        if(memory.find(currentkey)!=memory.end())
        {
            return memory[currentkey];
        }
        int selected=0;
        if(wt[currentindex]<=capacity)
        {
            selected=val[currentindex]+DP(val,wt,capacity-wt[currentindex],memory,currentindex);//current index is not incremented because it is unlimited val
        }
        int notselected=DP(val,wt,capacity,memory,currentindex+1);
        memory[currentkey]=max(selected,notselected);
        return memory[currentkey];
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        unordered_map<string,int>memory;
        return DP(val,wt,capacity,memory,0);
        
    }
};

/*
Given a set of items, each with a weight and a value, represented by the array wt[] and val[] respectively. Also, a knapsack with a weight limit capacity.
Your task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.

Note: Each item can be taken any number of times.

Examples:

Input: val[] = [1, 1], wt[] = [2, 1], capacity = 3
Output: 3
Explanation: The optimal choice is to pick the 2nd element 3 times.
Input: val[] = [10, 40, 50, 70], wt[] = [1, 3, 4, 5], capacity = 8
Output: 110
Explanation: The optimal choice is to pick the 2nd element and the 4th element.
Input: val[] = [6, 8, 7, 100], wt[] = [2, 3, 4, 5], capacity = 1
Output: 0
Explanation: We can't pick any element. Hence, total profit is 0.
*/
