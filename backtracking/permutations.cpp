class Solution {
public:
    vector<int>temp;
    void backtracking(vector<int>& nums,vector<bool>&used,vector<vector<int>>&result)
    {
        if(temp.size()==nums.size())
        {
            result.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(used[i])
            {
                continue;
            }
            temp.push_back(nums[i]);
            used[i]=true;
            backtracking(nums,used,result);
            temp.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>used(nums.size(),false);
        vector<vector<int>>result;
        backtracking(nums,used,result);
        return result;
    }
};
/*
Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
