class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int,int>>st;
        int ans=0;
        for(int i=nums.size()-1;i>=0;--i){
            int c=0;
            while(!st.empty() && st.top().first<nums[i]){
                c=max(c+1,st.top().second);
                st.pop();
            }
            st.push({nums[i],c});
            ans=max(ans,c);
        }
        return ans;
    }
};