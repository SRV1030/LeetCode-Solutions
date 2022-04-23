class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int del=nums.size()-k;
        vector<int>st;
        for(auto&i:nums){
            while(!st.empty() && i<st.back() && del){
                st.pop_back();
                del--;
            }
            st.push_back(i);
        }
        return vector<int>(st.begin(),st.begin()+k);
    }
};