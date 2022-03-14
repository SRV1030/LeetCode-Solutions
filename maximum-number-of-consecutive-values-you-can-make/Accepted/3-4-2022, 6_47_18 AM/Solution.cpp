// https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make

class Solution {
public:
    int c=1;  
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        for(auto&i:coins){
            if(i>c) break;
            c+=i;
        }
        return c;
    }
};