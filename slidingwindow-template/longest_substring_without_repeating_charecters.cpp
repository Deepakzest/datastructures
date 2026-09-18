class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(128,0);
        int left=0;
        int maxlen=0;
        for(int right=0;right<s.size();right++)
        {
            freq[s[right]]++;
            while(freq[s[right]]>1)
            {
                freq[s[left]]--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
        
    }
};
/*
nput: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
*/
