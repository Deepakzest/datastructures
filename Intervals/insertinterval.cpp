class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newinterval) {
        int n=intervals.size();
        int i=0;
        vector<vector<int>>result;
        while(i<n&&intervals[i][1]<newinterval[0])//left part
        {
            result.push_back(intervals[i]);
            i++;
        }
        while(i<n&&intervals[i][0]<=newinterval[1])
        {
            newinterval[0]=min(intervals[i][0],newinterval[0]);
            newinterval[1]=max(intervals[i][1],newinterval[1]);
            i++;
        }
        result.push_back(newinterval);
        while(i<n)
        {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
        
    }
};
/*
Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/
