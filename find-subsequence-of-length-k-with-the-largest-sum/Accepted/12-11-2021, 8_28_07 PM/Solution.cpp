// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>t1,t2;
        for(int i=0;i<nums.size();i++)t1.push_back({nums[i],i});
        sort(t1.begin(),t1.end());
        for(int i=t1.size()-1;i>=0&&k--;i--) t2.push_back({t1[i].second,t1[i].first});
        sort(t2.begin(),t2.end());
        vector<int>ans;
        for(auto& i:t2)ans.push_back(i.second);
        return ans;
    }
};