class Solution {
public:
    vector<vector<int>>result;
    vector<int>temp;
    void helper(vector<int>nums,int index)
    {
        if(index==nums.size())
        {
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        helper(nums,index+1);
        temp.pop_back();
        helper(nums,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int index=0;
        helper(nums,index);
        return result;
        
    }
};

/*
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/
