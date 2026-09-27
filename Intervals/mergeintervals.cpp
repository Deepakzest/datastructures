class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>result;
        vector<int>newinterval=intervals[0];//first=[1,3]
        result.push_back(newinterval);
        for(int i=1;i<intervals.size();i++)
        {
            vector<int>interval=intervals[i];
            if(interval[0]<=newinterval[1])
            {
                newinterval[1]=max(interval[1],newinterval[1]);
                result.back()[1]=newinterval[1];
            }
            else
            {
                newinterval=interval;
                result.push_back(newinterval);
            }

        }
        return result;
        
    }
};
/*
Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
Example 3:

Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.
*/
