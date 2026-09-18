class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>map(128);
        for(auto c:t)
        {
            map[c]++;//frequency map of t is ready
        }
        int counter=t.size();//3 for example1
        int left=0;
        int right=0;
        int start=0;
        int minlength=INT_MAX;
        while(right<s.size())
        {
            if(map[s[right]]>0)
            {
                counter--;
            }
            map[s[right]]--;
            right++;
            while(counter==0)
            {
                if(right-left<minlength)
                {
                    minlength=right-left;
                    start=left;
                }
                map[s[left]]++;
                if(map[s[left]]>0)
                {
                    counter++;
                }
                left++;
            }
        }
        return minlength==INT_MAX?"":s.substr(start,minlength);
    }
};

/*
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
*/
