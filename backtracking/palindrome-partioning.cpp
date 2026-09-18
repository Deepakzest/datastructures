class Solution {
public:
    bool ispalindrome(string s)
    {
        string s2=s;
        reverse(s2.begin(),s2.end());
        return s2==s;
    }
    void getallparts(string s,vector<vector<string>>&result,vector<string>&parts)
    {
        if(s.size()==0)
        {
            result.push_back(parts);
            return;
        }
        for(int i=0;i<s.size();i++)
        {
            string part=s.substr(0,i+1);
            if(ispalindrome(part))
            {
                parts.push_back(part);
                getallparts(s.substr(i+1),result,parts);
                parts.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>part;
        getallparts(s,result,part);
        return result;
        
    }
};

/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
*/
