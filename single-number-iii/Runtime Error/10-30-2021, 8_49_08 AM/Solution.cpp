// https://leetcode.com/problems/single-number-iii

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr=0,n1=0,n2=0;
        for(auto& i:nums)xr^=i;
        int rt_set_bit=xr&~(xr-1);        
        for(auto& i:nums){
            if(i&rt_set_bit)n1^=i;
            else n2^=i;
        }
        return {n1,n2};
    }
};