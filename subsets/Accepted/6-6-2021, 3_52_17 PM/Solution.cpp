// https://leetcode.com/problems/subsets

class Solution {
public: vector<vector<int>> res;
    void util(vector<int> nums,int ind,vector<int> &temp){
        if(ind==nums.size())res.push_back(temp);
        else{
            util(nums,ind+1,temp);
            temp.push_back(nums[ind]);
            util(nums,ind+1,temp);  
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        vector<int> temp={};
        util(nums,0,temp);
        return res;
    }
};