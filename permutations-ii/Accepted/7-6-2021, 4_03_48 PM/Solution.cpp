// https://leetcode.com/problems/permutations-ii

class Solution {
public:
   set<vector<int>> v;
    void perm(vector<int> nums,int l,int h){
        if(l==h){
            v.insert(nums);
            return;
        }
        for(int i=l;i<=h;i++){
            swap(nums[l],nums[i]);
            perm(nums,l+1,h);
            swap(nums[i],nums[l]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       perm(nums,0,nums.size()-1);
        vector<vector<int>> ans;
        for(auto i:v)ans.push_back(i);
        return ans;
    }
};