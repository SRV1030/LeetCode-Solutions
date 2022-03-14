// https://leetcode.com/problems/third-maximum-number

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long f=INT_MIN,s=INT_MIN,t=INT_MIN;
        for(auto& i:nums){
            if(i==f || i==s || i==t) continue;
            if(i>f){
                t=s;
                s=f;
                f=i;
            }
            else if(i>s){
                t=s;
                s=i;
            }
            else if(i>t)t=i;
        }
        return t==INT_MIN?f:t;
    }
};