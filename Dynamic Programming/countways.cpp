
class Solution {
  public:
    int DP(int n,unordered_map<string,int>&memory,int currentindex,vector<int>&score)
    {
        string currentkey=to_string(n)+"_"+to_string(currentindex);
        if(n==0)
        {
            return 1;
        }
        if(currentindex>=score.size())
        {
            return 0;
        }
        if(memory.find(currentkey)!=memory.end())
        {
            return memory[currentkey];
        }
        int select=0;
        if(score[currentindex]<=n)
        {
            select=DP(n-score[currentindex],memory,currentindex,score);
        }
        int notselect=DP(n,memory,currentindex+1,score);
        memory[currentkey]=select+notselect;
        return memory[currentkey];
    }
    int countWays(int n) {
        //  code here
        vector<int>score={3,5,10};
        unordered_map<string,int>memory;
        return DP(n,memory,0,score);
    }
};
/*
Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find number of distinct combinations to reach the given score.

Examples:

Input: n = 10
Output: 2
Explanation:
There are two ways {5,5} and {10}.
Input: n = 20
Output: 4
Explanation:
There are four possible ways. {5,5,5,5}, {3,3,3,3,3,5}, {10,10}, {5,5,10}.
*/
