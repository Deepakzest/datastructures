class Solution {
public:
    void findall(string &digits,map<char,string>&mapper,vector<string>&ans,int currentindex, string s)
    {
        if(currentindex>=digits.size())
        {
            ans.push_back(s);
            return;   
        }
        char charnum=digits[currentindex];
        string letter=mapper[charnum];
        for(int i=0;i<letter.size();i++)
        {
            s.push_back(letter[i]);
            findall(digits,mapper,ans,currentindex+1,s);
            s.pop_back();
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        map<char,string>mapper{
            {'1',""},
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"},
        };
        string s="";
        vector<string>ans;
        if(digits.size()==0)
        {
            return ans;
        }
        findall(digits,mapper,ans,0,s);
        return ans;
        
    }
};
