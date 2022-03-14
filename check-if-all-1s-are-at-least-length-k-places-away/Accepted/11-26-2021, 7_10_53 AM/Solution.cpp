// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int c=k;
        for(auto&i:nums){
            if(i==1){
                if (c<k) return false;
                c=0;
            }else c++;
        }
        return true;
    }
};