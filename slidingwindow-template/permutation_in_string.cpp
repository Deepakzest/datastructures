class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freqS1(128,0);
        vector<int>freqS2(128,0);
        int windowsize=s1.size();
        for(char c:s1)
        {
            freqS1[c]++;
        }
        int left=0;
        for(int right=0;right<s2.size();right++)
        {
            freqS2[s2[right]]++;
            if(right-left+1>windowsize)
            {
                freqS2[s2[left]]--;
                left++;
            }
            if(right-left+1==windowsize)
            {
                if(freqS1==freqS2)
                {
                    return true;
                }
            }
        }
        return false;
        
    }
};

/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
*/
