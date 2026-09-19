class Solution {
public:
    pair<int,int>expand(string &s,int left,int right)
    {
        while(left>=0&&right<=s.length()&&s[left]==s[right])
        {
            left--;
            right++;
        }
        return{left+1,right-1};
    }
    string longestPalindrome(string s) {
        int start=0;
        int end=0;
        for(int i=0;i<s.length();i++)
        {
            auto[l1,r1]=expand(s,i,i);//odd length
            if(r1-l1>end-start)
            {
                start=l1;
                end=r1;
            }
            auto[l2,r2]=expand(s,i,i+1);//even length
            if(r2-l2>end-start)
            {
                start=l2;
                end=r2;
            }
        }
        return s.substr(start,end-start+1);
    }
};

/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
*/
