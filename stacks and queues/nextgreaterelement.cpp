class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>result(nums2.size());
        for(int i=nums2.size()-1;i>=0;i--)
        {
            int currentelement=nums2[i];//comming from backwards
            if(st.empty())
            {
                result[i]=-1;
                st.push(currentelement);
                continue;
            }
            if(!st.empty()&&st.top()>currentelement)
            {
                result[i]=st.top();
                st.push(currentelement);
                continue;
            }
            while(!st.empty()&&st.top()<=currentelement)
            {
                st.pop();
            }
            if(st.empty())
            {
               result[i]=-1;
               st.push(currentelement);
            }
            else
            {
                result[i]=st.top();
                st.push(currentelement);

            }
        }
        unordered_map<int,int> mp;

for(int i = 0; i < nums2.size(); i++)
{
    mp[nums2[i]] = result[i];
}

vector<int> answer(nums1.size());

for(int i = 0; i < nums1.size(); i++)
{
    answer[i] = mp[nums1[i]];
}

return answer;
    }
};
