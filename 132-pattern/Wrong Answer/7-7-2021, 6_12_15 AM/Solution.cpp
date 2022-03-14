// https://leetcode.com/problems/132-pattern

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return false;
        stack<int> st;
         vector<int>nsl;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]<=st.top())st.pop();
            int a=st.empty()?nums[i]:st.top();
            st.push(nums[i]);
            nsl.push_back(a);
        }
        st=stack<int>();
        vector<int>nsr;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]<=st.top())st.pop();
            int a=st.empty()?nums[i]:st.top();
            st.push(nums[i]);
            nsr.push_back(a);
        }
        reverse(nsr.begin(),nsr.end());
        for(int i=1;i<n-1;i++){
            // cout<<nsl[i]<<" "<<nums[i]<<" "<<nsr[i]<<"\n";
            if(nums[i]!=nsl[i]&& nums[i]!=nsr[i] && nsr[i]>nsl[i]) return true;
        }
        return false;
        
    }
};