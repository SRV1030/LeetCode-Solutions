// https://leetcode.com/problems/subsets-ii

class Solution {
public: vector<vector<int>> v;
    void util(vector<int>&nums,int ind,vector<int> t){
        v.push_back(t);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            t.push_back(nums[i]);
            util(nums,i+1,t);
            t.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        util(nums,0,{});
        return v;
    }
};