// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int c=0,f=0;
        for(auto&i:nums){
            if(i==1){
                if (f && c<k) return false;
                c=0;
                f=1;
            }else c++;
        }
        return true;
    }
};