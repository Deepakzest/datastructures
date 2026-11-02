class Solution {
public:
    int DP(vector<vector<int>>&memo,int i,int j,string &word1, string &word2)
    {
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(memo[i][j]!=-1)return memo[i][j];
        if(word1[i]==word2[j])return memo[i][j]=DP(memo,i-1,j-1,word1,word2);
        int insert=DP(memo,i,j-1,word1,word2);
        int del=DP(memo,i-1,j,word1,word2);
        int replace=DP(memo,i-1,j-1,word1,word2);
        return memo[i][j]=1+min({insert,del,replace});
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>memo(m,vector<int>(n,-1));
        return DP(memo,m-1,n-1,word1,word2);
    }
};
