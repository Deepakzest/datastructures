class Solution {
  public:
    int DP(vector<int> &price,int rodlength,vector<vector<int>>&memory,int currentindex)
    {
        if(rodlength==0)
        {
            return 0;
        }
        if(currentindex>=rodlength)
        {
            return 0;
        }
        if(memory[currentindex][rodlength]!=-1)
        {
            return memory[currentindex][rodlength];
        }
        int selected=0;
        if(currentindex+1<=rodlength)
        {
            selected=price[currentindex]+DP(price,rodlength-currentindex-1,memory,currentindex);
        }
        int notselected=DP(price,rodlength,memory,currentindex+1);
        memory[currentindex][rodlength]=max(selected,notselected);
        return memory[currentindex][rodlength];
    }
    int cutRod(vector<int> &price) {
        // code here
        int rodlength=price.size();
        vector<vector<int>>memory(rodlength+1,vector<int>(rodlength+1,-1));
        return DP(price,rodlength,memory,0);
    }
};
