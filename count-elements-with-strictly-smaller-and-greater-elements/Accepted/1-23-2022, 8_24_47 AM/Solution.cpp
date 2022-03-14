// https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements

class Solution {
public:
    int countElements(vector<int>& nums) {
        int ans=0;
        int mx=INT_MIN,mn=INT_MAX;
        for(auto num:nums){
            mx=max(mx,num);
            mn=min(mn,num);
        }
        for(auto num:nums){
            if(num>mn&&num<mx)ans++;
        }
        return ans;
    }
};