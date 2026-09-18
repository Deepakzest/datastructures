class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>result;
        vector<int>freqP(128,0);
        for(char c:p)
        {
            freqP[c]++;
        }
        int left=0;
        vector<int>freqS(128,0);
        int windowsize=p.size();
        for(int right=0;right<s.size();right++)
        {
            freqS[s[right]]++;
            if(right-left+1>windowsize)
            {
                freqS[s[left]]--;
                left++;
            }
            if(right-left+1==windowsize)
            {
                if(freqS==freqP)
                {
                    result.push_back(left);
                }
            }
        }
        return result;
        
    }
};

/*
Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/
