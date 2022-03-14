// https://leetcode.com/problems/range-sum-query-immutable

class NumArray {
public:
    vector<int>s;
    NumArray(vector<int>& nums) {
        s=nums;
        for(int i=1;i<nums.size();i++)s[i]=s[i-1]+nums[i];
    }
    
    int sumRange(int left, int right) {
        if(!left) return s[right];
        return s[right]-s[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */