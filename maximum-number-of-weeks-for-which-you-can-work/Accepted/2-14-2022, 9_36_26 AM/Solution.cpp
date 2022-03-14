// https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work

class Solution {
public:
    long long numberOfWeeks(vector<int>& ms) {
       long long mx=0,ts=0,rs=0;
       for(auto&i:ms) {
           ts+=i;
           if(i>mx)mx=i;
       }
       rs=ts-mx;
       if(rs>=mx-1) return ts;
       return ts-(mx-rs)+1; 
    }
};