// https://leetcode.com/problems/greatest-sum-divisible-by-three

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int>v(3);
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i]+v[0],y=nums[i]+v[1],z=nums[i]+v[2];
            v[x%3]=max(x, v[x%3]); 
            v[y%3]=max(y, v[y%3]); 
            v[z%3]=max(z, v[z%3]); 
        }
        return v[0];
    }
};