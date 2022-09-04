class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<size(nums)-1;++i)
            if(!st.insert(nums[i+1]+nums[i]).second) return true;         
        return false;
    }
};