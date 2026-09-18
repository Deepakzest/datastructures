class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0;
        int one=0;
        int two=nums.size()-1;
        while(one<=two)
        {
            if(nums[one]==0)
            {
                swap(nums[zero],nums[one]);
                zero++;
                one++;
            }
            else if(nums[one]==1)
            {
                one++;
            }
            else
            {
                swap(nums[one],nums[two]);
                two--;
            }
        }      
    }
};

/*
Input: nums = [2,0,2,1,1,0]

Output: [0,0,1,1,2,2]

Explanation:

The array has two 0s, two 1s, and two 2s. Sorting them in-place places all 0s first, then all 1s, then all 2s.
*/
