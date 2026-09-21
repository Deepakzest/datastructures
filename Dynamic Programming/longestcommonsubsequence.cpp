class Solution {
public:
    int DP(string &text1, string &text2,int i,int j,vector<vector<int>>&memory)
    {
        if(i>=text1.size()||j>=text2.size())
        {
            return 0;
        }
        if(memory[i][j]!=-1)
        {
            return memory[i][j];
        }
        int selected=0;
        int notselected=0;
        if(text1[i]==text2[j])
        {
            selected=1+DP(text1,text2,i+1,j+1,memory);
        }
        else
        {
            int skiptext1=DP(text1,text2,i+1,j,memory);
            int skiptext2=DP(text1,text2,i,j+1,memory);
            notselected=max(skiptext1,skiptext2);
        }
        memory[i][j]=max(selected,notselected);
        return memory[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>memory(text1.size()+1,vector<int>(text2.size()+1,-1));
        return DP(text1,text2,0,0,memory);
        
    }
};
/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
*/
