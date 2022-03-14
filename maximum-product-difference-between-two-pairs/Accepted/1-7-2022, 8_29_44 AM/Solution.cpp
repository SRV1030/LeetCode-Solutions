// https://leetcode.com/problems/maximum-product-difference-between-two-pairs

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int mx1=0,mx2=0,mn1=1e5,mn2=1e5;
        for(auto&i:nums){
            if(i>mx1){
                mx2=mx1;
                mx1=i;
            }
            else if(i>mx2)mx2=i;
            if(i<mn1){
                mn2=mn1;
                mn1=i;
            }                
            else if(i<mn2)mn2=i;
        }
        return (mx1*mx2)-(mn1*mn2);
    }
};