// https://leetcode.com/problems/permutations-ii

class Solution {
public:
      vector<vector<int>> v;
    void perm(vector<int> nums,int l,int h){
        if(l==h){
            v.push_back(nums);
            return;
        }
        set<int> s;
        for(int i=l;i<=h;i++){
            if(s.count(nums[i]))
                continue;
            s.insert(nums[i]);
            swap(nums[l],nums[i]);
            perm(nums,l+1,h);
            swap(nums[i],nums[l]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       perm(nums,0,nums.size()-1);
        // vector<vector<int>> ans;
        // for(auto i:v)ans.push_back(i);
        return v;
    }
};