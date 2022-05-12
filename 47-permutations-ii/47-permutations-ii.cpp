class Solution {
public: vector<vector<int>> v;
    void util(vector<int>&nums,int l,int r){
        if(l==r){
            v.push_back(nums);
            return;
        }
        set<int>s;
        for(int i=l;i<=r;i++){
            if(s.count(nums[i])) continue;
            s.insert(nums[i]);
            swap(nums[i],nums[l]);
            util(nums,l+1,r);
            swap(nums[i],nums[l]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        util(nums,0,nums.size()-1);
        return v;
    }
};