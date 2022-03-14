// https://leetcode.com/problems/next-greater-element-ii

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        for(int i=n-1;i>=0;i--)st.push(nums[i]);
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]>=st.top())st.pop();
            ans.push_back(st.empty()?-1:st.top());
            st.push(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};