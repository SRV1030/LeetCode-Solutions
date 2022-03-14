// https://leetcode.com/problems/sum-of-all-subset-xor-totals

class Solution {
public:
    int sum=0;
    void solve(vector<int>& nums,int i,int xr){
        if(i==nums.size()) sum+=xr;
        else {
            solve(nums,i+1,xr^nums[i]);
            solve(nums,i+1,xr);
        }
        
    }
    int subsetXORSum(vector<int>& nums) {
        solve(nums,0,0);
        return sum;
    }
};