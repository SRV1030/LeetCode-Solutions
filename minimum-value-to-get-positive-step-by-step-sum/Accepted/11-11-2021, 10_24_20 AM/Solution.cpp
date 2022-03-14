// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mn=0,t=0;
        for(auto& i:nums){
            t+=i;
            if(t<mn)mn=t;
        }
        return -mn+1;
    }
};