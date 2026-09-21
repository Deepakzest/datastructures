class Solution {
public:
    int DP(int n,unordered_map<int,int>&memory)
    {
        if(n==0||n==1)
        {
            return 1;
        }
        if(memory.find(n)!=memory.end())
        {
            return memory[n];
        }
        int catalan=0;
        for(int i=0;i<n;i++)
        {
            catalan+=DP(i,memory)*DP(n-1-i,memory);
        }
        return memory[n]=catalan;
    }
    int numTrees(int n) {
        unordered_map<int,int>memory;
        return DP(n,memory);
    }
};
