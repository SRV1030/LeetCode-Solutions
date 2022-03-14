// https://leetcode.com/problems/permutations

class Solution {
public: vector<vector<int>>v;
    void util(vector<int>&nums,int l,int h){
        if(l==h){
            v.push_back(nums);
            return;
        }
        for(int i=l;i<=h;i++){
            swap(nums[i],nums[l]);
            util(nums,l+1,h);
            swap(nums[i],nums[l]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        util(nums,0,nums.size()-1);
        return v;
    }
};