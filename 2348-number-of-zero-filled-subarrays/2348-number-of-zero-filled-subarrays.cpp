class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long sm=0,c=0;
        for(auto&i:nums){
            if(i==0)++c;
            else c=0;
            sm+=c;
        }
        return sm;
    }
};