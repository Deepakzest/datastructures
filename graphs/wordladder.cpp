class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        char original=' ';
        queue<pair<string,int>>Q;
        Q.push({beginWord,0});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);//marking as it is visited
        while(!Q.empty())
        {
            string word=Q.front().first;
            int steps=Q.front().second;
            Q.pop();
            if(word==endWord){return steps+1;}
            for(int i=0;i<word.size();i++)
            {
                original=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        st.erase(word);
                        Q.push({word,steps+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
        
    }
};

/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
*/
